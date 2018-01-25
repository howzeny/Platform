//
//  Unit.hpp
//  Platform
//
//  Created by NamSangGyu on 2018. 1. 23..
//  Copyright © 2018년 NamSangGyu. All rights reserved.
//

#ifndef Unit_hpp
#define Unit_hpp

#include <iostream>
#include "Status.hpp"
#include "AI/AI.hpp"
#include "Equipment.hpp"

class Unit {
private:
    std::string name_;
    UnitStatus stats_;
    AI *unit_ai_;
    
    const Weapon *weapon_;
    const Armor *armor_;
    
public:
    Unit(std::string name, UnitStatus stats);
    Unit(std::string name, UnitStatus stats,AI *ai, const Weapon *weapon, const Armor *armor);
    
    void SetAI(const AI *ai);
    void SetWeapon(const Weapon *weapon);
    void SetArmor(const Armor *armor);
    
    friend std::ostream& operator<<(std::ostream& os, const Unit* unit);
};

#endif /* Unit_hpp */
