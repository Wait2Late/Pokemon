#pragma once
#include "Move.h"

class DoubleTeam : public MoveBase
{
public:
    DoubleTeam() : MoveBase("Double Team", 0) {}
    ~DoubleTeam() override;
    
    // void ApplyEffect(Pokemon& user, Pokemon& target) override
    // {
    //     user.SetHitAccuracy(user.GetHitAccuracy() + 100);
    // }
};
