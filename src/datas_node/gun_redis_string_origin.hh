//
// Created by dos DRTT on 4/1/19.
//

#ifndef GUNREDIS_GUN_REDIS_STRING_ORIGIN_HH
#define GUNREDIS_GUN_REDIS_STRING_ORIGIN_HH
#pragma once


#endif //GUNREDIS_GUN_REDIS_STRING_ORIGIN_HH


typedef struct string_origin_0 {
    /**
     * the size of have use length
     */
    int len = 0;
    /**
     * the size of have not use length
     */
    int free = 0;
    /**
     * char * buffer
     */
    char *buff = nullptr;
} string_origin;