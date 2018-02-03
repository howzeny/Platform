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
    const UnitManager &um = UnitManager::GetInstance();
    
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
    const BattleManager &bm = BattleManager::GetInstance();
    
    for(const auto &unit : bm.units_in_order()) {
        std::cout << index << ". " << unit;
        if(index != bm.units_in_order().size()) {
            std::cout << std::endl;
            index++;
        }
    }
}


void console::show_action_list() {
    
}

void console::print_with_banner(const std::string &text, const char banner, int banner_size ) {
    int text_size = (int)text.length();
    long side_space = (banner_size - text_size);
    
    //text size + 4 is larger than banner_size
    // #####                     #########
    // hello  -> make it to      # hello #
    // #####                     #########
    if (side_space < 4)
        banner_size = text_size + 4;
    
    side_space = banner_size - text_size;
    std::string edge(banner_size, banner);
    long body_half_edge_size = side_space / 2 - 1;

    std::string middle(body_half_edge_size, ' ');
    
   std::cout << edge << std::endl;
    if( side_space % 2 != 0)
        std::cout << banner << middle << text << middle <<" "<< banner << std::endl;
    else
        std::cout << banner << middle << text << middle <<  banner << std::endl;
    
    std::cout << edge << std::endl;

}


void console::print_function_surround_by_banner(void (*other_function)(), const std::string &text, const char banner, int banner_size) {
    std::cout << std::endl;
    console::print_with_banner(text, banner, banner_size);
    (*other_function)();
    console::print_with_banner("End of "+text, banner, banner_size);
    std::cout << std::endl;
}


Constant::InputCode console::GetInputCode() {
    std::cout << "Choose Action to execute: ";
    
    return Constant::NO_INPUT;
}
