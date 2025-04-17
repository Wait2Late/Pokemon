#include "Battle.h"

#include <array>
#include <map>

#include "PokemonName.h"


void Battle::StartMenu(std::array<PokemonName, 6>& LegendaryPokemonTeam, PokemonName& Rattata, int& currentPokemonIndex)
{
    PokemonName currentPokemon = LegendaryPokemonTeam[currentPokemonIndex];

    while (currentPokemon.getIsAlive())
    {
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
}

void Battle::PickMove(PokemonName& currentPokemon, PokemonName& Rattata)
{
    std::cout << currentPokemon.GetName() << " health: " << currentPokemon.GetHealth() << "\n";

    int i = 1;
    auto rattataMoves = Rattata.GetMoveList();
    for (const std::string& move : rattataMoves)
    {
        std::cout << i++ << ". " << move << "\n";
    }

    int moveChoice = 0;
    std::cin >> moveChoice;
    moveChoice--;

    system("cls");
    int enemyMoveChoice = rand() % currentPokemon.GetMoveList().size() + 1;
    // auto allPokemon = std::array<PokemonName, 2> { currentPokemon, Rattata };
    // for (const auto& move : allPokemon)
    // {
    //     //Check if the array has "QuickAttack" in it
    //     if (std::find(move.GetMoveList().begin(), move.GetMoveList().end(), "QuickAttack") != move.GetMoveList().end())
    //     {
    //         //Has "QuickAttack"
    //     }
    // }

    if (rattataMoves[moveChoice] == "QuickAttack")
    {
        Rattata.SetPriority(true);
    }

    if (currentPokemon.GetSpeed() >= Rattata.GetSpeed())
    {
        if (Rattata.GetPriority())
        {
            DamageLogic(currentPokemon, Rattata, moveChoice);
        }

        DamageLogic(Rattata, currentPokemon, enemyMoveChoice);

        if (!Rattata.GetPriority())
        {
            DamageLogic(currentPokemon, Rattata, moveChoice);
        }
    }
}


void Battle::BattleLogic(PokemonName& currentPokemon, PokemonName& Rattata)
{
    int currentPokemonSpeed = currentPokemon.GetSpeed();
    int RattataSpeed = Rattata.GetSpeed();

    if (currentPokemonSpeed >= RattataSpeed)
    {
        std::cout << currentPokemon.GetName() << " attacks first!\n";
        // Implement the logic for the current Pokemon's attack
    }
    else
    {
        std::cout << Rattata.GetName() << " attacks first!\n";
        // Implement the logic for Rattata's attack
    }
    {
        
    }
}

void Battle::DamageLogic(PokemonName& reciever, PokemonName& attacker, int moveChoice)
{
    if (!attacker.getIsAlive())
    {
        return;
    }
    
    int damageDiff = 0;
    std::string attackerMove = attacker.GetMoveList()[moveChoice];
    
    std::cout << attacker.GetName() << " used " << attackerMove << "!\n";

    if (attackerMove == "QuickAttack")
    {
        //Redo the damage logic if the move does not bypass the defense, then the damage need to be only 1
        damageDiff = reciever.GetDefense() - (attacker.GetAttack() + 10);

    }
    else if (attackerMove == "DoubleTeam")
    {
        damageDiff = reciever.GetDefense() - (attacker.GetAttack() + 10);
    }
    else if (attackerMove == "Endeavor")
    {
        damageDiff = reciever.GetDefense() - (attacker.GetAttack() + 10);
    }
    else
    {
        damageDiff = reciever.GetDefense() - (attacker.GetAttack() + 100);
    }
    
    
    if (damageDiff <= 0)
    {
        damageDiff++;
    }
    
    reciever.SetHealth(reciever.GetHealth() - damageDiff);
    std::cout << reciever.GetName() << " took " << damageDiff << " damage!\n";

    std::cout << reciever.GetName() << " has " << reciever.GetHealth() << " health left!\n";
    if (reciever.GetHealth() <= 0)
    {
        std::cout << reciever.GetName() << " fainted!\n";
        reciever.SetAlive(false);
    }
}
