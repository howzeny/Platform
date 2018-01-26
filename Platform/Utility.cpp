//
//  Utility.cpp
//  Platform
//
//  Created by NamSangGyu on 2018. 1. 25..
//  Copyright © 2018년 NamSangGyu. All rights reserved.
//

#include "Utility.hpp"

std::string Utility::lowercase_string(std::string str) {
    std::string ret = str;
    std::transform(ret.begin(), ret.end(), ret.begin(), ::tolower);
    return ret;
}
