#pragma once
#include "Move.h"

class QuickAttack : public MoveBase
{
public:
    QuickAttack(): MoveBase("QuickAttack", 40) {}
    ~QuickAttack() override;
    
    void ApplyEffect(PokemonBase* user, PokemonBase* target) override
    {
        user->SetPriority(true);
    }

    int CalculateDamage(PokemonBase* user, PokemonBase* target) override
    {
        return MoveBase::CalculateDamage(user, target);
    }
};
