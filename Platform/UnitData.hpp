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
    UnitData(UnitType type, UnitStatus stats);
    UnitData(UnitType type, std::string name, UnitStatus stats);
    friend std::ostream& operator<<(std::ostream &os, const UnitData &ud);
};



//type, {hp mp atk def int res spd}
namespace UnitDB{
    
    const UnitData &get_unit_data_by_name(const std::string &name);
    const UnitData &get_unit_data_by_Type(UnitType type);
    //maybe will be added find type in custom
    
    extern const std::vector<UnitData> kCharacterDB ;

};
    
    
#endif /* UnitData_hpp */
