//
// Created by dos DRTT on 4/1/19.
//

#include "gun_redis_string_object.hpp"


int gun_redis_string_object::get_length() {
    return this->origin->len;
}

bool gun_redis_string_object::operator==(gun_redis_string_object &object) {
    if (this->origin->len != object.get_length()) {
        return false;
    }
    if (this->hash != object.hash) {
        return false;
    }


    return false;
}

void gun_redis_string_object::clear() {
    delete this->origin;
    this->origin = new string_origin();
    hash = 0;
}

gun_redis_string_object::~gun_redis_string_object() {
    delete this->origin;
}


gun_redis_string_object::gun_redis_string_object(const char *str) {
    this->origin = new string_origin();
    for (; str[this->origin->len] != 0; ++(this->origin->len));
    this->origin->buff = new char[this->origin->len * 2]{0};
    this->origin->free = this->origin->len;
    for (int i = 0; i < this->origin->len; ++i) {
        this->origin->buff[i] = str[i];
    }
}

int gun_redis_string_object::compare(gun_redis_compareable &comp) {
    return 0;
}

gun_redis_string_object::gun_redis_string_object(gun_redis_string_object &obj) {


}

gun_redis_string_object& gun_redis_string_object::operator=(gun_redis_string_object &obj) {

}

