#pragma once
#include "mprpcconfig.h"
/* 
    time:20220614
    func:mprpc框架的基础类，负责框架的一些初始化操作
*/
class MprpcApplication{
public:
    static void Init(int argc,char **argv);
    static MprpcApplication& GetInstance();
    static MprpcConfig& GetConfig();
    

private:
    MprpcApplication(){};
    MprpcApplication(const MprpcApplication&)=delete; //禁用拷贝构造
    MprpcApplication(MprpcApplication&&)=delete;    //移动构造

    static MprpcConfig m_config;
};