#include "Battle.h"

#include <array>

#include "PokemonName.h"

void Battle::StartMenu(std::array<PokemonName, 6>& LegendaryPokemonTeam, PokemonName& Rattata, int& currentPokemonIndex)
{
    PokemonName currentPokemon = LegendaryPokemonTeam[currentPokemonIndex];

    std::cout << "Choose between 1-4\n";
    std::cout << "1. Choose a move\n";
    std::cout << "2. Display enemy stats\n";
    std::cout << "3. Exit\n";

    int choice;
    std::cin >> choice;
    system("cls");

    switch (choice)
    {
    case 1:
        MoveList(currentPokemon, Rattata);
        break;
    case 2:
        currentPokemon.DisplayStats();
        break;
    case 3:
        std::cout << "Exiting the game.\n";
        break;
    default:
        std::cout << "Invalid choice. Please try again.\n";
        StartMenu(LegendaryPokemonTeam, Rattata, currentPokemonIndex);
        break;
    }
}

void Battle::MoveList(PokemonName& currentPokemon, PokemonName& Rattata)
{
    std::cout << "1.Endeavor\n";
    std::cout << "2.Quick Attack\n";
    std::cout << "3.Double Team\n";

    int moveChoice;
    std::cin >> moveChoice;
    
    switch (moveChoice)
    {
    case 1: 
        std::cout << "Rattata used Endeavor!\n";
        //TODO impelent an attack observer pattern
        AttackObserver(currentPokemon, Rattata, eMove::Endeavor);
        break;
    case 2:
        std::cout << "Rattata used Quick Attack!\n";
        //TODO implement this attack first 
        break;
    case 3:
        std::cout << "Rattata used Double Team!\n";
        //TODO implement invisibility logic
        break;
    default:
        std::cout << "Invalid choice. Please try again.\n";
        MoveList(currentPokemon, Rattata);
        break;
    }
}

void Battle::AttackObserver(const PokemonName& reciever, const PokemonName& Attacker, eMove move)
{
    int health = reciever.data.health;
    std::cout << reciever.data.name << "'s health: " << health << "\n";

    switch (move)
    {
        case eMove::Endeavor:
            std::cout << reciever.data.name << " used Endeavor!\n";
            // Implement the logic for Endeavor move
            break;
    }
}
