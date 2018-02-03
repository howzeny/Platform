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
#include "Unit.hpp"

class BattleAction {

public:
    BattleAction();
    virtual ~BattleAction(){}
    friend std::ostream& operator<<(std::ostream &os, const BattleAction &ba);
    virtual void Execute(const Unit* unit) = 0;
    
    virtual bool RequireSingleEnemyTarget() = 0;
    virtual bool RequireAllEnemyTarget() = 0;
    virtual bool RequireSingleAllyTarget() = 0;
    virtual bool RequireAllAllyTarget() = 0;
  
private:
    virtual void print(std::ostream &os) const = 0;
};



class AttackAction : public BattleAction {
public:
    AttackAction();
    virtual void Execute(const Unit* unit) override;
    
    virtual bool RequireSingleEnemyTarget() override;
    virtual bool RequireAllEnemyTarget() override;
    virtual bool RequireSingleAllyTarget() override;
    virtual bool RequireAllAllyTarget() override;
    
private:
    virtual void print(std::ostream &os) const override;
};

class SpellAction : public BattleAction {
  
public:
    virtual void Execute(const Unit* unit) override;
    
    virtual bool RequireSingleEnemyTarget() override;
    virtual bool RequireAllEnemyTarget() override;
    virtual bool RequireSingleAllyTarget() override;
    virtual bool RequireAllAllyTarget() override;
    
private:
    virtual void print(std::ostream& os) const override;
};

class GuardAction : public BattleAction {
  
public:
    virtual void Execute(const Unit* unit) override;
    
    virtual bool RequireSingleEnemyTarget() override;
    virtual bool RequireAllEnemyTarget() override;
    virtual bool RequireSingleAllyTarget() override;
    virtual bool RequireAllAllyTarget() override;
private:
    virtual void print(std::ostream &os) const override;
};

class NoAction : public BattleAction {
   
public:
    virtual void Execute(const Unit* unit) override;
    
    virtual bool RequireSingleEnemyTarget() override;
    virtual bool RequireAllEnemyTarget() override;
    virtual bool RequireSingleAllyTarget() override;
    virtual bool RequireAllAllyTarget() override;
private:
    virtual void print(std::ostream &os) const override;
};

typedef std::pair<Constant::InputCode, char> CodeInput;
typedef std::pair<CodeInput, std::reference_wrapper<BattleAction>> KeyAction;

namespace action {
    extern AttackAction kAttack;
    extern SpellAction kSpell;
    extern GuardAction kGuard;
    
    extern NoAction kNoAction;
    
    extern const std::vector<KeyAction> kKeyActionList;
};


std::ostream& operator<<(std::ostream &os, const CodeInput &ic);

#endif /* BattleAction_hpp */
