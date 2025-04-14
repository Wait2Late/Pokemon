#pragma once
#include <iostream>

#include "PokemonName.h"

class Battle
{
public:
    void StartMenu(std::array<PokemonName, 6>& LegendaryPokemonTeam, PokemonName& Rattata, int& currentPokemonIndex);
    void MoveList(PokemonName& currentPokemon, PokemonName& Rattata);
    
private:

    void AttackObserver(const PokemonName& reciever, const PokemonName& Attacker, eMove move);

};
