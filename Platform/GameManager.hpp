//
//  GameManager.hpp
//  Platform
//
//  Created by NamSangGyu on 2018. 1. 23..
//  Copyright © 2018년 NamSangGyu. All rights reserved.
//

#ifndef GameManager_hpp
#define GameManager_hpp

class GameManager {
    //Singleton
private:
    GameManager();
    virtual ~GameManager() {}
 
public:
    static GameManager& GetInstance();
    
    GameManager(GameManager const&) = delete;
    void operator=(GameManager const&) = delete;
//Singleton End
    
    private:
    
    public:
    
};





#endif /* GameManager_hpp */
