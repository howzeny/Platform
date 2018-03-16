//
//  BattleAction.cpp
//  Platform
//
//  Created by NamSangGyu on 2018. 1. 30..
//  Copyright © 2018년 NamSangGyu. All rights reserved.
//

#include "BattleAction.hpp"


namespace action {
    Action kAttack(NONE, "attack", Constant::ATK, 1, 0);
    Action kMagicBolt(NONE, "magic bolt", Constant::INT, 1.8, 3);
    Action kFireBall(MULTI_TARGET, "fire ball", Constant::INT, 1.3, 6);
    Action kHeal(ALLY_TARGET|NEGATIVE_VALUE, "heal", Constant::INT, 2.0, 4);
    Action kGuard(BUFF, "guard", Constant::DEF, 2.0, 0);
};

Action::Action(ActionType a_type, std::string a_name, Constant::Attribute attr, float multiplier, float cost) {
    
}

std::ostream& operator<<(std::ostream &os, const Action &a) {
    os << a.action_name_ << ", Attribute : " << a.attr_type_ << " Mult(" << a.multiplier_ << ") [" <<  a.cost_ << "]" << std::endl;
    return os;
}



/*
namespace action {
    AttackAction kAttack;
    SpellAction kSpell;
    GuardAction kGuard;
    
    NoAction kNoAction;
    
    const std::vector<KeyAction> kKeyActionList = {
        KeyAction(Constant::NUM_ONE, kAttack),
        KeyAction(Constant::NUM_TWO, kSpell),
        KeyAction(Constant::NUM_THREE, kGuard),
    };
}


BattleAction::BattleAction() {
    
}

BattleAction::~BattleAction() {
    
}

std::ostream& operator<<(std::ostream &os, const BattleAction &ba) {
    ba.print(os);
    
    return os;
}


////Attack

AttackAction::AttackAction() {
    
}

void AttackAction::Execute(const Unit* unit) {
    
}

void AttackAction::print(std::ostream &os) const {
    os << "Attack";
}

///Spell

void SpellAction::Execute(const Unit* unit) {
    
}
void SpellAction::print(std::ostream &os) const {
    os << "Spell";
}



//Guard
void GuardAction::Execute(const Unit* unit) {
    
}
void GuardAction::print(std::ostream &os) const {
    os<< "Guard";
}

//No Action

void NoAction::Execute(const Unit* unit) {
    
}

void NoAction::print(std::ostream &os) const {
    os << "NO ACTION";
}

*/
