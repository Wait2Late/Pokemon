#include "Battle.h"

#include <array>
#include <map>
#include <random>

#include "PokemonName.h"


void Battle::StartMenu(std::array<PokemonName, 6>& LegendaryPokemonTeam, PokemonName& Rattata, int& currentPokemonIndex)
{
    PokemonName currentPokemon = LegendaryPokemonTeam[currentPokemonIndex];

    while (currentPokemon.getIsAlive() && Rattata.getIsAlive())
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

    Rattata.SetPriority(false);
    
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
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, currentPokemon.GetMoveList().size() - 1);
    int enemyMoveChoice = dis(gen);
    
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

void Battle::DamageLogic(PokemonName& reciever, PokemonName& attacker, int moveChoice)
{
    if (!attacker.getIsAlive())
    {
        return;
    }
    
    int damageDealt = 0;
    std::string attackerMove = attacker.GetMoveList()[moveChoice];
    
    std::cout << attacker.GetName() << " used " << attackerMove << "!\n";

    if (attackerMove == "QuickAttack")
    {
        damageDealt = reciever.GetDefense() - (attacker.GetAttack() + 10);
    }
    else if (attackerMove == "DoubleTeam")
    {
        std::cout << attacker.GetName() << " increased its evasion!\n";
        attacker.SetHitAccuracy(200);
    }
    else if (attackerMove == "Endeavor")
    {
        if (reciever.GetHealth() > 1)
        {
            reciever.SetHealth(attacker.GetHealth());
        }
        else
        {
            damageDealt = reciever.GetDefense() - (attacker.GetAttack() + 10);
        }
    }
    else
    {
        damageDealt = reciever.GetDefense() - (attacker.GetAttack() + 100);
    }

    if (reciever.GetDefense() > attacker.GetAttack() && attackerMove != "Endeavor" && attackerMove != "DoubleTeam")
    {
        damageDealt = 1;
    }
    else if (damageDealt < 0)
    {
        damageDealt = -damageDealt;
    }

    if (reciever.GetHitAccuracy() > 100)
    {
        std::cout << reciever.GetName() << " dodged the attack!\n";
    }
    else
    {
        reciever.SetHealth(reciever.GetHealth() - damageDealt);
    }

    if (attackerMove != "Endeavor" && reciever.GetHitAccuracy() <= 100)
    {
        std::cout << reciever.GetName() << " took " << damageDealt << " damage!\n";
    }
    std::cout << reciever.GetName() << " has " << reciever.GetHealth() << " health left!\n";

    if (reciever.GetHeldItem() == "FocusSash")
    {
        if (reciever.GetHealth() <= 1)
        {
            reciever.SetHealth(1);
            std::cout << reciever.GetName() << " survived with 1 health left! Focus sash broke down!\n";
            reciever.SetHeldItem("");
        }
    }
    else if (reciever.GetHealth() <= 0)
    {
        std::cout << reciever.GetName() << " fainted!\n";
        reciever.SetAlive(false);
    }
}
