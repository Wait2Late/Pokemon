#pragma once
#include "Move.h"

class IceBeam : public MoveBase
{
public:
    IceBeam() : MoveBase("Ice Beam", 90){}

    // void ApplyEffect(Pokemon& user, Pokemon& target) override
    // {
    //     Move::ApplyEffect(user, target);
    // }
};
