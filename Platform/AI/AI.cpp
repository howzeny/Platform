//
//  AI.cpp
//  Platform
//
//  Created by NamSangGyu on 2018. 1. 23..
//  Copyright © 2018년 NamSangGyu. All rights reserved.
//

#include "AI.hpp"
#include "Console.hpp"

//AI Interface
void AI_Interface::print(std::ostream &os) const {
    os << "AI Name : " << this->ai_name();
}

std::ostream& operator<<(std::ostream &os, const AI_Interface &ai) {
    ai.print(os);
    return os;
}



//AI
AI::AI(AI_Interface &wrapper) :wrapped(wrapper) {
    std::cout << "seperate ?" << std::endl;
}



const std::string AI::ai_name() const {
    return "AI(" + wrapped.ai_name() + ")";
}

Constant::InputCode AI::DecideInput() const {
    return wrapped.DecideInput();
}

std::string AI::Decision()() const {
    return DecideInput();
}

//Player
const std::string Player::ai_name() const {
    return "Player";
}

Constant::InputCode Player::DecideInput() const {
    return console::GetInputCode();
}

//NoAI
const std::string NoAI::ai_name() const {
    return "No AI";
}

Constant::InputCode NoAI::DecideInput() const {
    return Constant::NO_INPUT;
}

namespace ai {
    
    NoAI kNoAI;
    Player kPlayer;
    
    const std::vector<std::reference_wrapper<AI_Interface>> kAIList = {
        kNoAI,
        kPlayer,
    };

};
