//
// Created by dos DRTT on 3/17/19.
//

#include "GunString.hpp"

GunString::GunString(const std::string &originl) : originl(originl) {
}

const std::string &GunString::getOriginl() const {
    return originl;
}

void GunString::setOriginl(const std::string &originl) {
    GunString::originl = originl;
}

