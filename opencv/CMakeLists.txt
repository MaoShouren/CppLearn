cmake_minimum_required(VERSION 3.0)
project(test)

# 寻找 OpenCV 库
find_package(OpenCV REQUIRED)

# 设置包含路径
include_directories(${OpenCV_INCLUDE_DIRS})

# 添加可执行文件
add_executable(main filestorage.cc)

# 链接 OpenCV 库
target_link_libraries(main ${OpenCV_LIBS})
