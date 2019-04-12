#include <iostream>
#include "datas_node/gun_redis_list.hh"


int main(int argc, char *argv[]) {

   gun_redis:: gun_redis_list<int> ls;
    ls.add(1);
    ls.add(2);

    ls.add(3);

    std::cout << ls.get(1) << std::endl;
    std::cout << ls.get(0) << std::endl;

    return 0;
}
