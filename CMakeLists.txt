cmake_minimum_required(VERSION 3.8)
project(GunRedis)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/main.cpp src/datas_node/GunString.cpp src/datas_node/GunString.hpp src/Boot.cpp src/Boot.hpp)
add_executable(GunRedis ${SOURCE_FILES})