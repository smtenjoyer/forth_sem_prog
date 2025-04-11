#ifndef WEAPON_H
#define WEAPON_H
#pragma once
#include "AbstractWeapon.h"

class MeleeWeapon : public AbstractWeapon {
protected:
    int _length;
public:
    MeleeWeapon( std::string& name, const int& damage, int lenght) : AbstractWeapon(name, damage), _length(lenght) {}
    void ShowInfo() const override {
        std::cout << "Melee Weapon name: " << _name << ", Damage: " << _damage << " hp, Length: " << _length << "sm" << std::endl;
    }
    virtual std::string GetType() const override {return "Melee";}
};

class Sword : public MeleeWeapon {
private:
    float _handCount;
public:
    Sword( std::string& name, const int& damage, int lenght, float handCount) : MeleeWeapon(name, damage, lenght), _handCount(handCount) {}
    void ShowInfo() const override {
        std::cout << "Sword name: " << _name << ", Damage: " << _damage << " hp, Length: " << _length << " sm, HandCount: " << _handCount << std::endl;
    }
    virtual std::string GetType() const override {return "Sword";}
};

class RangedWeapon : public AbstractWeapon {
protected:
    int _velosity;
public:
    RangedWeapon( std::string& name, const int& damage, int velosity) : AbstractWeapon(name, damage), _velosity(velosity) {}
    void ShowInfo() const override {
        std::cout << "Ranged Weapon name: " << _name << ", Damage: " << _damage << " hp, Velosity: " << _velosity << "mph" << std::endl;
    }
    virtual std::string GetType() const override {return "Ranged";}
};

class WisardWand : public RangedWeapon {
private:
    std::string _elemental;
public:
    WisardWand( std::string& name, const int& damage, int velosity, const std::string& elemental) : RangedWeapon(name, damage, velosity), _elemental(elemental) {}
    void ShowInfo() const override {
        std::cout << "Sword name: " << _name << ", Damage: " << _damage << " hp, Velosity: " << _velosity << " mph, Elemental: " << _elemental << std::endl;
    }
    virtual std::string GetType() const override {return "Wisard Wand";}
};

#endif
