//
//  UnitData.cpp
//  Platform
//
//  Created by NamSangGyu on 2018. 1. 23..
//  Copyright © 2018년 NamSangGyu. All rights reserved.
//

#include "UnitData.hpp"
#include "Utility.hpp"

namespace {
    std::string name_distinct(UnitType u_type) {
        switch(u_type) {
            case UNIT_WARRIOR:           return "Warrior";
            case UNIT_TANKER:            return "Tanker";
            case UNIT_MAGICIAN:          return "Magician";
            case UNIT_HEALER:            return "Hearler";
            case UNIT_DARK_HEALER:        return "Dark Healer";
            
            case UNIT_SKELETON:          return "Skeleton";
            case UNIT_SKELETON_MAGE:     return "Skeleton Mage";
            case UNIT_ORGE:              return "Orge";
                
            case NO_UNIT:                return "None";
            
            default:
                return "Error";
        }
    }
}


UnitData::UnitData(UnitType type, UnitStatus status): UnitData(type, name_distinct(type), status) {}
UnitData::UnitData(UnitType type, std::string name, UnitStatus status) :unit_type(type), type_name(name), stats(status) {}

std::ostream& operator<<(std::ostream& os, const UnitData& ud) {
    os << "Unit Type : " << ud.type_name << "\n";
    os << ud.stats;
    return os;
}


const UnitData &UnitDB::get_unit_data_by_name(const std::string &name) {
    for(const auto &ud : kCharacterDB) {
        if(Utility::lowercase_string(ud.type_name) == Utility::lowercase_string(name)) {
            return ud;
        }
    }
    return kCharacterDB.back();
}


const UnitData &UnitDB::get_unit_data_by_Type(UnitType type) {
    for(const auto &ud : kCharacterDB) {
        if(ud.unit_type == type) {
            return ud;
        }
    }
    return kCharacterDB.back();
}
