//
//  AI.cpp
//  Platform
//
//  Created by NamSangGyu on 2018. 1. 23..
//  Copyright © 2018년 NamSangGyu. All rights reserved.
//

#include "AI.hpp"


AI::AI(AI_Interface &wrapper) :wrapped(wrapper) {
    
}

const std::string AI::ai_name() const {
    return "AI(" + wrapped.ai_name() + ")";
}

void AI::action() {
    wrapped.action();
}
