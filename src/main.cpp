#include <iostream>
#include "Boot.hpp"





int main(int argc, char *argv[]) {
    gun_std::Server *realserver = new gun_std::GunRedisServer();
    gun_std::Server *realserver1 = new gun_std::GunRedisServer();
    (*realserver)+realserver1;
    realserver->init();
    return 0;
}

