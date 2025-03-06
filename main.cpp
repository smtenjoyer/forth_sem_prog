#include "Versus.h"



int main() {
    std::cout << "This is a breathtaking pvp game where you can fight against the most powerful heroes and villains of all times!" << std::endl;
    std::cout << "Do you want to try?" << std::endl;

    std::string input = "";
    std::cin >> input;
    if (input == "yes" || input == "Yes")
    {   
        
        Game new_game;
        Fighter Player = new_game.CreateAvatar();
        
        Fighter* Enemy = new_game.CreateEnemy(); 
        
        
        new_game.Duel(Player, *Enemy);
        
        
    }
    else if (input == "no" || input == "No"){
        std::cout << "Then so be it." << std::endl;
    }
    else{
        std::cout << "What? Come back when you learn to talk." << std::endl;
    }
    return 0;
}
