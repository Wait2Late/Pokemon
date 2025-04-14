#pragma once
#include <iostream>

#include "../Structs/PokemonData.h"

class PokemonName
{
public:
    PokemonName(const std::string& name, const int level, const int health, const int attack, const int defense, const int spAttack, const int spDefense, const int speed)
        : data(name, level, health, attack, defense, spAttack, spDefense, speed) {}

    void DisplayStats() {
        std::cout << "Name: " << data.name << "\n";
        std::cout << "Level: " << data.level << "\n";
        std::cout << "Health: " << data.health << "\n";
        std::cout << "Attack: " << data.attack << "\n";
        std::cout << "Defense: " << data.defense << "\n";
        std::cout << "Special Attack: " << data.spAttack << "\n";
        std::cout << "Special Defense: " << data.spDefense << "\n";
        std::cout << "Speed: " << data.speed << "\n";
    }

public:
    PokemonData data;
};
