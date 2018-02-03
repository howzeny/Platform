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
        KeyAction(CodeKey(Constant::NUM_ONE, '1'), kAttack),
        KeyAction(CodeKey(Constant::NUM_TWO, '2'), kSpell),
        KeyAction(CodeKey(Constant::NUM_THREE, '3'), kGuard),
    };
}


BattleAction::BattleAction() {
    
}

std::ostream& operator<<(std::ostream &os, const BattleAction &ba) {
    ba.print(os);
    
    return os;
}


////Attack

AttackAction::AttackAction() {
    
}

void AttackAction::Execute() {
    
}

void AttackAction::print(std::ostream &os) const {
    os << "Attack";
}

///Spell

void SpellAction::Execute() {
    
}
void SpellAction::print(std::ostream &os) const {
    os << "Spell";
}



//Guard
void GuardAction::Execute() {
    
}
void GuardAction::print(std::ostream &os) const {
    os<< "Guard";
}

//No Action

void NoAction::Execute() {
    
}

void NoAction::print(std::ostream &os) const {
    os << "NO ACTION";
}




std::ostream& operator<<(std::ostream &os, const CodeKey &ic) {
    os << ic.second;
    return os;
}
