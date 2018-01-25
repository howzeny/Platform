//
//  Equipment.hpp
//  Platform
//
//  Created by NamSangGyu on 2018. 1. 23..
//  Copyright © 2018년 NamSangGyu. All rights reserved.
//

#ifndef Equipment_hpp
#define Equipment_hpp

#include <string>
#include <iostream>
#include "Status.hpp"

class EquipAttr {

private:
    std::string name_;
    EquipStatus stats_;
    
public:
    const std::string &name() const;
};

class Weapon{
private:
    EquipAttr &eq_attr;
public:
    Weapon(EquipAttr &wrapper) : eq_attr(wrapper) {}
    const std::string name() const;
};

class Armor{
private:
    EquipAttr &eq_attr;
public:
    Armor(EquipAttr &wrapper) : eq_attr(wrapper) {}
    virtual const std::string name() const;
};

#endif /* Equipment_hpp */
