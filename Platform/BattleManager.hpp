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
    std::vector<std::reference_wrapper<BattleAction>> actions_;
    std::vector<Unit*> units_in_order_;
    
public:
    void BattleStart();
    
    bool AddBattleAction(BattleAction &action);
    bool IsRegisterd(Constant::InputCode code);
    
    void InitTurn();
    
    void ExecuteUnitTurn(Unit* unit);
    
    const std::vector<Unit*> units_in_order() const;
    const Unit* NextUnit() const;
    
    
private:
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

