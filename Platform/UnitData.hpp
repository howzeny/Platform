//
//  UnitData.hpp
//  Platform
//
//  Created by NamSangGyu on 2018. 1. 23..
//  Copyright © 2018년 NamSangGyu. All rights reserved.
//

#ifndef UnitData_hpp
#define UnitData_hpp

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "Status.hpp"

enum UnitType {
    //Player
    UNIT_WARRIOR,
    UNIT_TANKER,
    UNIT_MAGICIAN,
    UNIT_HEALER,
    UNIT_DARK_HEALER,
    
    //Enemy
    UNIT_SKELETON,
    UNIT_SKELETON_MAGE,
    UNIT_ORGE,
    
    //Will be added
    //CUSTOM_TYPE,
    
    NO_UNIT,
};

struct UnitData {
    UnitType unit_type;
    std::string type_name;
    UnitStatus stats;
    
    //Appearance
    
    UnitData(){}
    virtual ~UnitData(){}
    UnitData(UnitType type, UnitStatus stats);
    UnitData(UnitType type, std::string name, UnitStatus stats);
    friend std::ostream& operator<<(std::ostream &os, const UnitData &ud);
};



//type, {hp mp atk def int res spd}
namespace UnitDB{
    
    const UnitData &get_unit_data_by_name(const std::string &name);
    const UnitData &get_unit_data_by_Type(UnitType type);
    //maybe will be added find type in custom
    
    
    //DO NOT OVERLAP UNIT TYPE UNLESS CUSTOM
    const std::vector<UnitData> kCharacterDB = {
        // Player UnitDB
        {UNIT_WARRIOR, {20, 0, 10, 6, 3, 8, 5}},
        {UNIT_TANKER, "Tanker", {25, 0, 8, 10, 2, 10, 2}},
        {UNIT_MAGICIAN, {15, 10, 3, 4, 10, 10, 4}},
        {UNIT_HEALER, {16, 12, 5, 5, 8, 15, 4}},
        {UNIT_DARK_HEALER, "Dark Healer", {17, 11, 6, 5, 10, 13, 6}},
        
       
        // Enemy UnitDB
        {UNIT_SKELETON, {10, 0, 8, 5, 1, 0, 4}},
        {UNIT_SKELETON_MAGE, {8, 8, 6, 3, 8, 10, 5}},
        {UNIT_ORGE, {30, 0, 13, 4, 1, 3, 1}},
        
        // NO Unit
        {NO_UNIT, "NO NAME", {}}
    };
    
    /*
    const std::vector<UnitData> character_database = {
        {UNIT_WARRIOR, {20, 0, 10, 6, 3, 8, 5}},
        {UNIT_MAGICIAN, {15, 10, 3, 4, 10, 10, 4}},
        {UNIT_HEALER, {16, 12, 5, 5, 8, 15, 4}}
    };
    
    const std::vector<UnitData> enemy_database = {
        {UNIT_SKELETON, {10, 0, 8, 5, 1, 0, 4}},
        {UNIT_SKELETON_MAGE, {8, 8, 6, 3, 8, 10, 5}},
        {UNIT_ORGE, {30, 0, 13, 4, 1, 3, 1}},
        
    };
     */
};
    
    
#endif /* UnitData_hpp */
