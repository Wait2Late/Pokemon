#pragma once

#include "../Structs/PokemonData.h"
#include <iostream>


class PokemonName
{
public:
    PokemonName(const std::string& name, const int level, const int health, const int attack, const int defense, const int spAttack, const int spDefense, const int speed)
        : data(name, level, health, attack, defense, spAttack, spDefense, speed) {}

    void DisplayStats();

    std::array<std::string, 4> CreateMoveList(const std::string& move1, const std::string& move2, const std::string& move3, const std::string& move4);
    std::array<std::string, 4> GetMoveList() const;
public:
    PokemonData data;
    PokemonMoveData moveData;
private:
    std::array<std::string, 4> moveList;
};
