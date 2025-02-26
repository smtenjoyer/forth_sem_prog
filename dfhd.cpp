#include <iostream>
#include <string>
#include <vector>

class Vehicle {
protected:
    std::string Brand;
public:
    Vehicle(const std::string& brand) : Brand(brand) {}
    virtual void ShowInfo() const {
        std::cout << "Brand: " << Brand << std::endl;
    }
    virtual ~Vehicle() {}
};

class LandVehicle : public Vehicle {
protected:
    int Wheels;
public:
    LandVehicle(const std::string& brand, int wheels) : Vehicle(brand), Wheels(wheels) {}
    void ShowInfo() const override {
        std::cout << "Land Vehicle Brand: " << Brand << ", Wheels: " << Wheels << std::endl;
    }
};

class Tank : public LandVehicle {
private:
    int Armor;
public:
    Tank(const std::string& brand, int wheels, int armor) : LandVehicle(brand, wheels), Armor(armor) {}
    void ShowInfo() const override {
        std::cout << "Tank Brand: " << Brand << ", Wheels: " << Wheels << ", Armor: " << Armor << " mm" << std::endl;
    }
};

class Pilot {
private:
    std::string Name;
public:
    Pilot(const std::string& name) : Name(name) {}
    std::string GetName() const { return Name; }
};

class Aircraft : public Vehicle {
private:
    Pilot* _Pilot;
    int MaxAltitude;
public:
    Aircraft(const std::string& brand, int maxAltitude, Pilot* pilot) : Vehicle(brand), MaxAltitude(maxAltitude), _Pilot(pilot) {}
    void ShowInfo() const override {
        std::cout << "Aircraft Brand: " << Brand << ", Max Altitude: " << MaxAltitude << " meters, Pilot: " << _Pilot->GetName() << std::endl;
    }
};

int main() {
    Vehicle car("Toyota");
    Tank t34("T-34", 4, 45);
    Pilot john("John Doe");
    Aircraft jet("F-16", 15000, &john);

    car.ShowInfo();
    t34.ShowInfo();
    jet.ShowInfo();
    return 0;
}
