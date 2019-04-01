//
// Created by dos DRTT on 4/1/19.
//

#ifndef GUNREDIS_GUN_REDIS_COLLECTION_HH
#define GUNREDIS_GUN_REDIS_COLLECTION_HH


class gun_redis_collection {
public:
    virtual int get_length() = 0;

    virtual void clear() = 0;
};


#endif //GUNREDIS_GUN_REDIS_COLLECTION_HH
