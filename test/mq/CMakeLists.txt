# 1. 声明cmake所需版本
cmake_minimum_required(VERSION 3.1.3)

# 2. 设置工程项目名称（内部会生成一系列的内置变量）
project(simple_publish VERSION 1.0)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++17")

# 3. 添加生成目标（可执行程序）
set(simple_publish_target "simple_publish")
add_executable(${simple_publish_target} ${CMAKE_CURRENT_SOURCE_DIR}/simple_publish.cc)
set(simple_subscribe_target "simple_subscribe")
add_executable(${simple_subscribe_target} ${CMAKE_CURRENT_SOURCE_DIR}/simple_subscribe.cc)
set(delayed_publish_target "delayed_publish")
add_executable(${delayed_publish_target} ${CMAKE_CURRENT_SOURCE_DIR}/delayed_publish.cc)
set(delayed_subscribe_target "delayed_subscribe")
add_executable(${delayed_subscribe_target} ${CMAKE_CURRENT_SOURCE_DIR}/delayed_subscribe.cc)

# 4. 依赖检查（依赖库的查找以及链接选项的添加）
find_package(bite_scaffold REQUIRED)

# 5. 设置链接库
target_link_libraries(${simple_publish_target} PRIVATE bite_scaffold::bite_scaffold)
target_link_libraries(${simple_subscribe_target} PRIVATE bite_scaffold::bite_scaffold)
target_link_libraries(${delayed_publish_target} PRIVATE bite_scaffold::bite_scaffold)
target_link_libraries(${delayed_subscribe_target} PRIVATE bite_scaffold::bite_scaffold)
