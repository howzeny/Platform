//
//  Unit.cpp
//  Platform
//
//  Created by NamSangGyu on 2018. 1. 23..
//  Copyright © 2018년 NamSangGyu. All rights reserved.
//

#include "Unit.hpp"

Unit::Unit(std::string name, UnitStatus stats, AI &ai) :Unit(name, stats, ai, NULL, NULL) {

}

Unit::Unit(std::string name, UnitStatus stats,AI &ai, const Weapon *weapon, const Armor *armor):name_(name), stats_(stats), unit_ai_(ai), weapon_(weapon), armor_(armor) {
    
}

void Unit::SetWeapon(const Weapon *weapon) {
    weapon_ = weapon;
}

void Unit::SetArmor(const Armor *armor) {
    armor_ = armor;
}

std::ostream& operator<<(std::ostream& os, const Unit* unit)
{
    os << "Unit Name : " << unit->name_ << std::endl;
    os << unit->stats_ ;
    return os;
}
