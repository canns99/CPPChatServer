/* 
    time:20220616
    func:
        epoll的使用  
        epoll_create  创建fd
        epoll_ctl     进行add/mod/del
        epoll_wait
 */

#pragma once

#include "Poller.h"
#include "TimeStamp.h"

#include <vector>
#include <sys/epoll.h>

class Channel;

class EPollPoller:public Poller{
public:
    EPollPoller(EventLoop* loop);
    ~EPollPoller() override;

    //重写基类Poller的抽象方法
    TimeStamp poll(int timeoutMs, ChannelLists* activeChannels)override;
    void updateChannel(Channel* channel)override;
    void removeChannel(Channel* channel)override;

private:
    //初始化vector长度
    static const int kInitEventListSize=16;

    //填写活跃的连接
    void fillActiveChannels(int numEvents,ChannelLists* activeChannels)const;
    //更新channel通道
    void update(int operation, Channel* channel);

    //存储epoll事件
    using EventList = std::vector<epoll_event>;

    int epollfd_;
    EventList events_;
};