//
//  AI.hpp
//  Platform
//
//  Created by NamSangGyu on 2018. 1. 23..
//  Copyright © 2018년 NamSangGyu. All rights reserved.
//

#ifndef AI_hpp
#define AI_hpp

#include <iostream>
#include <string>

class AI {
    std::string ai_name_;
    
public:
    const std::string &ai_name() const;
};

#endif /* AI_hpp */
