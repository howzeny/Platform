//
//  BattleManager.cpp
//  Platform
//
//  Created by NamSangGyu on 2018. 1. 31..
//  Copyright © 2018년 NamSangGyu. All rights reserved.
//

#include "BattleManager.hpp"
#include "Utility.hpp"
#include "UnitManager.hpp"
#include "Console.hpp"


#include <iostream>

namespace {
    void sort_unit_by_spd(std::vector<Unit*> &team) {
        std::sort(team.begin(), team.end(), FastUnit());
    }
}



void BattleManager::BattleStart() {
    InitTurn();
    
    console::print_with_banner("Units In Order", '#');
    console::print_units_by_fast_order();
    console::print_with_banner("End of Units In Order", '#');
}

bool BattleManager::AddBattleAction(BattleAction &action) {
    if(IsRegisterd(action.execution_code())) {
        std::cout << "code is already registered" << std::endl;
        return false;
    }
    actions_.push_back(action);
    return true;
}

bool BattleManager::IsRegisterd(Constant::InputCode code) {
    for(const auto &action : actions_) {
        if(code == action.get().execution_code()) {
            return true;
        }
    }
    return false;
}

void BattleManager::InitTurn() {
    UnitManager &um = UnitManager::GetInstance();
    const std::vector<Unit*> &team_one = um.units_team_one();
    const std::vector<Unit*> &team_two = um.units_team_two();
    
    /*
    //preallocate mem
    units_in_order_.reserve( team_one.size() + team_two.size());
    //add team one
    units_in_order_.insert(units_in_order_.end(), team_one.begin(), team_one.end());
    //add team two
    units_in_order_.insert(units_in_order_.end(), team_two.begin(), team_two.end());
    */
    Utility::emerge_vector(units_in_order_, team_one, team_two);
    
    sort_unit_by_spd(units_in_order_);
}

const std::vector<Unit*> BattleManager::units_in_order() const {
    return units_in_order_;
}

const Unit* BattleManager::NextUnit() const{
    return units_in_order_.front();
}

//Singleton Implementation
BattleManager::BattleManager() {
    std::cout << "Battle Manager is initialized" << std::endl;
    
}

BattleManager::~BattleManager() {
    for( auto &unit : units_in_order_) {
        delete unit;
    }
}

BattleManager& BattleManager::GetInstance() {
    static BattleManager instance;
    
    return instance;
}
