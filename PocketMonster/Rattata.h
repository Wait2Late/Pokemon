#pragma once
#include "Pokemon.h"

class Rattata : public PokemonBase
{
public:
    Rattata() : PokemonBase("Rattata", 1, 10, 10, 10, 10, 10, 10) {}
    ~Rattata() override;
};
