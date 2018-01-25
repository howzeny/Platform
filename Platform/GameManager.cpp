//
//  GameManager.cpp
//  Platform
//
//  Created by NamSangGyu on 2018. 1. 23..
//  Copyright © 2018년 NamSangGyu. All rights reserved.
//

#include "GameManager.hpp"
#include <iostream>

GameManager::GameManager() {
    std::cout << "GameManager instance is generated , ";
    std::cout << "should be called once" << std::endl;
}

GameManager& GameManager::GetInstance() {
    static GameManager instance;
    
    return instance;
}


