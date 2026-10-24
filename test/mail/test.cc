#include <memory>
#include "bite_scaffold/mail.h"
#include "bite_scaffold/log.h"


int main()
{
    bitelog::bitelog_init();
    // 1. 构造邮件服务配置
    bitecode::mail_settings settings = {
        .username = "JzSan521@163.com",
        .password = "UBTtCJ76iezXC9ws",
        .url = "smtps://smtp.163.com:465",
        .from = "JzSan521@163.com",
    };
    // 2. 实例化邮件客户端对象
    auto mail = std::make_unique<bitecode::MailClient>(settings);
    // 3. 发送邮件
    bool ret = mail->send("270988047@qq.com", "6789");
    if (!ret) {
        std::cout << "发送邮件失败！" << std::endl;
    }
    return 0;
}