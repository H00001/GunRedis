//
// Created by dos DRTT on 4/1/19.
//

#ifndef GUNREDIS_GUN_REDIS_COMPAREABLE_HH
#define GUNREDIS_GUN_REDIS_COMPAREABLE_HH
namespace gun_redis {

    class gun_redis_compareable {

        virtual int compare(gun_redis_compareable &comp) = 0;

    protected:
        explicit gun_redis_compareable() = default;
    };

};

#endif //GUNREDIS_GUN_REDIS_COMPAREABLE_HH
