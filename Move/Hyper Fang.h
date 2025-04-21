#pragma once
#include "Move.h"

class Hyper_Fang : public MoveBase
{
public:
    Hyper_Fang() : MoveBase("Hyper Fang", 80) {}
    ~Hyper_Fang() override;

    // void ApplyEffect(Pokemon& user, Pokemon& target) override
    // {
    //     Move::ApplyEffect(user, target);
    // }
};
