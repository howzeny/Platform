//
//  Console.hpp
//  Platform
//
//  Created by NamSangGyu on 2018. 1. 29..
//  Copyright © 2018년 NamSangGyu. All rights reserved.
//

#ifndef Console_hpp
#define Console_hpp

#include <string>

namespace console {
    void clear_screen();
    void print_members_in_battle_field();
    void print_ai_list();
    void print_units_by_fast_order();
    
    void show_action_list();
    
    void print_with_banner(const std::string &text,const char banner, int banner_size = 70);
}
#endif /* Console_hpp */
