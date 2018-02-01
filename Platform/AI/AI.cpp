//
//  AI.cpp
//  Platform
//
//  Created by NamSangGyu on 2018. 1. 23..
//  Copyright © 2018년 NamSangGyu. All rights reserved.
//

#include "AI.hpp"

void AI_Interface::print(std::ostream &os) const {
    os << "AI Name : " << this->ai_name();
}

std::ostream& operator<<(std::ostream &os, const AI_Interface &ai) {
    ai.print(os);
    return os;
}

AI::AI(AI_Interface &wrapper) :wrapped(wrapper) {
    
}

const std::string AI::ai_name() const {
    return "AI(" + wrapped.ai_name() + ")";
}

void AI::action() {
    wrapped.action();
}



const std::string Player::ai_name() const {
    return "Player";
}

void Player::action() {

}


