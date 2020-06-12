# CMake 最低版本号要求

cmake_minimum_required (VERSION 2.8)

# 项目信息

project (client)

# 指定生成目标

add_executable(client client_main.cpp)

target_link_libraries(client readline)
