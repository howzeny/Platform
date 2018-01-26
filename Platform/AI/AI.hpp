//
//  AI.hpp
//  Platform
//
//  Created by NamSangGyu on 2018. 1. 23..
//  Copyright © 2018년 NamSangGyu. All rights reserved.
//

#ifndef AI_hpp
#define AI_hpp

#include <iostream>
#include <string>

class AI_Interface {
    
public:
    virtual const std::string ai_name() const = 0;
    virtual void action() = 0;
};

class AI : AI_Interface {
    AI_Interface &wrapped;
public:
    AI(AI_Interface &wrapper);
    
    virtual const std::string ai_name() const;
    virtual void action();
};

class NoAI : public AI_Interface {
    
public:
    NoAI(){}
    virtual const std::string ai_name() const {return "No AI";}
    virtual void action() {}
};




#endif /* AI_hpp */
