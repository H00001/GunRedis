#include <iostream>
#include "datas_node/gun_redis_string_object.hpp"

using namespace top_gun_plan;

int main(int argc, char *argv[]) {
    gun_redis_string_object kppk("hh");
    std::cout << kppk.get_string();
    return 0;
}
