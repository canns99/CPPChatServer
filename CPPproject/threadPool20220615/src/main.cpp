// #include "test.cpp"
#include <ctime>
#include <iostream>

extern void test_no_1000();
extern void test_yes_1000();
extern void test_no_1000_mt();
extern void test_yes_1000_mt();

int main(){
    clock_t begin=clock();
    /* *************单例******* */
    // Connection conn;
    // char sql[1024]={0};
    // sprintf(sql, "insert into user(name, password, state) values('%s', '%s', '%s')",
    //         "wangwu", "123456","offline");


    // test_no_1000();
    // test_yes_1000();


    //muilt_thread
    test_no_1000_mt();
    // test_yes_1000_mt();


    clock_t end = clock();
    std::cout<<"4线程的连接池测试 test: yes pool, test 10000\n";
    std::cout<<"use time:"<<(end-begin)<<"ms\n";
    return 0;
}