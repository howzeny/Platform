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
    
    void print_key_action(const std::vector<KeyAction> &actions) {
        console::print_with_banner("Possible Action", '/');
        for(const auto& key_action : actions) {
            auto key = key_action.first;
            auto action = key_action.second;
            std::cout << action << "-Key["<< Utility::CodeToKey(key) << "]" << std::endl;
        }
    }

}



void BattleManager::BattleStart() {
    InitTurn();
    console::print_function_surround_by_banner(&console::print_units_by_fast_order, "Units In Order", '#', 70);
    
    InitAction();
    
    while(!units_in_order_.empty()) {
        const Unit* next_unit = get_next_order_unit();
        ExecuteUnitTurn(next_unit);
        SwitchToNextUnit();
        
    }
}

bool BattleManager::AddBattleAction(Constant::InputCode input_code, BattleAction &action) {
    if(IsRegisterd(input_code)) {
        std::cout << "code is already registered" << std::endl;
        return false;
    }
    actions_.push_back(KeyAction(input_code, action));
    return true;
}

bool BattleManager::AddBattleAction(const KeyAction &key_action) {
    return AddBattleAction(key_action.first, key_action.second);
}

bool BattleManager::IsRegisterd(Constant::InputCode code) {
    for(const auto &key_action : actions_) {
        if(code == key_action.first ) {
            std::cout << "Already registered action Code";
            return true;
        }
    }
    return false;
}

void BattleManager::InitTurn() {
    ClearOrderStack();
    
    UnitManager &um = UnitManager::GetInstance();
    const std::vector<Unit*> &team_one = um.units_team_one();
    const std::vector<Unit*> &team_two = um.units_team_two();
    
    Utility::emerge_vector(units_in_order_, team_one, team_two);
    
    sort_unit_by_spd(units_in_order_);
}

void BattleManager::InitAction() {
    for(const auto &key_action : action::kKeyActionList) {
        AddBattleAction(key_action);
    }
}


void BattleManager::ExecuteUnitTurn(const Unit *unit) {
    console::print_with_banner("Unit Action", '#');
    std::cout << unit << std::endl;
    
    print_key_action(actions_);
    const AI *unit_ai = unit->unit_ai();
    
    Constant::InputCode input = unit_ai->DecideInput();
    BattleAction &action = ActionCall(input);
    //BattleAction& action = action::kNoAction;
    
    /*
    while(&action == &action::kNoAction) {
        Constant::InputCode input = unit_ai->DecideInput();
        action = ActionCall(input);
        std::cout << "Unit [" << unit->name() << "] choose <" << action << ">" << std::endl << std::endl;

    }*/
     std::cout << "Unit [" << unit->name() << "] choose <" << action << ">" << std::endl << std::endl;
    
    action.Execute(unit);
}

BattleAction &BattleManager::ActionCall(Constant::InputCode code) {
    for(const auto& key_action : actions_) {
        const auto& key = key_action.first;
        const auto& action = key_action.second;
        if(key == code) {
            return action.get();
        }
    }
    return action::kNoAction;
}

Constant::InputCode BattleManager::KeyToCode(const char input) {
    for(const auto& key_actions : actions_) {
        const auto& key = key_actions.first;
        if(Utility::CodeToKey(key) == input) {
            return key;
        }
    }
    return Constant::NO_INPUT;
}

void BattleManager::ClearOrderStack() {
    units_in_order_.clear();
}

const std::vector<Unit*> BattleManager::units_in_order() const {
    return units_in_order_;
}

const Unit* BattleManager::get_next_order_unit() const {
    return units_in_order_.front();
}

bool BattleManager::SwitchToNextUnit() {
    if(units_in_order_.empty())
        return false;
    Utility::pop_front(units_in_order_);
    return true;
}

//Singleton Implementation
BattleManager::BattleManager() {
    console::print_with_banner("Battle Manager is initialized" , '#');
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
