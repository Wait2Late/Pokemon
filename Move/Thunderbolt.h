#pragma once
#include "Move.h"

class Thunderbolt : public MoveBase
{
public:
    Thunderbolt() : MoveBase("Thunderbolt", 90) {}
    ~Thunderbolt() override;

    // void ApplyEffect(Pokemon& user, Pokemon& target) override
    // {
    //     Move::ApplyEffect(user, target);
    // }
};
