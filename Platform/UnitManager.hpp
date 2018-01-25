//
//  UnitManager.hpp
//  Platform
//
//  Created by NamSangGyu on 2018. 1. 23..
//  Copyright © 2018년 NamSangGyu. All rights reserved.
//

#ifndef UnitManager_hpp
#define UnitManager_hpp

#include "Unit.hpp"
#include "UnitData.hpp"
#include "AI/AI.hpp"
#include "Equipment.hpp"
#include "Constant.h"


class UnitGenerator {
private:
    UnitGenerator();
    virtual ~UnitGenerator(){};
public:
    static UnitGenerator& GetInstance();
    UnitGenerator(UnitGenerator const&) = delete;
    void operator=(UnitGenerator const&) = delete;
    //Singleton End
    
private:
    std::string CombineName(const std::string &type_name, const std::string &ai_name, const std::string &weapon_name, const std::string &armor_name);
public:
    Unit* Generate(const UnitData &d_unit, const AI &ai, const Weapon *weapon, const Armor *armor);
protected:
    virtual Unit* GenerateUnit(std::string name, UnitStatus stats);
};

class UnitRemover {
private:
    UnitRemover();
    virtual ~UnitRemover(){};
public:
    static UnitRemover& GetInstance();
    UnitRemover(UnitRemover const&) = delete;
    void operator=(UnitRemover const&) = delete;
    //Singleton End
    
private:
    void RemoveUnit(Unit &unit);
};


class UnitManager {
private:
    UnitManager();
    virtual ~UnitManager(){};
public:
    static UnitManager& GetInstance();
    UnitManager(const UnitManager &other) = delete;
    void operator=(const UnitManager &other) = delete;
    
private:
    std::vector<Unit*> units_team_one_;
    std::vector<Unit*> units_team_two_;
public:
    //Design issue two function vs enum with one function
    bool AddUnitToTeamOne(Unit* unit);
    bool AddUnitToTeamTwo(Unit* unit);
    
    bool RemoveUnitFromTeamOne(Unit* unit);
    bool RemoveUnitFromTeamTwo(Unit* unit);
    
    //Xth start with 1
    bool RemoveXthUnitFromTeamOne(int xth);
    bool RemoveXthUnitFromTeamTwo(int xth);
    
    const std::vector<Unit*> &units_team_one() const;
    const std::vector<Unit*> &units_team_two() const;
    
    void PrintUnitsInTeamOne() const;
    void PrintUnitsInTeamTwo() const;
    
};

#endif /* UnitManager_hpp */
