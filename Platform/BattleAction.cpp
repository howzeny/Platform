//
//  BattleAction.cpp
//  Platform
//
//  Created by NamSangGyu on 2018. 1. 30..
//  Copyright © 2018년 NamSangGyu. All rights reserved.
//

#include "BattleAction.hpp"




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


