cmake_minimum_required(VERSION 2.8.12)
project(gflags_demo)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_C_FLAGS       "${CMAKE_C_FLAGS} -g -w -O3 -DNDEBUG -std=c++11")
set(CMAKE_CXX_FLAGS     "${CMAKE_CXX_FLAGS} -g -w -O3 -DNDEBUG -std=c++11")
add_subdirectory(gflags)                   # 添加子目录

add_executable(main main.cc)               # 生成目标文件 main
target_link_libraries(main gflags::gflags) # 链接到 gflags库

# message(${PROJECT_SOURCE_DIR})
# message(${PROJECT_BINARY_DIR})
# message(${CMAKE_CURRENT_SOURCE_DIR})
# message(${CMAKE_CURRENT_BINARY_DIR})
# message(${EXECUTABLE_OUTPUT_PATH})
# message(${LIBRARY_OUTPUT_PATH})
# message(${PROJECT_NAME})
# message(${CMAKE_BINARY_DIR})
