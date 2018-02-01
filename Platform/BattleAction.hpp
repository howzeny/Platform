//
//  BattleAction.hpp
//  Platform
//
//  Created by NamSangGyu on 2018. 1. 30..
//  Copyright © 2018년 NamSangGyu. All rights reserved.
//

#ifndef BattleAction_hpp
#define BattleAction_hpp

#include <iostream>
#include "Constant.h"

class BattleAction {

public:
    BattleAction(Constant::InputCode input_code);
    friend std::ostream& operator<<(std::ostream &os, const BattleAction &ba);
    virtual void Execute() = 0;
    
    const Constant::InputCode execution_code() const;
    
protected:
    Constant::InputCode execution_code_;
private:
    virtual void print(std::ostream &os) const = 0;
};



class AttackAction : public BattleAction {
public:
    AttackAction(Constant::InputCode input_code);
    virtual void Execute() override;
private:
    virtual void print(std::ostream &os) const override;
};

class SpellAction : public BattleAction {
  
public:
    virtual void Execute() override;
private:
    virtual void print(std::ostream& os) const override;
};

#endif /* BattleAction_hpp */
