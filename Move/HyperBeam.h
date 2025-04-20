#pragma once
#include "Move.h"

class HyperBeam : public MoveBase
{
public:
    HyperBeam() : MoveBase("Hyper Beam", 150) {}

    ~HyperBeam() override;

    // void ApplyEffect(Pokemon& user, Pokemon& target) override
    // {
    //     Move::ApplyEffect(user, target);
    // }
};
