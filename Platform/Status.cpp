//
//  Status.cpp
//  Platform
//
//  Created by NamSangGyu on 2018. 1. 25..
//  Copyright © 2018년 NamSangGyu. All rights reserved.
//

#include "Status.hpp"
#include <iostream>

namespace {
    std::string bracket_attr(int stat) {
        return "(" + std::to_string(stat) + ")";
    }
    std::string bracket_points(int point, int max_point) {
        return "(" + std::to_string(point) + "/" + std::to_string(max_point) + ")";
    }
}

std::ostream& operator<<(std::ostream &os, const UnitStatus &us) {
    
    os << "[HP" << bracket_points(us.hp, us.mhp) <<"  MP" << bracket_points(us.mp, us.mmp) <<"]" << std::endl;
    os << "[ATK" << bracket_attr(us.atk) <<"  DEF" << bracket_attr(us.def) <<  " INT" << bracket_attr(us.intelligence) << "  RES" << bracket_attr(us.resist) <<"  SPD" << bracket_attr(us.spd) <<"]" << std::endl;
    
    return os;
}
