cmake_minimum_required(VERSION 3.8)
project(GunRedis)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/main.cpp src/datas_node/gun_redis_string_object.cpp src/datas_node/gun_redis_string_origin.cc src/datas_node/gun_redis_collection.cc src/datas_node/gun_redis_compareable.cc src/datas_node/gun_redis_compareable.hh)
add_executable(GunRedis ${SOURCE_FILES})