//
// Created by dos DRTT on 4/1/19.
//

#include "gun_redis_string_object.hpp"


namespace top_gun_plan {
    int top_gun_plan::gun_redis_string_object::get_length() {
        return this->origin->len;
    }

    /**
     * compare gun sds string
     * @param object
     * @return
     */
    bool top_gun_plan::gun_redis_string_object::operator==(gun_redis_string_object &object) {
        if (this->origin->len != object.get_length()) {
            return false;
        }
        if (this->hash != object.hash) {
            return false;
        }
        return false;
    }


    void top_gun_plan::gun_redis_string_object::clear() {
        delete this->origin;
        this->origin = new string_origin();
        hash = 0;
    }

    top_gun_plan::gun_redis_string_object::~gun_redis_string_object() {
        delete this->origin;
    }


    top_gun_plan::gun_redis_string_object::gun_redis_string_object(const char *str) {
        this->origin = new string_origin();
        for (; str[this->origin->len] != 0; ++(this->origin->len));
        this->origin->buff = new char[this->origin->len * 2]{0};
        this->origin->free = this->origin->len;
        for (int i = 0; i < this->origin->len; ++i) {
            this->origin->buff[i] = str[i];
            hash += str[i];
        }
    }

    int top_gun_plan::gun_redis_string_object::compare(gun_redis_compareable &comp) {
        return 0;
    }

    /**
    * copy construct function ,we do not suggest you use it
    * @Deprecated
    * @param obj
    */
    gun_redis_string_object::gun_redis_string_object(gun_redis_string_object &obj) {


    }

    /**
     *
     * @param construct function ,we do not suggest you use it
     * @return
     */
    gun_redis_string_object &gun_redis_string_object::operator=(gun_redis_string_object &obj) {
        return *this;
    }


    /**
     *
     * @return
     */
    const char *top_gun_plan::gun_redis_string_object::get_string() {
        return this->origin->buff;
    }

    /**
     *
     * @param val
     * @return
     */
    const char *top_gun_plan::gun_redis_string_object::operator<<(int val) {
        return get_string();
    }

//    std::ostream &gun_redis_string_object::operator<<(std::ostream &out, gun_redis_string_object &obj) {
//        out << get_string();
//        return out;
//    }


}
