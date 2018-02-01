//
//  Utility.hpp
//  Platform
//
//  Created by NamSangGyu on 2018. 1. 25..
//  Copyright © 2018년 NamSangGyu. All rights reserved.
//

#ifndef Utility_hpp
#define Utility_hpp

#include <algorithm>
#include <string>
#include <vector>


namespace Utility {
    std::string lowercase_string(std::string str);
    
    template<typename T>
    bool element_in_vector(const T &element,const std::vector<T> &vector) {
        return std::find(vector.begin(), vector.end(), element) != vector.end();
    }
    
    template<typename T>
    bool element_in_vector(const T &element,const std::vector<std::reference_wrapper<T>> &vector) {
        return std::find(vector.begin(), vector.end(), element) != vector.end();
    }

    template<typename T>
    bool element_in_vector(const T *element,const std::vector<T*> &vector) {
        return std::find(vector.begin(), vector.end(), element) != vector.end();
    }

    template<typename T>
    void emerge_vector(std::vector<T> &target, const std::vector<T> &vec_one, const std::vector<T> &vec_two) {
        target.reserve(vec_one.size() + vec_two.size());
        target.insert(target.end(), vec_one.begin(), vec_one.end());
        target.insert(target.end(), vec_two.begin(), vec_two.end());
    }
};

#endif /* Utility_hpp */
