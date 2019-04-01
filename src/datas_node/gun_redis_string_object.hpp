//
// Created by dos DRTT on 4/1/19.
//

#ifndef GUNREDIS_GUN_REDIS_STRING_OBJECT_HPP
#define GUNREDIS_GUN_REDIS_STRING_OBJECT_HPP

#include "gun_redis_string_origin.hh"
#include "gun_redis_collection.hh"
#include "gun_redis_compareable.hh"

/**
 *
 */
class gun_redis_string_object : public gun_redis_collection, public gun_redis_compareable {
private:
    string_origin *origin = nullptr;
    long hash = 0;
public:
    explicit gun_redis_string_object() = default;

    gun_redis_string_object(gun_redis_string_object &obj);

    gun_redis_string_object& operator=(gun_redis_string_object &obj);

    explicit gun_redis_string_object(const char *str);

    int get_length() override;

    bool operator==(gun_redis_string_object &object);

    void clear() override;

    int compare(gun_redis_compareable &comp) override;


    //void operator<<(int size);

    ~gun_redis_string_object();

};


#endif //GUNREDIS_GUN_REDIS_STRING_OBJECT_HPP