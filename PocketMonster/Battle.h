#pragma once
#include <iostream>

#include "Pokemon.h"


class Battle
{
public:
    // void StartMenu(std::array<Pokemon, 6>& LegendaryPokemonTeam, Pokemon& Rattata, int& currentPokemonIndex);
    void StartMenu(std::vector<Pokemon> LegendaryPokemonTeam, Pokemon& Rattata, int& currentPokemonIndex);
    void PickMove(Pokemon& currentPokemon, Pokemon& Rattata);
    
private:
    void DamageLogic(Pokemon& reciever, Pokemon& attacker, int moveChoice);
    
};

