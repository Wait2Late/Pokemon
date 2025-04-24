#pragma once
#include "Move.h"

class IceBeam : public MoveBase
{
public:
    IceBeam() : MoveBase("Ice Beam", 90){}
    ~IceBeam() override;

    // void ApplyEffect(Pokemon& user, Pokemon& target) override
    // {
    //     Move::ApplyEffect(user, target);
    // }
};
