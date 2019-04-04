//
// Created by dos DRTT on 4/3/19.
//

#ifndef GUNREDIS_GUN_REDIS_LIST_HH
#define GUNREDIS_GUN_REDIS_LIST_HH

#include "gun_redis_list_base.hh"
#include "gun_redis_list_origin.hh"

template<typename T>
class gun_redis_list : gun_redis_list_base<T> {
private:
    int size;
    gun_redis_list_origin0<T> *head;
    gun_redis_list_origin0<T> *tail;
public:
    gun_redis_list() : size(0), head(nullptr), tail(nullptr) {}

    int get_length() override {
        return this->size;
    }

    void clear() override {
        this->size = 0;
        //some clear operate
    }

    void add(T val) override {
        gun_redis_list_origin0<T> *const node = new gun_redis_list_origin0<T>();
        node->val = val;

        if (tail == nullptr) {
            tail = node;
            head = node;
            this->size++;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
            this->size++;
        }
    }


    T get(int index) override {

        if (index < size / 2) {
            gun_redis_list_origin0<T> *move = head;
            for (int i = 0; i < index; ++i) {
                move = move->next;
            }
            return move->val;

        } else {
            gun_redis_list_origin0<T> *move = tail;
            for (int i = 0; i < size - index - 1; ++i) {
                move = move->prev;
            }
            return move->val;
        }
    }

    ~gun_redis_list() {

    }


};


#endif //GUNREDIS_GUN_REDIS_LIST_HH
