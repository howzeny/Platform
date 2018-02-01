//
//  BattleAction.cpp
//  Platform
//
//  Created by NamSangGyu on 2018. 1. 30..
//  Copyright © 2018년 NamSangGyu. All rights reserved.
//

#include "BattleAction.hpp"



BattleAction::BattleAction(Constant::InputCode input_code) : execution_code_(input_code) {
    
}

std::ostream& operator<<(std::ostream &os, const BattleAction &ba) {
    ba.print(os);
    
    return os;
}

const Constant::InputCode BattleAction::execution_code() const {
    return execution_code_;
}


////Attack

AttackAction::AttackAction(Constant::InputCode input_code) : BattleAction(input_code) {
    
}

void AttackAction::Execute() {
    
}

void AttackAction::print(std::ostream &os) const {
    os << "Attack" << std::endl;
}
