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


const char Utility::CodeToKey(Constant::InputCode code) {
    switch(code) {
        case Constant::NUM_ONE:   return '1';
        case Constant::NUM_TWO:   return '2';
        case Constant::NUM_THREE: return '3';
        case Constant::NUM_FOUR:  return '4';
        case Constant::NUM_FIVE:  return '5';
            
        case Constant::NO_INPUT: return ' ';
    }
}
