#ifndef VERSUS_H
#define VERSUS_H
#include "WeaponFActory.h"
#include <ctime> 
#include "logger.h"

void createAvatarLog(Logger* ConsoleLogger, Logger* FileLogger){
    ConsoleLogger->log("Avatar was created\n");
    FileLogger->log("Avatar was created");
}
void createEnemyLog(Logger* ConsoleLogger, Logger* FileLogger){
    ConsoleLogger->log("Enemy was created\n");
    FileLogger->log("Enemy was created");
}

class Game{
    public:
        ~Game() {};
        
        Fighter CreateAvatar(){

            LoggerFactory LogFac;
            Logger* ConsoleLogger = LogFac.CreateLogger(1);
            Logger* FileLogger = LogFac.CreateLogger(2, "D:/Programming/projects/TECH/3lab/log.txt");
            ConsoleLogger->log("Game started!\n");
            FileLogger->log("Game started!");

            std::cout << "First of all you have to create your avatar. Chose a name: " << std::endl;
            std::string new_name;
            std::cin >> new_name;

            Fighter new_fighter(new_name);

            std::cout << "Good. Are you melee or ranged user? " << std::endl;
            std::string weapon_choice;
            
            while(weapon_choice != "melee" || weapon_choice != "ranged"){
            std::cin >> weapon_choice;
            if (weapon_choice == "melee")
            {
                std::cout << "You are a sword user now. Chose a name for your sword: " << std::endl;
                std::string weapon_name_choice;
                std::cin >> weapon_name_choice;
                std::cout << "What type of sword is that: onehanded or twohanded? " << std::endl;
                std::string handed_choice;
                std::cin >> handed_choice;
                
                if (handed_choice == "onehanded")
                {
                    AbstractWeapon* new_sword = WeaponFactory::CreateWeapon("Sword", weapon_name_choice, 100, 100, 1.0f);
                    new_fighter.EquipWeapon(new_sword);
                    std::cout << "Your name is "<< new_name << " with " << weapon_name_choice << " in your hands and you are ready to fight." << std::endl;
                    createAvatarLog(ConsoleLogger, FileLogger);
                    return new_fighter;
                }
                else if (weapon_choice == "twohanded"){
                    AbstractWeapon* new_sword = WeaponFactory::CreateWeapon("Sword", weapon_name_choice, 150, 160, 2.0f);
                    new_fighter.EquipWeapon(new_sword);
                    std::cout << "Your name is "<< new_name << " with " << weapon_name_choice << " in your hands and you are ready to fight." << std::endl;
                    createAvatarLog(ConsoleLogger, FileLogger);
                    return new_fighter;
                }
                else{
                    AbstractWeapon* new_sword = WeaponFactory::CreateWeapon("Sword", weapon_name_choice, 130, 120, 1.5f);
                    new_fighter.EquipWeapon(new_sword);
                    std::cout << "Your name is "<< new_name << " with 1.5 handed sword " << weapon_name_choice << " in your hands and you are ready to fight." << std::endl;
                    createAvatarLog(ConsoleLogger, FileLogger);
                    return new_fighter;
                }
            }
            else if (weapon_choice == "ranged"){
                std::cout << "You are a wisard now. Chose a name for your wand: " << std::endl;
                std::string weapon_name_choice;
                std::cin >> weapon_name_choice;
                std::cout << "What kind of magic do you use? " << std::endl;
                std::string magic_choise;
                std::cin >> magic_choise;
                AbstractWeapon* new_sword = WeaponFactory::CreateWeapon("WisardWand", weapon_name_choice, 200, 50, 0.0f, magic_choise);
                    new_fighter.EquipWeapon(new_sword);
                    std::cout << "Your name is "<< new_name << " with " << weapon_name_choice << " in your hands shoting " << magic_choise << " in everyone you see and you are ready to fight." << std::endl;
                    return new_fighter;
            }
            else{
                weapon_choice = "";
                std::cout << "What? Think again" << std::endl;
            }
        }
    }
    
