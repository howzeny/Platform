//
//  main.cpp
//  Platform
//
//  Created by NamSangGyu on 2018. 1. 23..
//  Copyright © 2018년 NamSangGyu. All rights reserved.
//

#include <iostream>

#include "GameManager.hpp"
#include "Status.hpp"
#include "Unit.hpp"
#include "UnitManager.hpp"
#include "UnitRecruit.hpp"
#include "AI.hpp"
#include "Console.hpp"
#include "Utility.hpp"
#include "BattleManager.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    UnitRecruitExample ex;
    
    GameManager &gm = GameManager::GetInstance();
    gm.Initialize(ex);
    gm.ShowUnitsInEachTeam();
    
    BattleManager &bm = BattleManager::GetInstance();
    bm.BattleStart();
    
    return 0;
}
