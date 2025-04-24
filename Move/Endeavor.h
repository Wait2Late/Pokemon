#pragma once
#include "Move.h"

class Endeavor : public MoveBase
{
public:
    Endeavor() : MoveBase("Endeavor", 0){}
    ~Endeavor() override;
    
    void ApplyEffect(PokemonBase* user, PokemonBase* target) override
    {
    }

    int CalculateDamage(PokemonBase* user, PokemonBase* target) override
    {
        if (target->GetHealth() > user->GetHealth())
        {
            const int mewtwoHealth = target->GetHealth();
            const int rattataHealth = user->GetHealth();

            const int healthDiff = mewtwoHealth - rattataHealth;
            return target->TakeDamage(healthDiff);
        }
        else
        {
            return target->TakeDamage(0);
        }
    }
};
