//
//  Console.cpp
//  Platform
//
//  Created by NamSangGyu on 2018. 1. 29..
//  Copyright © 2018년 NamSangGyu. All rights reserved.
//

#include "Console.hpp"
#include "UnitManager.hpp"
#include "AI.hpp"
#include "GameManager.hpp"
#include "BattleManager.hpp"

#include <iostream>

void console::clear_screen() {
    for(int i = 0; i < 70; i++) {
        std::cout << std::endl;
    }
}
    
void console::print_members_in_battle_field() {
    UnitManager &um = UnitManager::GetInstance();
    um.PrintUnitsInTeamOne();
    um.PrintUnitsInTeamTwo();
}

void console::print_ai_list() {
    int index = 1;
    for(const auto &ai : ai::kAIList) {
        std::cout << index++ << ". " <<  ai << std::endl;
    }
}

void console::print_units_by_fast_order() {
    std::cout << "Units in Order <Next Unit>" << std::endl;
    int index = 1;
    
    for(const auto &unit : BattleManager::GetInstance().units_in_order()) {
        std::cout << index++ << ". " << unit << std::endl;
    }
}


void console::show_action_list() {
    
}

void console::print_with_banner(const std::string &text, const char banner, int banner_size ) {
    std::string edge(banner_size, banner);
    long body_half_edge_size = ((banner_size - text.length()) / 2) - 1;
    std::string middle(body_half_edge_size, banner);
    
    std::cout << edge << std::endl;
    if(text.length() % 2 !=0)
        std::cout << middle << " " << text << " " << middle << banner << std::endl;
    else
        std::cout << middle << " " << text << " " << middle << std::endl;
    std::cout << edge << std::endl;
}
