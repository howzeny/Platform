//
//  Equipment.cpp
//  Platform
//
//  Created by NamSangGyu on 2018. 1. 23..
//  Copyright © 2018년 NamSangGyu. All rights reserved.
//

#include "Equipment.hpp"

const std::string &EquipAttr::name() const {
    return name_;
}

const std::string Weapon::name() const {
    return "weapon-" + eq_attr.name();
}

const std::string Armor::name() const {
    return "armor-" + eq_attr.name();
}
