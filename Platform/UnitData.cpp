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


namespace UnitDB {
    //DO NOT OVERLAP UNIT TYPE UNLESS CUSTOM
    const std::vector<UnitData> kCharacterDB = {
        // Player UnitDB
        {UNIT_WARRIOR, {20, 0, 10, 6, 3, 8, 6}},
        {UNIT_TANKER, "Tanker", {25, 0, 8, 10, 2, 10, 2}},
        {UNIT_MAGICIAN, {15, 10, 3, 4, 10, 10, 3}},
        {UNIT_HEALER, {16, 12, 5, 5, 8, 15, 4}},
        {UNIT_DARK_HEALER, "Dark Healer", {17, 11, 6, 5, 10, 13, 6}},
        
        
        // Enemy UnitDB
        {UNIT_SKELETON, {10, 0, 8, 5, 1, 0, 5}},
        {UNIT_SKELETON_MAGE, {8, 8, 6, 3, 8, 10, 5}},
        {UNIT_ORGE, {30, 0, 13, 4, 1, 3, 1}},
        
        // NO Unit
        {NO_UNIT, "NO NAME", {}}
    };
};
