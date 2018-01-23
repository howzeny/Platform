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



class UnitGenerator {
private:
    UnitGenerator();
    virtual ~UnitGenerator();
public:
    static UnitGenerator& GetInstance();
    UnitGenerator(UnitGenerator const&) = delete;
    void operator=(UnitGenerator const&) = delete;
    //Singleton End
    
private:
    
public:
    void Generate(const UnitData &d_unit);
};

class UnitRemover {
private:
    UnitRemover();
    virtual ~UnitRemover();
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
    virtual ~UnitManager();
public:
    static UnitManager& GetInstance();
    UnitManager(const UnitManager &other) = delete;
    void operator=(const UnitManager &other) = delete;
};

#endif /* UnitManager_hpp */
