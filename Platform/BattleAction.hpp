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
#include <vector>

#include "Constant.h"

class BattleAction {

public:
    BattleAction();
    virtual ~BattleAction(){}
    friend std::ostream& operator<<(std::ostream &os, const BattleAction &ba);
    virtual void Execute() = 0;
  
private:
    virtual void print(std::ostream &os) const = 0;
};



class AttackAction : public BattleAction {
public:
    AttackAction();
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

class GuardAction : public BattleAction {
  
public:
    virtual void Execute() override;
private:
    virtual void print(std::ostream &os) const override;
};

class NoAction : public BattleAction {
   
public:
    virtual void Execute() override;
private:
    virtual void print(std::ostream &os) const override;
};

typedef std::pair<Constant::InputCode, char> CodeKey;
typedef std::pair<CodeKey, std::reference_wrapper<BattleAction>> KeyAction;

namespace action {
    extern AttackAction kAttack;
    extern SpellAction kSpell;
    extern GuardAction kGuard;
    
    extern NoAction kNoAction;
    
    extern const std::vector<KeyAction> kKeyActionList;
};


std::ostream& operator<<(std::ostream &os, const CodeKey &ic);

#endif /* BattleAction_hpp */
