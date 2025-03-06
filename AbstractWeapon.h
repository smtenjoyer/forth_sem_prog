#ifndef ABSTRACTWEAPON_H
#define ABSTRACTWEAPON_H
#include <iostream>
#include <string>
#include <vector>

class AbstractWeapon {
protected:
    std::string _name;
    int _damage;
public:
    AbstractWeapon(std::string& name, const int& damage) : _name(name), _damage(damage) {}
    virtual void ShowInfo() const {
        std::cout << "Name: " << _name << ", Damage: " << _damage << " hp" << std::endl;
    }
    virtual int GetDamage() const { return _damage; } 
    virtual ~AbstractWeapon() {}
    virtual std::string GetName() const { return _name; } 
    virtual std::string GetType() const = 0;
};

#endif