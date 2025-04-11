#ifndef WEAPONFACTORY_H
#define WEAPONFACTORY_H
#pragma once
#include "Weapon.h"
#include "Fighter.h"

class WeaponFactory {
public:
    static AbstractWeapon* CreateWeapon(const std::string& type,  std::string& name,
                                        int damage, int arg1 = 0, float arg2 = 0.0f, const std::string& arg3 = "") {
        if (type == "Sword") {
            return new Sword(name, damage, arg1, arg2);
        } else if (type == "WisardWand") {
            return new WisardWand(name, damage, arg1, arg3);
        } else if (type == "MeleeWeapon") {
            return new MeleeWeapon(name, damage, arg1);
        } else if (type == "RangedWeapon") {
            return new RangedWeapon(name, damage, arg1);
        } else {
            std::cerr << "Unknown weapon type: " << type << std::endl;
            return nullptr;
        }
    }
};

#endif
