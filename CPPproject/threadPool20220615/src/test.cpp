/* 2.第一组（1000）测试
    （模拟1000个人访问数据库）
    （1）不使用连接池 
*/

#include "Connection.h"
#include "ConnectionPool.h"
#include <iostream>
#include <thread>
using namespace std;

void test_no_1000(){

    clock_t begin=clock();
    const static int num=1000;

    for(int i=0;i<num;i++){
        Connection conn;
        char sql[1024]={0};
        sprintf(sql, "insert into user3(name, age, sex) values('%s', %d, '%s')",
            "wangwu", 20,"male");

        conn.connect("127.0.0.1",3306,"root", "123456", "chat");
        conn.update(sql);
    }

    clock_t end = clock();
    cout<<"threadPool test: no pool, test 1000\n";
    cout<<"use time:"<<(end-begin)<<"ms\n";
}

void test_yes_1000(){
    clock_t begin=clock();
    const static int num=10000;

    ConnectionPool *cp = ConnectionPool::getConnectionPool();
    for(int i=0;i<num;i++){
        shared_ptr<Connection> sp=cp->getConnection();
        char sql[1024]={0};
        sprintf(sql, "insert into user3(name, age, sex) values('%s', %d, '%s')",
            "wangwu", 20,"male");

        sp->update(sql);
    }

    clock_t end = clock();
    cout<<"threadPool test: yes pool, test 10000\n";

    cout<<"use time:"<<(end-begin)<<"ms\n";
}

void test_yes_1000_mt(){
  
    const static int num=2500;

    thread t1([](){
        ConnectionPool *cp = ConnectionPool::getConnectionPool();
    for(int i=0;i<num;i++){
        shared_ptr<Connection> sp=cp->getConnection();
        char sql[1024]={0};
        sprintf(sql, "insert into user3(name, age, sex) values('%s', %d, '%s')",
            "wangwu", 20,"male");

        sp->update(sql);
    }
    });

    thread t2([](){
        ConnectionPool *cp = ConnectionPool::getConnectionPool();
    for(int i=0;i<num;i++){
        shared_ptr<Connection> sp=cp->getConnection();
        char sql[1024]={0};
        sprintf(sql, "insert into user3(name, age, sex) values('%s', %d, '%s')",
            "wangwu", 20,"male");

        sp->update(sql);
    }
    });

        thread t3([](){
        ConnectionPool *cp = ConnectionPool::getConnectionPool();
    for(int i=0;i<num;i++){
        shared_ptr<Connection> sp=cp->getConnection();
        char sql[1024]={0};
        sprintf(sql, "insert into user3(name, age, sex) values('%s', %d, '%s')",
            "wangwu", 20,"male");

        sp->update(sql);
    }
    });

        thread t4([](){
        ConnectionPool *cp = ConnectionPool::getConnectionPool();
    for(int i=0;i<num;i++){
        shared_ptr<Connection> sp=cp->getConnection();
        char sql[1024]={0};
        sprintf(sql, "insert into user3(name, age, sex) values('%s', %d, '%s')",
            "wangwu", 20,"male");

        sp->update(sql);
    }
    });

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    
}


void test_no_1000_mt(){
    const static int num=2500;

    thread t1([](){
        for(int i=0;i<num;i++){
        Connection conn;
        char sql[1024]={0};
        sprintf(sql, "insert into user3(name, age, sex) values('%s', %d, '%s')",
            "wangwu", 20,"male");

        conn.connect("127.0.0.1",3306,"root", "123456", "chat");
        conn.update(sql);
    }
    });

    thread t2([](){
        for(int i=0;i<num;i++){
        Connection conn;
        char sql[1024]={0};
        sprintf(sql, "insert into user3(name, age, sex) values('%s', %d, '%s')",
            "wangwu", 20,"male");

        conn.connect("127.0.0.1",3306,"root", "123456", "chat");
        conn.update(sql);
    }
    });

    thread t3([](){
        for(int i=0;i<num;i++){
        Connection conn;
        char sql[1024]={0};
        sprintf(sql, "insert into user3(name, age, sex) values('%s', %d, '%s')",
            "wangwu", 20,"male");

        conn.connect("127.0.0.1",3306,"root", "123456", "chat");
        conn.update(sql);
    }
    });

    thread t4([](){
        for(int i=0;i<num;i++){
        Connection conn;
        char sql[1024]={0};
        sprintf(sql, "insert into user3(name, age, sex) values('%s', %d, '%s')",
            "wangwu", 20,"male");

        conn.connect("127.0.0.1",3306,"root", "123456", "chat");
        conn.update(sql);
    }
    });

    t1.join();
    t2.join();
    t3.join();
    t4.join();

}