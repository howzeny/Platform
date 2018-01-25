//
//  UnitData.cpp
//  Platform
//
//  Created by NamSangGyu on 2018. 1. 23..
//  Copyright © 2018년 NamSangGyu. All rights reserved.
//

#include "UnitData.hpp"

namespace {
    std::string name_distinct(UnitType u_type) {
        switch(u_type) {
            case UNIT_WARRIOR:
                return "Warrior";
            case UNIT_MAGICIAN:
                return "Magician";
            case UNIT_HEALER:
                return "Hearler";
                
            case UNIT_SKELETON:
                return "Skeleton";
            case UNIT_SKELETON_MAGE:
                return "Skeleton Mage";
            case UNIT_ORGE:
                return "Orge";
            case NO_UNIT:
                return "None";
            default:
                return "Error";
        }
    }
}

UnitData::UnitData(UnitStatus status) {
    stats = status;
}

UnitData::UnitData(UnitType type, UnitStatus status){
    type_name = name_distinct(type);
    stats = status;
}

std::ostream& operator<<(std::ostream& os, const UnitData& ud) {
    const UnitStatus &stat = ud.stats;
    os << "Unit Type : " << ud.type_name << "\n";
    os << "[HP MP ATK DEF INT RES SPD]" << "\n";
    os << " " << stat.hp << "\t" << stat.mp << "\t" << stat.atk << "\t" << stat.def
    << "\t" << stat.intelligence << "\t" << stat.resist << "\t" << stat.spd << std::endl;
    return os;
}
