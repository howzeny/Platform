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

int main(int argc, const char * argv[]) {
    // insert code here...
    UnitRecruitExample ex;
    
    ex.AddUnitsToTeamOne();
    ex.AddUnitsToTeamTwo();
    
    UnitManager::GetInstance().PrintUnitsInTeamOne();
    UnitManager::GetInstance().PrintUnitsInTeamTwo();
    //std::cout << a << std::endl;
    return 0;
}
