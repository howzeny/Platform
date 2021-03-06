//
//  Constant.h
//  Platform
//
//  Created by NamSangGyu on 2018. 1. 24..
//  Copyright © 2018년 NamSangGyu. All rights reserved.
//

#ifndef Constant_h
#define Constant_h

namespace Constant {
    enum Team {
        TEAM_ONE,
        TEAM_TWO,
        
        NO_TEAM, // Dont know its necessity yet
    };
    
    enum InputCode {
        NUM_ONE,
        NUM_TWO,
        NUM_THREE,
        NUM_FOUR,
        NUM_FIVE,
        
        
        NO_INPUT,
    };
    
    enum Attribute {
        HP,
        MP,
        ATK,
        DEF,
        INT,
        RES,
        SPD
    };
}

#endif /* Constant_h */
