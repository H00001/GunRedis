//
// Created by dos DRTT on 4/1/19.
//

#ifndef GUNREDIS_GUN_REDIS_STRING_OBJECT_HPP
#define GUNREDIS_GUN_REDIS_STRING_OBJECT_HPP

#include <ostream>
#include "gun_redis_string_origin.hh"
#include "gun_redis_collection.hh"
#include "gun_redis_compareable.hh"
#include "gun_hash.hh"

/**
 *  this is a dynamic string int gun redis
 */

namespace gun_redis {
    class gun_redis_string_object : public gun_redis_collection, public gun_redis_compareable, public gun_hash {
    private:
        string_origin *origin = nullptr;
        long hash = 0;
    public:
        explicit gun_redis_string_object() = default;

        gun_redis_string_object(gun_redis_string_object &obj);

        gun_redis_string_object &operator=(gun_redis_string_object &obj);

        explicit gun_redis_string_object(const char *str);

        int get_length() override;

        bool operator==(gun_redis_string_object &object);

        void clear() override;

        int compare(gun_redis_compareable &comp) override;

        const char *get_string();

        const char *operator<<(int val);


        void catstring(const char *val);

        void substring(int sta, int end);

        void replace(const char *old, const char *news);

        int get_hash() override ;


        //  std::ostream &operator<<(std::ostream &out,gun_redis_string_object& obj);

        //void operator<<(int size);

        ~gun_redis_string_object();

    };
}


#endif //GUNREDIS_GUN_REDIS_STRING_OBJECT_HPP
