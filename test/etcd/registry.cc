#include "bite_scaffold/etcd.h"
#include "bite_scaffold/log.h"
#include <iostream>

int main()
{
    bitelog::bitelog_init();
    //进行服务注册
    const std::string url = "http://192.168.65.128:2379";
    const std::string svc_name = "user";
    const std::string svc_addr = "192.168.65.128:9000";
    // 1. 实例化服务提供者对象
    bitesvc::SvcProvider provider(url, svc_name, svc_addr);
    // 2. 注册服务即可
    provider.registry();
    getchar();
    return 0;
}