#include <iostream>
#include <string>
#include <vector>

class Fighter {
private:
    std::string _name;
public:
    Fighter(const std::string& name) : _name(name) {}
    std::string GetName() const { return _name; }
};

class AbstractWeapon {
protected:
    Fighter* _fighter;
    std::string _name;
    int _damage;
public:
    AbstractWeapon(Fighter* fighter, const std::string& name, const int& damage) : _fighter(fighter), _name(name), _damage(damage) {}
    virtual void ShowInfo() const {
        std::cout << "Owner: " << _fighter->GetName() << ", Name: " << _name << ", Damage: " << _damage << " hp" << std::endl;
    }
    virtual ~AbstractWeapon() {}
};

class MeleeWeapon : public AbstractWeapon {
protected:
    int _length;
public:
    MeleeWeapon(Fighter* fighter, const std::string& name, const int& damage, int lenght) : AbstractWeapon(fighter, name, damage), _length(lenght) {}
    void ShowInfo() const override {
        std::cout << "Owner: " << _fighter->GetName() << ", Melee Weapon name: " << _name << ", Damage: " << _damage << " hp, Length: " << _length << "sm" << std::endl;
    }
};

class Sword : public MeleeWeapon {
private:

    float _handCount;
public:
    Sword(Fighter* fighter, const std::string& name, const int& damage, int lenght, float handCount) : MeleeWeapon(fighter, name, damage, lenght), _handCount(handCount) {}
    void ShowInfo() const override {
        std::cout << "Owner: " << _fighter->GetName() << ", Sword name: " << _name << ", Damage: " << _damage << " hp, Length: " << _length << " sm, HandCount: " << _handCount << std::endl;
    }
};

class RangedWeapon : public AbstractWeapon {
protected:
    int _velosity;
public:
    RangedWeapon(Fighter* fighter, const std::string& name, const int& damage, int velosity) : AbstractWeapon(fighter, name, damage), _velosity(velosity) {}
    void ShowInfo() const override {
        std::cout << "Owner: " << _fighter->GetName() << ", Ranged Weapon name: " << _name << ", Damage: " << _damage << " hp, Velosity: " << _velosity << "mph" << std::endl;
    }
};

class WisardWand : public RangedWeapon {
private:
    std::string _elemental;
public:
    WisardWand(Fighter* fighter, const std::string& name, const int& damage, int velosity, std::string elemental) : RangedWeapon(fighter, name, damage, velosity), _elemental(elemental) {}
    void ShowInfo() const override {
        std::cout << "Owner: " << _fighter->GetName() << ", Sword name: " << _name << ", Damage: " << _damage << " hp, Velosity: " << _velosity << " mph, Elemental: " << _elemental << std::endl;
    }
};


int main() {
    Fighter Arthur("Arthur");
    Fighter Gandalf("Gandalf");
    Sword Excalibur(&Arthur, "Excalibur", 999, 120, 1.5);
    WisardWand Staff(&Gandalf, "Staff", 9999, 100, "fire");
    

    Excalibur.ShowInfo();
    Staff.ShowInfo();
    return 0;
}
