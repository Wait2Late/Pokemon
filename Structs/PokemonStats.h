#pragma once

struct PokemonData
{
    int level;
    int health;
    int attack;
    int defense;
    int spAttack;
    int spDefense;
    int speed;

    PokemonData(const int l, const int h, const int a, const int d, const int sa, const int sd, const int s)
        :level(l), health(h), attack(a), defense(d), spAttack(sa), spDefense(sd), speed(s) {}
};
