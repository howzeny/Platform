//
//  Unit.cpp
//  Platform
//
//  Created by NamSangGyu on 2018. 1. 23..
//  Copyright © 2018년 NamSangGyu. All rights reserved.
//

#include "Unit.hpp"

Unit::~Unit() {
    std::cout << "Unit " << name_ << "is released" << std::endl;
    if(unit_ai_ != NULL) {
        delete unit_ai_;
    }
    if(weapon_ != NULL) {
        delete weapon_;
    }
    if(armor_ != NULL) {
        delete armor_;
    }
}

Unit::Unit(std::string name, UnitStatus stats, const AI *ai) :Unit(name, stats, ai, NULL, NULL) {

}

Unit::Unit(std::string name, UnitStatus stats, const AI *ai, const Weapon *weapon, const Armor *armor):name_(name), stats_(stats), weapon_(weapon), armor_(armor) {
    if(ai == NULL) {
        unit_ai_ = new AI(ai::kNoAI);
    }
    else
        unit_ai_ = ai;
}

void Unit::SetAI(const AI *ai) {
    unit_ai_ = ai;
}
void Unit::SetWeapon(const Weapon *weapon) {
    weapon_ = weapon;
}

void Unit::SetArmor(const Armor *armor) {
    armor_ = armor;
}

const UnitStatus &Unit::stats() const {
    return stats_;
}

const AI *Unit::unit_ai() const {
    return unit_ai_;
}

const std::string &Unit::name() const {
    return name_;
}

std::ostream& operator<<(std::ostream& os, const Unit* unit)
{
    os << "Unit Name : " << unit->name_ << std::endl;
    os << unit->stats_ << std::endl;
    return os;
}
