//
// Created by dos DRTT on 4/3/19.
//

#ifndef GUNREDIS_GUN_REDIS_ORIGIN_HH
#define GUNREDIS_GUN_REDIS_ORIGIN_HH


namespace gun_redis {
    template<typename T>
    struct gun_redis_list_origin0 {
        T val;
        gun_redis_list_origin0<T> *next = nullptr;
        gun_redis_list_origin0<T> *prev = nullptr;

    };
}


#endif //GUNREDIS_GUN_REDIS_ORIGIN_HH
