//
// Created by dos DRTT on 4/3/19.
//

#ifndef GUNREDIS_GUN_REDIS_LIST_BASE_HH
#define GUNREDIS_GUN_REDIS_LIST_BASE_HH


#include "gun_redis_collection.hh"

template<typename T>
class gun_redis_list_base : gun_redis_collection {


    virtual void add(T val) = 0;


    virtual T get(int index) = 0;
};


#endif //GUNREDIS_GUN_REDIS_LIST_BASE_HH
