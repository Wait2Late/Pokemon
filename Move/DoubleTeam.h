#pragma once
#include "Move.h"

class DoubleTeam : public MoveBase
{
public:
    DoubleTeam() : MoveBase("Double Team", 0) {}
    ~DoubleTeam() override;

    void ApplyEffect(PokemonBase* user, PokemonBase* target) override
    {
        // user->SetHitAccuracy(user->GetHitAccuracy() + 100);
    }

    int CalculateDamage(PokemonBase* user, PokemonBase* target) override
    {
        user->SetHitAccuracy(user->GetHitAccuracy() + 100);
        
        return MoveBase::CalculateDamage(user, target);
    }
};
