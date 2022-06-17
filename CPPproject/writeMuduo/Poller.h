/* 
    time:20220616
    func:poll和epoll抽象类接口
 */

#pragma once

#include "nocopyable.h"
#include "TimeStamp.h"

#include <vector>
#include <unordered_map>

class Channel;
class EventLoop;

class Poller : nocopyable{
public:
    using ChannelLists=std::vector<Channel*>;

    Poller(EventLoop* loop);
    virtual ~Poller()=default;

    /* 给所有IO复用保留统一的接口 */
    ///相当于启动了epoll_wait 
    virtual TimeStamp poll(int timeoutMs,ChannelLists* activeChannels)=0;
    //相当于启动了epoll_ctrl
    virtual void updateChannel(Channel* channel)=0;
    //fd所感兴趣的事件delete掉 
    virtual void removeChannel(Channel* channel)=0;

    //判断参数channel是否在当前Poller当中
    bool hasChannel(Channel* channel)const;

    //EventLoop可以通过该接口获取默认的IO复用的具体实现 
    static Poller* newDefaultPoller(EventLoop* loop);

protected:
    //map的key：sockfd  
    //value：sockfd所属的channel通道类型
    using ChannelMap = std::unordered_map<int,Channel*>;
    ChannelMap channels_;

private:
    //定义Poller所属的事件循环EventLoop
    EventLoop* ownerLoop_;

};