# 1. 声明cmake所需版本
cmake_minimum_required(VERSION 3.1.3)

# 2. 设置工程项目名称（内部会生成一系列的内置变量）
project(main VERSION 1.0)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++17")

# 3. 执行指令，针对odb映射结构生成代码到 ${CMAKE_CURRENT_BIRNARY_DIR} 目录下
file(GLOB_RECURSE odb_files ${CMAKE_CURRENT_SOURCE_DIR}/*.hxx)
execute_process(
    COMMAND odb -d mysql --std c++17 --generate-query --generate-schema --profile boost/date-time ${odb_files}
)
# 4. 获取生成的odb代码文件,用于参与联合编译
file(GLOB_RECURSE odb_src_files ${CMAKE_CURRENT_SOURCE_DIR}/*.cxx)
# 5. 因为在临时目录下也会生成相应的头文件，因此也需要设置一下头文件检索路径
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# 6. 添加生成目标（可执行程序）
file(GLOB_RECURSE src_files ${CMAKE_CURRENT_SOURCE_DIR}/*.cc)
add_executable(${PROJECT_NAME} ${src_files} ${odb_src_files})

# 7. 依赖检查（依赖库的查找以及链接选项的添加）
find_package(bite_scaffold REQUIRED)

# 8. 设置链接库
target_link_libraries(${PROJECT_NAME} PRIVATE bite_scaffold::bite_scaffold)
