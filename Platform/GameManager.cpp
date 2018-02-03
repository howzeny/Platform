//
//  GameManager.cpp
//  Platform
//
//  Created by NamSangGyu on 2018. 1. 23..
//  Copyright © 2018년 NamSangGyu. All rights reserved.
//

#include "GameManager.hpp"
#include "UnitManager.hpp"
#include "Console.hpp"
#include <iostream>




namespace  {

    bool InitTeamUnits(IUnitRecruit &recruiter) {
        recruiter.AddUnitsToTeamOne();
        recruiter.AddUnitsToTeamTwo();
        UnitManager &um = UnitManager::GetInstance();
        
        if(um.IsTeamOneEmpty() || um.IsTeamTwoEmpty()) {
            std::cout << "You should set at least One menber in each team" << std::endl;
            std::cout << "Reset Team" <<std::endl;
            um.ClearTeam();
            return false;
        }
        return true;
    }
}; //End of unnamed namespace



bool GameManager::Initialize(IUnitRecruit &recruiter) {
    //First Initialized Team Members
    
    if(!InitTeamUnits(recruiter)) {
        return false;
    }
    //Init AI
    
    //Init Equipment
    
    
    return true;
}


void GameManager::ShowUnitsInEachTeam() const {
    const UnitManager &um = UnitManager::GetInstance();
    
    console::print_with_banner("TEAM ONE MEMBER", '#', 50);
    um.PrintUnitsInTeamOne();
    
    console::print_with_banner("TEAM TWO MEMBER", '#', 50);
    um.PrintUnitsInTeamTwo();
    
    console::print_with_banner("END OF UNITS", '#', 50);
    std::cout << std::endl;
    
}





GameManager::GameManager() {
    console::print_with_banner("GameManager Initialized", '#', 20);
}

GameManager::~GameManager() {
  
}

GameManager& GameManager::GetInstance() {
    static GameManager instance;
    
    return instance;
}
