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

enum ActionType {
    NONE          = 0,
    
    SELF_TARGET          = (1 << 0),
    MULTI_TARGET         = (1 << 1),
    ALLY_TARGET          = (1 << 2),
    NEGATIVE_VALUE       = (1 << 3),
    BUFF                 = (1 << 4),
    HP_COST              = (1 << 5),
    
};

inline ActionType operator|(ActionType a, ActionType b) {
    return static_cast<ActionType>(static_cast<int>(a) | static_cast<int>(b));
}

class Action {
    std::string action_name_;
    ActionType action_type_;
    
    
    float multiplier_;
    float cost_;
    Constant::Attribute attr_type_;
    
public:
    Action(ActionType a_type, std::string a_name,Constant::Attribute attr, float multiplier, float cost);
    friend std::ostream& operator<<(std::ostream &os, const Action &a);
    void Execute(const Unit* unit);
};


typedef std::pair<Constant::InputCode, Action> KeyAction;

namespace action {
    extern Action kAttack;
    extern Action kMagicBolt;
    extern Action kFireBall;
    extern Action kHeal;
    extern Action kGuard;
    
    extern Action kNoAction;
    
    extern const std::vector<KeyAction> kKeyActionList;
};



/*

class BattleAction {
    
public:
    BattleAction();
    virtual ~BattleAction();
    friend std::ostream& operator<<(std::ostream &os, const BattleAction &ba);
    virtual void Execute(const Unit* unit) = 0;
    
//    virtual bool RequireSingleEnemyTarget() = 0;
//    virtual bool RequireAllEnemyTarget() = 0;
//    virtual bool RequireSingleAllyTarget() = 0;
//    virtual bool RequireAllAllyTarget() = 0;
  
private:
    virtual void print(std::ostream &os) const = 0;
};

class SingleTargetAction {
    
};



class AttackAction : public BattleAction {
public:
    AttackAction();
    virtual void Execute(const Unit* unit) override;
    
private:
    virtual void print(std::ostream &os) const override;
};

class SpellAction : public BattleAction {
  
public:
    virtual void Execute(const Unit* unit) override;

private:
    virtual void print(std::ostream& os) const override;
};

class GuardAction : public BattleAction {
  
public:
    virtual void Execute(const Unit* unit) override;

private:
    virtual void print(std::ostream &os) const override;
};

class NoAction : public BattleAction {
   
public:
    virtual void Execute(const Unit* unit) override;
    
private:
    virtual void print(std::ostream &os) const override;
};

//typedef std::pair<Constant::InputCode, char> CodeInput;
typedef std::pair<Constant::InputCode, std::reference_wrapper<BattleAction>> KeyAction;

namespace action {
    extern AttackAction kAttack;
    extern SpellAction kSpell;
    extern GuardAction kGuard;
    
    extern NoAction kNoAction;
    
    extern const std::vector<KeyAction> kKeyActionList;
};

*/

#endif /* BattleAction_hpp */
