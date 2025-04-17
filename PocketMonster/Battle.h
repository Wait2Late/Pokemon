#pragma once
#include <iostream>

#include "PokemonName.h"


class Battle
{
public:
    void StartMenu(std::array<PokemonName, 6>& LegendaryPokemonTeam, PokemonName& Rattata, int& currentPokemonIndex);
    void PickMove(PokemonName& currentPokemon, PokemonName& Rattata);
    
private:
    void BattleLogic(PokemonName& currentPokemon, PokemonName& Rattata);
    void DamageLogic(PokemonName& reciever, PokemonName& attacker, int moveChoice);
    
};

