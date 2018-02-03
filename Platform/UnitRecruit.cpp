//
//  UnitRecruit.cpp
//  Platform
//
//  Created by NamSangGyu on 2018. 1. 24..
//  Copyright © 2018년 NamSangGyu. All rights reserved.
//

#include "UnitRecruit.hpp"

#include "UnitData.hpp"
#include "UnitManager.hpp"

#include "AI/AI.hpp"

void IUnitRecruit::AddUnitsToTeamOne() {
    std::vector<Unit*> units = MakeUnitsForTeamOne();
    for(auto &unit : units) {
        UnitManager::GetInstance().AddUnitToTeamOne(unit);
    }
}
void IUnitRecruit::AddUnitsToTeamTwo() {
    std::vector<Unit*> units = MakeUnitsForTeamTwo();
    for(auto &unit : units) {
        UnitManager::GetInstance().AddUnitToTeamTwo(unit);
    }
}



std::vector<Unit*> UnitRecruitExample::MakeUnitsForTeamOne() {
    //Method 1. by UNIT CODE
    UnitData warrior_data = UnitDB::get_unit_data_by_Type(UNIT_WARRIOR);
    //Method 2. by UNIT NAME
    UnitData magician_data = UnitDB::get_unit_data_by_name("magician");
    
    //Make AI for unit
    AI *ai = new AI(ai::kNoAI);
    Player player;
    AI *ai2 = new AI(ai::kPlayer);
    
    //Warrior with NO AI, NO WEAPON, NO ARMOR
    Unit *unit = UnitGenerator::GetInstance().Generate(warrior_data, ai, NULL, NULL);
    //Magician with NO AI, NO WEAPON, NO ARMOR
    Unit *unit2 = UnitGenerator::GetInstance().Generate(magician_data, ai2, NULL, NULL);
    
    std::vector<Unit*> ret;
    ret.push_back(unit);
    ret.push_back(unit2);
    
    return ret;
}

std::vector<Unit*> UnitRecruitExample::MakeUnitsForTeamTwo() {
    UnitData skeleton_data = UnitDB::get_unit_data_by_name("skeleton");
    UnitData skeleton_mage_data = UnitDB::get_unit_data_by_Type(UNIT_SKELETON_MAGE);
    
    AI *ai = new AI(ai::kNoAI);
    
    
    Unit *unit = UnitGenerator::GetInstance().Generate(skeleton_data, ai, NULL, NULL);
    Unit *unit2 = UnitGenerator::GetInstance().Generate(skeleton_mage_data);
    
    std::vector<Unit*> ret = {unit, unit2};
    return ret;
}

