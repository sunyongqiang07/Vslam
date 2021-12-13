# 声明要求的 cmake 最低版本
cmake_minimum_required(VERSION 2.8)

# 声明一个cmake 工程
project(thin)

##matplotlibcpp
include_directories("/home/qingwa/my_Lib/matplotlib-cpp/") #路径需要根据自己路径做调整


# 设置编译模式
set(CMAKE_BUILD_TYPE "Debug")

add_compile_options(-std=c++11)
##python
find_package(PythonLibs 2.7)
include_directories(${PYTHON_INCLUDE_DIRS})  #使用这方式可以替代下面这行


# 添加一个可执行程序
add_executable(main main.cpp)
add_library(hello map.cpp)
target_link_libraries(main hello)
target_link_libraries(main ${PYTHON_LIBRARIES})
#
