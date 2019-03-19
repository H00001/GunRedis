//
// Created by dos DRTT on 3/17/19.
//
#pragma once
#ifndef GUNREDIS_GUNSTRING_HPP
#define GUNREDIS_GUNSTRING_HPP

#include <iostream>
#include <string>

class GunString {
private:
    std::string originl;
public:
    explicit GunString(const std::string &originl);

    const std::string &getOriginl() const;

    void setOriginl(const std::string &originl);
};


#endif //GUNREDIS_GUNSTRING_HPP
