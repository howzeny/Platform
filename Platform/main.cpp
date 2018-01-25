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

int main(int argc, const char * argv[]) {
    // insert code here...
    Unit *unit1 = new Unit("test", {1, 2, 3, 4, 5, 6, 7});
    Unit *unit2 = new Unit("test2", {2, 2, 3, 4, 5, 6, 7});
    
    UnitManager::GetInstance().AddUnitToTeamOne(unit1);
    UnitManager::GetInstance().AddUnitToTeamOne(unit2);
    UnitManager::GetInstance().AddUnitToTeamOne(unit1);
    UnitManager::GetInstance().PrintUnitsInTeamOne();
    UnitManager::GetInstance().RemoveUnitFromTeamOne(unit1);
    UnitManager::GetInstance().RemoveXthUnitFromTeamOne(1);
    if(UnitManager::GetInstance().RemoveUnitFromTeamOne(unit1)) {
        std::cout << "success to remove unit" << std::endl;
    } else  {
        std::cout << "fail to remove unit" << std::endl;
    }
    UnitManager::GetInstance().PrintUnitsInTeamOne();
    
    return 0;
}
