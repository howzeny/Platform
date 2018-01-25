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

class IUnitRecruit {
    
public:
    virtual void RecruitOneTeam() = 0;
    virtual void RecruitTwoTeam() = 0;
};

class UnitRecruitExample : IUnitRecruit {

public:
    virtual void RecruitOneTeam() override;
    virtual void RecruitTwoTeam() override;
};

#endif /* UnitRecruit_hpp */
