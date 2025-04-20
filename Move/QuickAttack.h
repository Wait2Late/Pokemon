#pragma once
#include "Move.h"

class QuickAttack : public MoveBase
{
public:
    QuickAttack(): MoveBase("QuickAttack", 40) {}
    ~QuickAttack() override;
    
    // void ApplyEffect(Pokemon& user, Pokemon& target) override
    // {
    //     user.SetPriority(true);
    //     Move::ApplyEffect(user, target);
    // }
};
