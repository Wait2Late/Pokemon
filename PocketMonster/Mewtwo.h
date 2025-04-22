#pragma once
#include "Pokemon.h"

class Mewtwo : public PokemonBase
{
public:
    Mewtwo() : PokemonBase("Mewtwo", 100, 416, 350, 306, 447, 306, 394) {}
    ~Mewtwo() override;
};
