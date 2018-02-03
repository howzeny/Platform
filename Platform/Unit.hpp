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
    
    const AI *unit_ai_;
    
    const Weapon *weapon_;
    const Armor *armor_;
    
public:
    virtual ~Unit();
    Unit(std::string name, UnitStatus stats, const AI *ai);
    Unit(std::string name, UnitStatus stats, const AI *ai, const Weapon *weapon, const Armor *armor);
    
    void SetAI(const AI *ai);
    void SetWeapon(const Weapon *weapon);
    void SetArmor(const Armor *armor);
    
    const UnitStatus &stats() const ;
    const AI *unit_ai() const;
    const std::string &name() const;
    
    friend std::ostream& operator<<(std::ostream& os, const Unit* unit);
};

class FastUnit {
public:
    inline bool operator() (const Unit* unit1, const Unit* unit2) {
        return unit1->stats().spd > unit2->stats().spd;
    }
};

#endif /* Unit_hpp */
