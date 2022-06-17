/* 
    time:20221616
    func:时间戳
 */

#pragma once
#include <iostream>
#include <string>

class TimeStamp{
public:
    TimeStamp();
    //带参数的构造，带参数的构造函数都加了explicit关键字：避免隐式对象转换
    explicit TimeStamp(int64_t microSecondsSinceEpoch);
    //获取当前时间,static
    static TimeStamp now();
    //获取当前时间的年月日时分秒的输出
    std::string timeToString() const;

private:
    int64_t microSecondsSinceEpoch_;
};