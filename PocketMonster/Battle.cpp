#include "Battle.h"

#include <array>

#include "PokemonName.h"


void Battle::StartMenu(std::array<PokemonName, 6>& LegendaryPokemonTeam, PokemonName& Rattata, int& currentPokemonIndex)
{
    PokemonName currentPokemon = LegendaryPokemonTeam[currentPokemonIndex];

    std::cout << "Choose between 1-4\n";
    std::cout << "1. Choose a move\n";
    std::cout << "2. Display your Pokemon stats\n";
    std::cout << "3. Display enemy stats\n";
    std::cout << "4. Exit\n";

    int choice;
    std::cin >> choice;
    system("cls");

    switch (choice)
    {
    case 1:
        PickMove(currentPokemon, Rattata);
        break;
    case 2:
        Rattata.DisplayStats();
        break;
    case 3:
        currentPokemon.DisplayStats();
        break;
    case 4:
        std::cout << "Exiting the game.\n";
        break;
    default:
        std::cout << "Invalid choice. Please try again.\n";
        StartMenu(LegendaryPokemonTeam, Rattata, currentPokemonIndex);
        break;
    }
}

void Battle::PickMove(PokemonName& currentPokemon, PokemonName& Rattata)
{
    std::cout << currentPokemon.data.name << " health: " << currentPokemon.data.health << "\n";

    int i = 1;
    auto moves = Rattata.GetMoveList();
    for (const std::string& move : moves)
    {
        std::cout << i << ". " << move << "\n";
        i++;
    }

    int moveChoice;
    std::cin >> moveChoice;
    
    switch (moveChoice)
    {
    case 1: 
        std::cout << "Rattata used " << moves[0] << "!\n";
        //TODO impelent an attack observer pattern
        AttackObserver(currentPokemon, Rattata, moves[0]);
        break;
    case 2:
        std::cout << "Rattata used " << moves[1] << "!\n";
        //TODO implement this attack first 
        break;
    case 3:
        std::cout << "Rattata used " << moves[2] << "!\n";

        std::cout << "Rattata used Double Team!\n";
        //TODO implement invisibility logic
        break;
    case 4:
        std::cout << "Rattata used " << moves[3] << "!\n";
        //Don't have to impelemt this move
    default:
        std::cout << "Invalid choice. Please try again.\n";
        PickMove(currentPokemon, Rattata);
        break;
    }
}

void Battle::AttackObserver(const PokemonName& reciever, const PokemonName& Attacker, std::string move)
{
    std::cout << Attacker.data.name << " used " << move << " on " << reciever.data.name << "!\n";
    
    std::cout << reciever.data.name << "'s health: " << reciever.data.health << "\n";

    // switch (move)
    // {
    //     case eMove::Endeavor:
    //         std::cout << reciever.data.name << " used Endeavor!\n";
    //         // Implement the logic for Endeavor move
    //         break;
    // }
}

void Battle::MoveLogic(std::string move)
{
    //Not valid
    // switch (move)
    // {
    // case "QuickAttack":
    //     std::cout << "Quick Attack used!\n";
    //     break;
    // case "DoubleTeam":
    //     std::cout << "Double Team used!\n";
    //     break;
    // case "Endeavor":
    //     std::cout << "Endeavor used!\n";
    //     break;
    // default:
    //     std::cout << move << " dealt 100 damage!\n";
    //     break;
    // }
}

void Battle::BattleLogic(PokemonName& currentPokemon, PokemonName& Rattata)
{
    int currentPokemonSpeed = currentPokemon.data.speed;
    int RattataSpeed = Rattata.data.speed;

    if (currentPokemonSpeed >= RattataSpeed)
    {
        std::cout << currentPokemon.data.name << " attacks first!\n";
        // Implement the logic for the current Pokemon's attack
    }
    else
    {
        std::cout << Rattata.data.name << " attacks first!\n";
        // Implement the logic for Rattata's attack
    }
    {
        
    }
}
