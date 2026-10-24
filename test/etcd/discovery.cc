#include "bite_scaffold/etcd.h"
#include "bite_scaffold/log.h"
#include <iostream>

void online(const std::string &svc_name, const std::string &svc_addr) {
    INF("新服务 {} 上线节点: {}", svc_name, svc_addr);
}
void offline(const std::string &svc_name, const std::string &svc_addr) {
    INF("新服务 {} 下线节点: {}", svc_name, svc_addr);
}

int main()
{
    bitelog::bitelog_init();
    //进行服务注册
    const std::string url = "http://192.168.65.128:2379";
    // 1. 实例化服务监控者对象
    bitesvc::SvcWatcher watcher(url, online, offline);
    // 2. 发现服务即可
    watcher.watch();
    getchar();
    return 0;
}