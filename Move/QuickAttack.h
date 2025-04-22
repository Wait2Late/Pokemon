#pragma once
#include "Move.h"

class QuickAttack : public MoveBase
{
public:
    QuickAttack(): MoveBase("QuickAttack", 40) {}
    ~QuickAttack() override;
    
    void ApplyEffect(Pokemon* user, Pokemon* target) override
    {
        user->SetPriority(true);
    }

    int CalculateDamage(Pokemon* user, Pokemon* target) override
    {
        return MoveBase::CalculateDamage(user, target);
    }
};
