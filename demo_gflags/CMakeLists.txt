cmake_minimum_required(VERSION 2.8.12)
project(gflags_demo)

add_subdirectory(gflags)                   # 添加子目录

add_executable(main main.cc)               # 生成目标文件 main
target_link_libraries(main gflags::gflags) # 链接到 gflags库
