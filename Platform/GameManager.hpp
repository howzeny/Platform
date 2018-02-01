//
//  GameManager.hpp
//  Platform
//
//  Created by NamSangGyu on 2018. 1. 23..
//  Copyright © 2018년 NamSangGyu. All rights reserved.
//

#ifndef GameManager_hpp
#define GameManager_hpp

#include <iostream>
#include <string>

#include "UnitRecruit.hpp"


class GameManager {
    
public:
    enum PhaseTurn {
        TEAM_ONE = 0,
        TEAM_TWO,
    };
    bool Initialize(IUnitRecruit &recruiter);
    
    void ShowUnitsInEachTeam() const ;
    
    //yet
    void InitBattleManager();
    
    void BattleStart();
    
    
private:
    
    int turn_num_;
    PhaseTurn phase_;
    
    
//Singleton
private:
    GameManager();
    virtual ~GameManager();
    
public:
    static GameManager& GetInstance();
    
    GameManager(GameManager const&) = delete;
    void operator=(GameManager const&) = delete;
    //Singleton End
};




#endif /* GameManager_hpp */
