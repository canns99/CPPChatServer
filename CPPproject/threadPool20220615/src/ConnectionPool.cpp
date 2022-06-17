#include "pch.h"
#include "ConnectionPool.h"
#include "public.h"

//线程安全的懒汉单例函数接口
ConnectionPool* ConnectionPool::getConnectionPool(){
	static ConnectionPool pool;
	return &pool;
}

//从配置文件中加载配置项
bool ConnectionPool::loadConfigFile()
{
	FILE *pf = fopen("mysql.ini", "r");
	if (pf == nullptr)
	{
		LOG("mysql.ini file is not exist!");
		return false;
	}

	while (!feof(pf))//文件没有到末尾 
	{
		char line[1024] = { 0 };
		fgets(line, 1024, pf);
		string str = line;
		int idx = str.find('=', 0);
		if (idx == -1)//无效的配置项
		{
			continue;
		}

		//password=123456\n
		int endidx = str.find('\n', idx);
		string key = str.substr(0, idx);
		string value = str.substr(idx + 1, endidx - idx - 1);

		if (key == "ip")
		{
			_ip = value;
		}
		else if (key == "port")
		{
			_port = atoi(value.c_str());
		}
		else if (key == "username")
		{
			_username = value;
		}
		else if (key == "password")
		{
			_password = value;
		}
		else if (key == "dbname")
		{
			_dbname = value;
		}
		else if (key == "initSize")
		{
			_initSize = atoi(value.c_str());
		}
		else if (key == "maxSize")
		{
			_maxSize = atoi(value.c_str());
		}
		else if (key == "maxIdleTime")
		{
			_maxIdleTime = atoi(value.c_str());
		}
		else if (key == "connectionTimeOut")
		{
			_connectionTimeout = atoi(value.c_str());
		}
	}
	return true;
}

ConnectionPool::ConnectionPool(){
	if(!loadConfigFile){
		return;
	}

	//initSize
	for(int i=0;i<_initSize;i++){
		Connection* p=new Connection();
		p->connect(_ip,_port,_password,_dbname);
		p->refreshAliveTime();
		_QConnection.push(p);
		_connectionCnt++;
	}

	//启动一个新的线程，作为连接的生产者 linux thread => pthread_create
	thread produce(std::bind(&ConnectionPool::produceConnectionTask,this));
	produce.detach();

	//启动一个新的定时线程，扫描超过maxIdleTime时间的空闲连接，进行对于的连接回收
	thread scanner(std::bind(&ConnectionPool::scannerIdleConnTask,this));
	scanner.detach();
}

void ConnectionPool::produceConnectionTask(){
	for(;;){
		unique_lock<mutex> lock(_QMutex);
		while(!_QConnection.empty()){
			cv.wait(lock);//队列不空，此处生产线程进入等待状态
		}

		//连接数量没有到达上限，继续创建新的连接
		if(_connectionCnt < _maxSize){
			Connection *p = new Connection();
			p->connect(_ip, _port, _username, _password, _dbname);
			p->refreshAliveTime();//刷新一下开始空闲的起始时间
			_QConnection.push(p);
			_connectionCnt++;

		}

		//通知消费者线程，可以消费连接了
		cv.notify_all();
	}
}

//给外部提供接口，从连接池中获取一个可用的空闲连接
shared_ptr<Connection> ConnectionPool::getConnection(){
	unique_lock<mutex> lock(_QMutex);
	while(_QConnection.empty()){
		if(cv_status::timeout == cv.wait_for(lock, chrono::milliseconds(_connectionTimeout))){
			if(_QConnection.empty()){
				LOG("获取空闲连接超时了...获取连接失败!");
					return nullptr;
			}
		}
	}//while

	/*
	shared_ptr智能指针析构时，会把connection资源直接delete掉，相当于
	调用connection的析构函数，connection就被close掉了。
	这里需要自定义shared_ptr的释放资源的方式，把connection直接归还到queue当中
	*/

	shared_ptr<Connection> sp(_QConnection.front(),[&](Connection *pcon){
		unique_lock<mutex> lock(_QMutex);
		pcon->refreshAliveTime();
		_QConnection.push(pcon);
	});

	_QConnection.pop();
	//消费完连接以后，通知生产者线程检查一下，如果队列为空了，赶紧生产连接
	cv.notify_all();

	return sp;
}

//扫描超过maxIdleTime时间的空闲连接，进行对于的连接回收
void ConnectionPool::scannerIdleConnTask(){
	for(;;){
		//通过sleep模拟定时效果
		this_thread::sleep_for(chrono::seconds(_maxIdleTime));

		unique_lock<mutex> lock(_QMutex);
		while(_connectionCnt > _initSize){
			//队头的时间没超过，那后面的时间就都没超过 
			Connection *p=_QConnection.front();
			if(p->getAliveeTime() >= _maxIdleTime*1000){
				_QConnection.pop();
				_connectionCnt--;
				delete p;
			}
			else{
				//队头的连接没有超过_maxIdleTime，其它连接肯定没有
				break;
			}
		}
	}
}