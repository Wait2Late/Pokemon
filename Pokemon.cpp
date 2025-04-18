// Pokemon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <array>
#include <iostream>

#include "PocketMonster/Battle.h"
#include "PocketMonster/PokemonName.h"

std::array<PokemonName, 6> CreateLegendaryPokemonTeam();

int main()
{
    std::cout << "Hello and welcome to Pokemon battle!\n";
    std::cout << "This is a simple Pokemon battle simulation.\n";
    std::cout << "You will play as Jimmy, the little boy from Route 1. Who anticipate to meet the Legendary Pokemon trainer\n";
    std::cout << "Jimmy only has one Pokemon at level 1. While the Legendary Pokemon Trainer has six of level 100\n";
    std::cout << "As you can imagine those Pokemon are also legendary\n\n";

    std::array<PokemonName, 6> LegendaryPokemonTeam = CreateLegendaryPokemonTeam();

    PokemonName Rattata("Rattata", 1, 10, 10, 10, 10, 10, 10);
    Rattata.CreateMoveList("QuickAttack", "DoubleTeam", "Endeavor", "");
    Rattata.SetHeldItem("FocusSash");
    
    int currentEnemyPokemon = 0;
    Battle battle;
    while (Rattata.getIsAlive())
    {
        battle.StartMenu(LegendaryPokemonTeam, Rattata, currentEnemyPokemon);
        currentEnemyPokemon++;
        if (currentEnemyPokemon >= LegendaryPokemonTeam.size())
        {
            std::cout << "Congratulations and welcome to the hall of fame!\n";
            std::cout << "You have defeated the Legendary Pokemon traner!\n";
            break;
        }
    }
    if (!Rattata.getIsAlive())
    {
        std::cout << "Your " << Rattata.GetName() << " has fainted!\n";
        std::cout << "You have lost the battle!\n";
    }

    int num = 0;
    std::cout << "Press any key to continue";
    std::cin >> num;
}







std::array<PokemonName, 6> CreateLegendaryPokemonTeam()
{
    PokemonName MewTwo("Mewtwo", 100, 416, 350, 306, 447, 306, 394);
    MewTwo.CreateMoveList("Ice_Beam", "Aura_Spehere", "Psychic", "HyperBeam");
        
    PokemonName Rayquaza("Rayquaza", 100, 414, 438, 306, 438, 306, 317);
    Rayquaza.CreateMoveList("Ice_Beam", "Flamethrower", "Aura_Spehere", "Draco_meteor");
        
    PokemonName Arceus("Arceus",100, 444, 372, 372, 372, 372, 372);
    Arceus.CreateMoveList("Judgment", "Surf", "Dragon_Claw", "Thunderbolt");
        
    PokemonName Necrozma("Necrozma", 100, 398, 476, 322, 476, 322, 392);
    Necrozma.CreateMoveList("Earthquake", "Psychic", "Light_That_Burns_The_Sky", "Fly");
        
    PokemonName Kyurem("Kyurem", 100, 454, 372, 306, 482, 328, 317);
    Kyurem.CreateMoveList("Ice_Beam", "Outrage", "Dragon_Claw", "HyperBeam");
        
    PokemonName Lugia("Lugia", 100, 416, 306, 394, 306, 447, 350);
    Lugia.CreateMoveList("Ice_Beam", "Surf", "Psychic", "HyperBeam");

    return { MewTwo, Rayquaza, Arceus, Necrozma, Kyurem, Lugia };
}












// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
