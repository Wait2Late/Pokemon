// Pokemon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <iostream>

#include "Move/DoubleTeam.h"
#include "Move/Endeavor.h"
#include "Move/Hyper Fang.h"
#include "Move/HyperBeam.h"
#include "Move/IceBeam.h"
#include "Move/Psychic.h"
#include "Move/QuickAttack.h"
#include "Move/Thunderbolt.h"
#include "PocketMonster/Mewtwo.h"
#include "PocketMonster/Pokemon.h"
#include "PocketMonster/Rattata.h"
#include "State/Battle.h"
#include "State/BattleOverState.h"
#include "State/PlayerTurnState.h"

void CreateMewtwo(std::unique_ptr<PokemonBase>& mewtwo);
void CreateRattata(std::unique_ptr<PokemonBase>& rattata);

int main()
{
    std::unique_ptr<PokemonBase> mewtwo;
    CreateMewtwo(mewtwo);


    std::unique_ptr<PokemonBase> rattata;
    CreateRattata(rattata);

    std::cout << "Hello and welcome to Pokemon battle!\n";
    std::cout << "This is a simple Pokemon battle simulation.\n";
    std::cout << "You will play as Jimmy, the little boy from Route 1. Who anticipate to meet the Legendary Pokemon trainer\n";
    std::cout << "Jimmy only has one Pokemon at level 1. While the Legendary Pokemon Trainer has one of level 100\n";
    std::cout << "As you can imagine that Pokemon is also legendary\n\n";
    
    Battle battle(std::move(rattata), std::move(mewtwo));
    battle.Start();

    // while (rattata->getIsAlive() && mewtwo->getIsAlive())
    while (true)
    {
        if (auto* state = battle.GetCurrentState())
        {
            if (dynamic_cast<PlayerTurnState*>(state))
            {
                // battle.HandleInput(3);
            }
            
            battle.Update();

            // if (dynamic_cast<BattleOverState*>(state))
            // {
            //     break;
            // }
        }
    }
}

void CreateMewtwo(std::unique_ptr<PokemonBase>& mewtwo)
{
    std::vector<std::unique_ptr<MoveBase>> mewtwoMoves;
    mewtwoMoves.push_back(std::make_unique<Thunderbolt>());
    mewtwoMoves.push_back(std::make_unique<IceBeam>());
    mewtwoMoves.push_back(std::make_unique<HyperBeam>());
    mewtwoMoves.push_back(std::make_unique<Psychic>());

    mewtwo = std::make_unique<Mewtwo>();
    mewtwo->LearnMoves(std::move(mewtwoMoves));
}

void CreateRattata(std::unique_ptr<PokemonBase>& rattata)
{
    std::vector<std::unique_ptr<MoveBase>> rattataMoves;
    rattataMoves.push_back(std::make_unique<QuickAttack>());
    rattataMoves.push_back(std::make_unique<DoubleTeam>());
    rattataMoves.push_back(std::make_unique<Endeavor>());
    rattataMoves.push_back(std::make_unique<Hyper_Fang>());

    rattata = std::make_unique<Rattata>();
    rattata->LearnMoves(std::move(rattataMoves));
    rattata->SetHeldItem("FocusSash");
}

// std::vector<Pokemon> CreateLegendaryPokemonTeam()
// {
//     Pokemon MewTwo("Mewtwo", 100, 416, 350, 306, 447, 306, 394);
//     MewTwo.CreateMoveList("Ice_Beam", "Aura_Spehere", "Psychic", "HyperBeam");
//         
//     // Pokemon Rayquaza("Rayquaza", 100, 414, 438, 306, 438, 306, 317);
//     // Rayquaza.CreateMoveList("Ice_Beam", "Flamethrower", "Aura_Spehere", "Draco_meteor");
//     //     
//     // Pokemon Arceus("Arceus",100, 444, 372, 372, 372, 372, 372);
//     // Arceus.CreateMoveList("Judgment", "Surf", "Dragon_Claw", "Thunderbolt");
//     //     
//     // Pokemon Necrozma("Necrozma", 100, 398, 476, 322, 476, 322, 392);
//     // Necrozma.CreateMoveList("Earthquake", "Psychic", "Light_That_Burns_The_Sky", "Fly");
//     //     
//     // Pokemon Kyurem("Kyurem", 100, 454, 372, 306, 482, 328, 317);
//     // Kyurem.CreateMoveList("Ice_Beam", "Outrage", "Dragon_Claw", "HyperBeam");
//     //     
//     // Pokemon Lugia("Lugia", 100, 416, 306, 394, 306, 447, 350);
//     // Lugia.CreateMoveList("Ice_Beam", "Surf", "Psychic", "HyperBeam");
//
//     return { MewTwo/*, Rayquaza, Arceus, Necrozma, Kyurem, Lugia */};
// }












// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