    Fighter* CreateEnemy() {

        LoggerFactory LogFac;
        Logger* ConsoleLogger = LogFac.CreateLogger(1);
        Logger* FileLogger = LogFac.CreateLogger(2, "D:/Programming/projects/TECH/3lab/log.txt");

        std::cout << "Now you chose who to fight: Arthur, Gandalf, Voldemort" << std::endl;
        std::string enemy_choice;
        
        while(enemy_choice != "Arthur" || enemy_choice != "Gandalf" || enemy_choice != "Voldemort"){
            std::cin >> enemy_choice;
        if (enemy_choice == "Arthur") {
            Fighter* arthur = new Fighter("Arthur"); 
            std::string weapon_name_choice = "Excalibur";
            AbstractWeapon* excalibur = WeaponFactory::CreateWeapon("Sword", weapon_name_choice, 300, 120, 1.5f);
            arthur->EquipWeapon(excalibur); 
            createEnemyLog(ConsoleLogger, FileLogger);
            return arthur;
        }
        else if (enemy_choice == "Gandalf") {
            Fighter* gandalf = new Fighter("Gandalf"); 
            std::string weapon_name_choice = "Staff";
            AbstractWeapon* staff = WeaponFactory::CreateWeapon("WisardWand", weapon_name_choice, 301, 100, 0.0f, "fire");
            gandalf->EquipWeapon(staff); 
            createEnemyLog(ConsoleLogger, FileLogger);
            return gandalf;
        }
        else if (enemy_choice == "Voldemort") {
            Fighter* voldemort = new Fighter("Voldemort"); 
            std::string weapon_name_choice = "Yew Wand";
            AbstractWeapon* Yew_Wand = WeaponFactory::CreateWeapon("WisardWand", weapon_name_choice, 302, 100, 0.0f, "Curse");
            voldemort->EquipWeapon(Yew_Wand); 
            createEnemyLog(ConsoleLogger, FileLogger);
            return voldemort;
        }
        else {
            std::cout << "What? Think again" << std::endl;
            enemy_choice = "";
        }
    }
    }

    void Duel(Fighter& player, Fighter& enemy) {
        LoggerFactory LogFac;
        Logger* ConsoleLogger = LogFac.CreateLogger(1);
        Logger* FileLogger = LogFac.CreateLogger(2, "D:/Programming/projects/TECH/3lab/log.txt");
        ConsoleLogger->log("\nGame processing...\n");
        FileLogger->log("Game processing...");
        char action;
        srand(time(0)); 
        
        std::cout << "\n--- Duel: " << player.GetName() << " vs. " << enemy.GetName() << " ---" << std::endl;
        while (player.GetHealth() > 0 && enemy.GetHealth() > 0) {
            std::cout << std::endl;
            std::cout << player.GetName() << " Health: " << player.GetHealth() << std::endl;
            std::cout << enemy.GetName() << " Health: " << enemy.GetHealth() << std::endl;

            std::cout << "Press 'F' to attack: ";
            std::cin >> action;

            if (action == 'F' || action == 'f') {
                player.Attack(&enemy);

                if (enemy.GetHealth() <= 0) {
                    std::cout << "\n" << enemy.GetName() << " has been defeated!" << std::endl;
                    break;
                }

                // Ход врага (бота) - случайная атака
                // Враг атакует с определенной вероятностью (например, 70%)
                if (rand() % 100 < 70) {
                    enemy.Attack(&player);

                    if (player.GetHealth() <= 0) {
                        std::cout << "\n" << player.GetName() << " has been defeated!" << std::endl;
                        break;
                    }
                }
                else {
                    std::cout << enemy.GetName() << " misses!" << std::endl;
                }

            }
            else {
                std::cout << "Invalid action." << std::endl;
            }
        }

        if (player.GetHealth() <= 0) {
            std::cout << "\nYou lost the duel!" << std::endl;
            ConsoleLogger->log("\nGame was ended. You lost the duel!");
            FileLogger->log("Game was ended. You lost the duel!");
        }
        else {
            std::cout << "\nYou won the duel!" << std::endl;
            ConsoleLogger->log("\nGame was ended. You won the duel!");
            FileLogger->log("Game was ended. You won the duel!");
        }
    }
};
#endif