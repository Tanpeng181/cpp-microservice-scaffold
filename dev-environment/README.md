# Docker 开发环境

本目录保存开发环境的 Docker Compose 文件及其引用的 MySQL、Redis、RabbitMQ、Elasticsearch、Kibana 配置，包含 Elasticsearch IK 插件。

将两个代码仓库放在同一个父目录下：

```text
workspace/
├── cpp-microservice-scaffold/
│   └── dev-environment/
│       └── docker-compose.yml
└── cpp-microservice-videoplayer/
```

启动开发环境：

```bash
cd cpp-microservice-scaffold/dev-environment
docker compose config --quiet
docker compose up -d
```

Compose 将两个仓库所在的父目录挂载到开发容器的 `/home/dev/workspace`。镜像地址、服务端口及开发用配置沿用现有环境，原工作目录中的文件不受影响。

视频项目的业务服务 Compose 文件位于另一个仓库的 `server/docker-compose.yml`。本目录只负责开发环境及基础依赖，业务服务的编译和运行配置请参照视频项目代码。

性能测试目录、测试报告和本机编译输出不包含在本次提交中。
