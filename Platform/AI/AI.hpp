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
#include <vector>

#include "Constant.h"

class AI_Interface {
    
    virtual void print(std::ostream& os) const;
public:
    virtual const std::string ai_name() const = 0;
    //maybe I can set action using several protected virtual methods
    virtual Constant::InputCode DecideInput() const = 0;
    
    friend std::ostream& operator<<(std::ostream &os, const AI_Interface &ai);
};

class AI : AI_Interface {
    AI_Interface &wrapped;
public:
    AI();
    AI(AI_Interface &wrapper);
    
    virtual const std::string ai_name() const;
    virtual Constant::InputCode DecideInput() const;
    
    Constant::InputCode Decision() const;
};

class Player : public AI_Interface {
    
public:
    virtual ~Player() {std::cout << "player is released" << std::endl;}
    virtual const std::string ai_name() const;
    virtual Constant::InputCode DecideInput() const;
};


class NoAI : public AI_Interface {
public:
    NoAI(){}
    virtual ~NoAI() {std::cout << "NoAI is released" << std::endl;}
    virtual const std::string ai_name() const;
    virtual Constant::InputCode DecideInput() const;
};

namespace ai {
    extern NoAI kNoAI;
    extern Player kPlayer;
    
    //Quite difficult to implement this code.
    //vector can't have raw reference. because It should be assignable.
    //If it is not pointer, reference_wrapper is needed.
    extern const std::vector<std::reference_wrapper<AI_Interface>> kAIList;
     
};


#endif /* AI_hpp */
