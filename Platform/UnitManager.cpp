//
//  UnitManager.cpp
//  Platform
//
//  Created by NamSangGyu on 2018. 1. 23..
//  Copyright © 2018년 NamSangGyu. All rights reserved.
//

#include "UnitManager.hpp"
#include "Status.hpp"

//////////////////////////////////////
///////////UNIT GENERATOR/////////////
//////////////////////////////////////

UnitGenerator::UnitGenerator() {
    std::cout << "UnitGenerator is initialized" << std::endl << std::endl;
}

UnitGenerator &UnitGenerator::GetInstance() {
    static UnitGenerator instance;
    
    return instance;
}


std::string UnitGenerator::CombineName(const std::string &type_name, const std::string &ai_name, const std::string &weapon_name, const std::string &armor_name) {
    std::string ret = type_name +" " + ai_name + " wearing [" + weapon_name +", " + armor_name +"]";
    return ret;
}

//generate unit name from equipment, type_name, ai_type
Unit* UnitGenerator::Generate(const UnitData &d_unit, const AI *ai, const Weapon *weapon, const Armor *armor) {
    UnitStatus stats = d_unit.stats;
    std::string weapon_name = "None";
    std::string armor_name = "None";
    std::string ai_name = "None AI";
    
    if(weapon != NULL)
        weapon_name = weapon->name();
    if(armor != NULL)
        armor_name = armor->name();
    if(ai != NULL)
        ai_name = ai->ai_name();
    
    std::string name = CombineName(d_unit.type_name, ai_name,
                                   weapon_name, armor_name);
    
    Unit *generated_unit = GenerateUnit(name, stats, ai, weapon, armor);
    
    return generated_unit;
}

Unit* UnitGenerator::Generate(const UnitData &d_unit) {
    return Generate(d_unit, NULL, NULL, NULL);
}

Unit* UnitGenerator::GenerateUnit(std::string name, UnitStatus stats, const AI *ai, const Weapon *weapon, const Armor *armor) {
    return new Unit(name, stats, ai, weapon, armor);
}

//////////////////////////////////////
////////////UNIT REMOVER//////////////
//////////////////////////////////////






//////////////////////////////////////
////////////UNIT MANAGER//////////////
//////////////////////////////////////

namespace {
    enum TeamNumber {
        ONE,
        TWO
    };
    
    bool AddUnitToTeam(Unit* unit, std::vector<Unit*> &team) {
        if(unit != NULL) {
            team.push_back(unit);
            return true;
        }
        return false;
    }
    
    //need to verify
    bool RemoveUnitFromTeam(Unit* unit, std::vector<Unit*> &team) {
        std::vector<Unit*>::iterator iter;
        for(iter = team.begin(); iter != team.end(); iter++) {
            if((*iter) == unit) {
                team.erase(iter);
                return true;
            }
        }
        return false;
    }
    
    bool RemoveXthUnitFromTeam(int xth, std::vector<Unit*> &team) {
        if(xth > team.size() || xth < 0)
            return false; // out of index
        std::vector<Unit*>::iterator iter = team.begin();
        for(int i = 1; i < xth; i++)
            iter++;
        team.erase(iter);
        return true;
        
    }
    
    void PrintUnitsInTeam(const std::vector<Unit*> &team){
        int num = 1;
        if(team.size() == 0) {
            std::cout << "Team have no member" << std::endl;
        }
        for(const auto &unit : team) {
            std::cout << "[" << num << "th unit]" << std::endl;
            std::cout << unit << std::endl;
            num++;
        }
    }
    
} // End of unnamed namespace


UnitManager::UnitManager() {
    std::cout << "UnitManager is initialized" << std::endl << std::endl;
}

UnitManager &UnitManager::GetInstance() {
    static UnitManager instance;
    
    return instance;
}

bool UnitManager::AddUnitToTeamOne(Unit *unit) {
    return AddUnitToTeam(unit, units_team_one_);
}

bool UnitManager::AddUnitToTeamTwo(Unit *unit) {
    return AddUnitToTeam(unit, units_team_two_);
}

bool UnitManager::RemoveUnitFromTeamOne(Unit *unit) {
    return RemoveUnitFromTeam(unit, units_team_one_);
}
bool UnitManager::RemoveUnitFromTeamTwo(Unit *unit) {
    return RemoveUnitFromTeam(unit, units_team_two_);
}

bool UnitManager::RemoveXthUnitFromTeamOne(int xth) {
    return RemoveXthUnitFromTeam(xth, units_team_one_);
}
bool UnitManager::RemoveXthUnitFromTeamTwo(int xth) {
    return RemoveXthUnitFromTeam(xth, units_team_two_);
}


const std::vector<Unit*> &UnitManager::units_team_one() const {
    return units_team_one_;
}
const std::vector<Unit*> &UnitManager::units_team_two() const {
    return units_team_two_;
}

void UnitManager::PrintUnitsInTeamOne() const {
    std::cout<< "##Team1##" << std::endl;
    PrintUnitsInTeam(units_team_one_);
}
void UnitManager::PrintUnitsInTeamTwo() const {
    std::cout<< "##Team2##" << std::endl;
    PrintUnitsInTeam(units_team_two_);
}




