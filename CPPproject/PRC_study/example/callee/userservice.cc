#include <iostream>
#include <string>
#include "user.pb.h"
#include "mprpcapplication.h"
#include "mprpcprovider.h"
/* 
    time:20220614
    func:UserService原来是一个本地服务，提供两个方法，login,GetFriendLists 
*/
class UserService:public fixbug::UserServiceRpc{
public:
    bool Login(std::string name, std::string pwd){
        std::cout<<"doing local service:Login\n";
        std::cout<<"name:"<<name<<" pwd:"<<pwd<<"\n";
        return false;
    }

    bool Register(uint32_t id,std::string name,std::string pwd){
        std::cout << "doing local service: Register" << std::endl;
        std::cout << "id:" << id << "name:" << name << " pwd:" << pwd << std::endl;
        return true;

    }

    /*
        我的角色是服务的提供者，你作为远端想发起一个调用我这个机器上的UserService的Login方法
        首先你会发一个RPC请求，这个请求是先到RPC框架，RPC框架根据你发过来的请求，然后根据参数和标识
        匹配到我的Login方法，然后它就把这个网络上发的请求上报来，我接收到这个请求后，从请求中拿取数据，
        然后做本地业务，填写相应的响应，然后再执行一个回调，相当于把执行完的这个RPC方法的返回值再塞给框架
        ，然后框架再进行序列化，通过网络传送回去，发送给你。体现在Login的四个参数。
	*/

	/*
    重写基类UserServiceRpc的虚函数 下面这些方法都是框架直接调用的
    1. caller RPC调用者   ===>   Login(LoginRequest)打包  => muduo库 =>   callee端
    2. callee RPC提供者   ===>   根据接收到的Login(LoginRequest)  => 交到下面重写的这个Login方法上了
    */
   void Login(::google::protobuf::RpcController* controller,
                       const ::fixbug::LoginRequest* request,
                       ::fixbug::LoginResponse* response,
                       ::google::protobuf::Closure* done){
        //框架给业务上报了请求参数LoginRequest，应用程序获取相应数据做本地业务（登录的本地业务）
        std::string name = request->name();
        std::string pwd=request->pwd();
        //这个就是使用protobuf的好处，protobuf直接把字节流反序列化成我们可以
        //识别的LoginRequest对象，通过他生成的方法获取姓名和密码。
		

        /* 
            做本地业务
        */
       bool login_result = Login(name,pwd);

        //框架只是创建一个LoginResponse，我们只需要把响应写入，包括错误码、错误消息、返回值
       fixbug::ResultCode *code=response->mutable_result();
       code->set_errcode(0);
       code->set_errmsg("");
       response->set_sucess(login_result);

       //执行回调操作，执行响应对象数据的序列化和网络发送（都是由框架来完成的）
		//Closure是一个抽象类，重写Run,让它去做一些事情
        done->Run();
    }
};


int main(int argc, char **argv)//需要配置文件
{
    //调用框架的初始化操作
    MprpcApplication::Init(argc, argv);//整个框架的初始化操作，日志，配置等等。

    //provider是一个rpc网络的服务对象。把UserService对象发布到rpc节点上。
    RpcProvider provider;
    // provider.NotifyService(new UserService());//发布服务
	//可以调用多次，生成多个远程RPC服务

    //启动一个rpc服务发布节点
    provider.Run();
	//Run以后，进程进入阻塞状态，等待远程的rpc调用请求

    return 0;
}



