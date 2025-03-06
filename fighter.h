#ifndef FIGHTER_H
#define FIGHTER_H
#include "AbstractWeapon.h"
#include <iostream>
#include <string>
#include <vector>

class Fighter {
private:
    const std::string _name;
    int _health = 1000;
    AbstractWeapon* _equippedWeapon = nullptr; 
public:
    ~Fighter() {delete _equippedWeapon; }
    Fighter(const std::string& name) : _name(name) {}
    std::string GetName() const { return _name; }
    int GetHealth() const {return _health;}
    void SetHealth(int health) {_health = health;}

    void EquipWeapon(AbstractWeapon* someWeapon)
    {
        if (_equippedWeapon) {
            std::cout << _name << " unequipped " << _equippedWeapon->GetName() << ". ";
            delete _equippedWeapon;
        }
        _equippedWeapon = someWeapon;
        std::cout  << _name <<  " equipped " << someWeapon->GetName() << "." << std::endl;
    }
    
    void TakeDamage(int damage) {
        _health -= damage;
        std::cout << _name << " takes " << damage << " damage!  Health: " << _health << std::endl;
    }

    void Attack(Fighter* target) {
        if (_health <=0){
            std::cout << _name << " is dead!" << std::endl;
        }
        if (_equippedWeapon) {
            std::cout << _name << " attacks " << target->GetName() << " with " << _equippedWeapon->GetName() << " for " << _equippedWeapon->GetDamage() << " damage!" << std::endl;
            target->TakeDamage(_equippedWeapon->GetDamage());
        } else {
            std::cout << _name << " attacks " << target->GetName() << " with bare hands!" << std::endl;
            target->TakeDamage(10);
        }
    }
};


#endif