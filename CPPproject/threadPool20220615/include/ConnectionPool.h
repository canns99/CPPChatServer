/* 
    time:20220615
    func:mysql连接池代码实现
 */


#pragma once
#include <string>
#include <queue>
#include <mutex>
#include <iostream>
#include <atomic>
#include <thread>
#include <condition_variable>
#include <memory>
#include <functional>
using namespace std;
#include "Connection.h"


#define MENU_NUM 10
/*
实现连接池功能模块
*/
class ConnectionPool
{
public:
	//获取连接池对象实例
	static ConnectionPool* getConnectionPool();
	//给外部提供接口，从连接池中获取一个可用的空闲连接
	shared_ptr<Connection> getConnection();//智能指针自动管理连接的释放 
private:
	//单例#1 构造函数私有化
	ConnectionPool();

	//从配置文件中加载配置项
	bool loadConfigFile(); 

	//运行在独立的线程中，专门负责生产新连接
	void produceConnectionTask();

	//扫描超过maxIdleTime时间的空闲连接，进行对于的连接回收
	void scannerIdleConnTask();

	string _ip;
	unsigned short _port;
	string _username;
	string _password;
	string _dbname;

	int _initSize;
	int _maxSize;
	int _minSize;
	int _maxIdleTime;
	int _connectionTimeout;

	// typedef enum{_IP,_PORT,_USERNAME,_PASSWORD,_DBNAME,
	// 			_INITSEIZE,_MAXSIZE,_MINSIZE,
	// 			_MAXIDLETIME,_CONNTIMEOUT
	// 			}Menu;
	// int menu(Menu type);

	queue<Connection*> _QConnection;//存储mysql链接的队列
	mutex _QMutex;	//队列互斥锁
	atomic_int _connectionCnt;//记录连接所创建的connection连接的总数量 
	condition_variable cv;//设置条件变量，用于连接生产线程和连接消费线程的通信

};
