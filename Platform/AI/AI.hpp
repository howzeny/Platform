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

class AI_Interface {
    
    virtual void print(std::ostream& os) const;
public:
    virtual const std::string ai_name() const = 0;
    //maybe I can set action using several protected virtual methods
    virtual void action() = 0;
    friend std::ostream& operator<<(std::ostream &os, const AI_Interface &ai);
};

class AI : AI_Interface {
    AI_Interface &wrapped;
public:
    AI();
    AI(AI_Interface &wrapper);
    
    virtual const std::string ai_name() const;
    virtual void action();
};

class Player : public AI_Interface {
    
public:
    virtual const std::string ai_name() const;
    virtual void action();
};


class NoAI : public AI_Interface {
public:
    NoAI(){}
    virtual const std::string ai_name() const {return "No AI";}
    virtual void action() {}
};

namespace ai {
    const NoAI kNoAI;
    const Player kPlayer;
    
    //Quite difficult to implement this code.
    //vector can't have raw reference. because It should be assignable.
    //If it is not pointer, reference_wrapper is needed.
    const std::vector<std::reference_wrapper<const AI_Interface>> kAIList = {
        kNoAI,
        kPlayer,
     };
     
};


#endif /* AI_hpp */
