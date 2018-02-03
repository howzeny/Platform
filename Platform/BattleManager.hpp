//
//  BattleManager.hpp
//  Platform
//
//  Created by NamSangGyu on 2018. 1. 31..
//  Copyright © 2018년 NamSangGyu. All rights reserved.
//

#ifndef BattleManager_hpp
#define BattleManager_hpp


#include <vector>

#include "BattleAction.hpp"
#include "Unit.hpp"

class BattleManager {
    //std::pair<std::pari<Constant::InputCode char>, std::reference_wrapper<BattleAction>> KeyAction;
    std::vector<KeyAction> actions_;
    std::vector<Unit*> units_in_order_;
    
public:
    void BattleStart();
    
    bool AddBattleAction(const CodeInput &input_code, BattleAction &action);
    bool AddBattleAction(const KeyAction &key_action);
    bool IsRegisterd(const CodeInput &code);
    
    void InitTurn();
    void InitAction();
    
    void ExecuteUnitTurn(const Unit* unit);
    BattleAction &ActionCall(Constant::InputCode code);
    
    Constant::InputCode KeyToCode(const char input);
    
    void ClearOrderStack();
    
    const std::vector<Unit*> units_in_order() const;
    const Unit* get_next_order_unit() const;
    bool SwitchToNextUnit();
    
//Singleton
private:
    BattleManager();
    virtual ~BattleManager();
public:
    static BattleManager& GetInstance();
    
    BattleManager(const BattleManager&) = delete;
    void operator=(const BattleManager&) = delete;
};


#endif /* BattleManager_hpp */

