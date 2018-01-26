//
//  Status.hpp
//  Platform
//
//  Created by NamSangGyu on 2018. 1. 23..
//  Copyright © 2018년 NamSangGyu. All rights reserved.
//

#ifndef Status_hpp
#define Status_hpp

#include <stdio.h>
#include <string>

struct BaseStatus {
    int hp;
    int mp;
    
    int atk;
    int def;
    int intelligence;
    int resist;
    int spd;
};

//no need yet


struct UnitStatus {
    int mhp;
    int hp;
    int mmp;
    int mp;
    
    int atk;
    int def;
    int intelligence;
    int resist;
    int spd;
    UnitStatus() : UnitStatus(0, 0, 0, 0, 0, 0, 0) {}
    UnitStatus(int mhp, int mmp, int atk, int def, int intelligence, int resist, int spd) : mhp(mhp), hp(mhp), mmp(mmp), mp(mmp), atk(atk), def(def), intelligence(intelligence), resist(resist), spd(spd) {}
    
    friend std::ostream& operator<<(std::ostream &os, const UnitStatus &us);
};

struct EquipStatus {
    int hp;
    int mp;
    
    int atk;
    int def;
    int intelligence;
    int resist;
    int spd;
};

#endif /* Status_hpp */
