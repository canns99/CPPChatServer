/* 
    time:20220616
    func:Channel 理解为通道，封装了sockfd和其感兴趣的event，如EPOLLIN、EPOLLOUT事件
         还绑定了poller返回的具体事件
 */

#pragma once
#include <functional>
#include <memory>

#include "nocopyable.h"
#include "TimeStamp.h"

//class 声明
class EventLoop;

class Channel : nocopyable{
public:
    //事件回调 
    using EventCallback = std::function<void()>;
    //只读事件的回调
    using ReadEventCallback = std::function<void(TimeStamp)>;

    Channel(EventLoop *loop,int fd);
    ~Channel();

    //fd得到poller通知以后，处理事件的
    //调用相应的回调方法来处理事件
    void handleEvent(TimeStamp receiveTime);

    //设置回调函数对象
    void setReadCallback(ReadEventCallback cb){
        readCallback_ =std::move(cb);
    }
    void setWriteCallback(EventCallback cb){
        writeCallback_ =std::move(cb);
    }
    void setCloseCallback(EventCallback cb){
        closeCallback_ =std::move(cb);
    }
    void setErrorCallback(EventCallback cb){
        errorCallback_ =std::move(cb);
    }

    //防止当channel被手动remove掉，channel还在执行回调操作，就是上面这些回调操作
    void tie(const std::shared_ptr<void>&);


    //事件
    int fd() const{
        return fd_;
    }
    int events() const {
        return events_;
    }
    int set_revents(int revt){
        revents_ = revt;
    }

    //设置fd相应的事件状态，要让fd对这个事件感兴趣 
    //update就是调用epoll_ctrl，通知poller把fd感兴趣的事件添加到fd上
    void enableReading(){
        events_ != kReadEvent;
        update();
    }
    void disableReading(){
        events_ &= ~kReadEvent;
        update();
    }
    void enableWriting(){
        events_ != kWriteEvent;
        update();
    }
    void disableWriting(){
        events_ != kWriteEvent;
        update();
    }
    void disableAll(){
        events_ = kNoneEvent;
        update();
    }

    //返回fd当前的事件状态
    bool isNoneEvent()const{
        return events_== kNoneEvent;
    };
    bool isWriteEvent()const{
        return events_== kWriteEvent;
    };
    bool isReadEvent()const{
        return events_== kReadEvent;
    };

    //index
    int index(){
        return index_;
    }
    void setIndex(int index){
        index_=index;
    }

    //one loop per thread
    EventLoop* ownerLoop(){
        return loop_;
    }
    void remove();

private:
    /* 成员函数 */
    //更新，内部对象调用
    void update();
    //受保护的处理事件
    void handleEventWithGuard(TimeStamp receiveTime);

    //回调成员
    ReadEventCallback readCallback_;
    EventCallback writeCallback_;
    EventCallback closeCallback_;
    EventCallback errorCallback_;

    //事件
    EventLoop *loop_;
    const int fd_;//fd, Poller监听的对象
    int events_;//注册fd感兴趣的事件
    int revents_;//poller返回的具体发生的事件
    int index_;

    //tie
    std::weak_ptr<void> tie_;
    bool tied_;

    //表示当前fd和其状态，是没有对任何事件感兴趣，还是对读或者写感兴趣
    static const int kNoneEvent;//都不感兴趣
    static const int kReadEvent;
    static const int kWriteEvent;
    

}；