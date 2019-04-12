//
// Created by dos DRTT on 4/1/19.
//

#include "gun_redis_string_object.hpp"


namespace gun_redis {
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
        size_t len = strlen(str);
        this->origin = new string_origin();
        this->origin->len = static_cast<int>(len);
        this->origin->free = this->origin->len;
        this->origin->buff = new char[this->origin->len * 2]{0};
        // memcpy()
        for (int i = 0; i < this->origin->len; ++i) {
            this->origin->buff[i] = str[i];
            hash += str[i];
        }
        get_hash();
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

    void gun_redis_string_object::replace(const char *old, const char *news) {

    }


    void gun_redis_string_object::catstring(const char *val) {
        size_t len = strlen(val);
        if (len < this->origin->free) {
            memcpy(this->origin->buff, val, len);
        }
    }

    void gun_redis_string_object::substring(int sta, int end) {

    }

    int gun_redis_string_object::get_hash() {
        if (origin != nullptr) {
            for (int i = 0; i < origin->len; ++i) {
                hash = hash ^ origin->buff[i];
            }
        } else {
            hash = 0;
        }
        return 0;
    }


}
