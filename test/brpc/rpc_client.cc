#include "bite_scaffold/rpc.h"
#include "bite_scaffold/log.h"
#include "cal.pb.h"

int main()
{
    // 进来后，先初始化日志系统
    bitelog::bitelog_init();
    // 0. 实例化服务节点管理对象
    biterpc::SvcChannels scs;
    // 1.手动添加服务端需要管理的服务名称
    scs.setWatch("user");
    // 2.  模拟服务发现，手动添加服务节点
    scs.addNode("user", "192.168.65.128:9000");
    // 2. 获取节点对应的channel
    auto channel = scs.getNode("user");
    if (!channel) {
        ERR("没有可供调用的服务！");
        return -1;
    }
    // 3. 发起rpc请求：实例化stub对象，new出req，rsp，异步回调对象
    brpc::Controller* cntl = new brpc::Controller;
    cal::AddReq *request = new cal::AddReq;
    request->set_num1(22);
    request->set_num2(333);
    cal::AddRsp *response = new cal::AddRsp;
    auto closure = biterpc::ClosureFactory::create([=](){
        std::unique_ptr<brpc::Controller> cntl_guard(cntl);
        std::unique_ptr<cal::AddReq> req_guard(request);
        std::unique_ptr<cal::AddRsp> rsp_guard(response);
        if (cntl_guard->Failed() == true) {
            std::cout << "rpc请求失败: " << cntl_guard->ErrorText() << std::endl;
            return ;
        }
        std::cout << rsp_guard->result() << std::endl;
    });
    cal::CalService_Stub stub(channel.get());
    stub.Add(cntl, request, response, closure);
    std::cout << "===================================\n";
    getchar();
    return 0;
}