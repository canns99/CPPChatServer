#include "EPollPoller.h"
#include "logger.h"
#include "channel.h"

#include <errno.h>
#include <unistd.h>
#include <string.h>

//标识channel和epoll的状态 
//channel未添加到poller中
const int kNew=-1;
//channel已添加到poller中
const int kAdded=1;
const int kDeleted=2;

EPollPoller::EPollPoller(EventLoop* loop):
            Poller(loop),epollfd_(::epoll_create1(EPOLL_CLOEXEC)),
            events_(kInitEventListSize){
    if(epollfd_<0){
        LOG_FATAL("epoll_create error:%d\n",errno);
    }
}

EPollPoller::~EPollPoller(){
    ::close(epollfd_);
}

//epoll_wait 
//eventloop会创建一个channellist，并把创建好的channellist的地址传给poll
//poll通过epoll_wait监听到哪些fd发生了事件，把真真正正发生事件的channel通过形参发送到eventloop提供的实参里面 
TimeStamp EPollPoller::poll(int timeoutMs, ChannelLists *activeChannels){
    //实际上应该用LOG_DEBUG输出日志更为合理，可以设置开启或者不开启 
    LOG_INFO("func=%s => fd total count:%lu \n",__FUNCTION__,channels_.size());
    
}