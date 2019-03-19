#include <iostream>
#include "Boot.hpp"





int main(int argc, char *argv[]) {
    gun_std::Server *realserver = new gun_std::GunRedisServer();
    realserver->init();
    return 0;
}

