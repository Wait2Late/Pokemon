#pragma once
#include "Pokemon.h"

class Rattata : public Pokemon
{
public:
    Rattata() : Pokemon("Rattata", 1, 10, 10, 10, 10, 10, 10) {}
    ~Rattata() override;
};
