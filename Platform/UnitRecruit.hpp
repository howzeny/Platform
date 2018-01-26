//
//  UnitRecruit.hpp
//  Platform
//
//  Created by NamSangGyu on 2018. 1. 24..
//  Copyright © 2018년 NamSangGyu. All rights reserved.
//

#ifndef UnitRecruit_hpp
#define UnitRecruit_hpp

#include <stdio.h>
#include <vector>
#include "Unit.hpp"

class IUnitRecruit {
    
public:
    void AddUnitsToTeamOne();
    void AddUnitsToTeamTwo();
    
private:
    virtual std::vector<Unit*> MakeUnitsForTeamOne() = 0;
    virtual std::vector<Unit*> MakeUnitsForTeamTwo() = 0;
    
};

class UnitRecruitExample :public IUnitRecruit {

private:
    virtual std::vector<Unit*> MakeUnitsForTeamOne() override;
    virtual std::vector<Unit*> MakeUnitsForTeamTwo() override;
};

#endif /* UnitRecruit_hpp */
