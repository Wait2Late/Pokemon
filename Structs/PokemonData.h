#pragma once
#include <array>
#include <string>
#include <vector>

enum class eMove : int
{
    QuickAttack = 0,
    DoubleTeam,
    Endeavor,
    HyperBeam,
    Judgment,
    Flamethrower,
    Aura_Spehere,
    Draco_meteor,
    Ice_Beam,
    Surf,
    Dragon_Claw,
    Thunderbolt,
    Earthquake,
    Psychic,
    Shadow_Ball,
    Fly,
    Light_That_Burns_The_Sky,
    Outrage,
};

struct PokemonData
{
    std::string name;
    int level;
    int health;
    int attack;
    int defense;
    int spAttack;
    int spDefense;
    int speed;

    PokemonData(std::string n, const int l, const int h, const int a, const int d, const int sa, const int sd, const int s)
        :name(std::move(n)), level(l), health(h), attack(a), defense(d), spAttack(sa), spDefense(sd), speed(s) {}

    // std::array<std::string, 4> PokemonMoves = 
};

struct PokemonMoveData
{
    std::vector<std::string> movesList = {
    "QuickAttack",
    "DoubleTeam",
    "Endeavor",
    "HyperBeam",
    "Judgment",
    "Flamethrower",
    "Aura_Spehere",
    "Draco_meteor",
    "Ice_Beam",
    "Surf",
    "Dragon_Claw",
    "Thunderbolt",
    "Earthquake",
    "Psychic",
    "Shadow_Ball",
    "Fly",
    "Light_That_Burns_The_Sky",
    "Outrage"};


    
};
