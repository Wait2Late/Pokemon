#pragma once

#include <iostream>
#include <string>
#include "../PocketMonster/Pokemon.h"

class MoveBase
{
public:
    MoveBase(std::string n, const int p) : name(std::move(n)), power(p) {}
    
    virtual ~MoveBase();

    virtual void ApplyEffect(PokemonBase* user, PokemonBase* target)
    {
    }
    
    virtual int CalculateDamage(PokemonBase* user, PokemonBase* target)
    {
        int damage = (user->GetAttack() + power) - target->GetDefense();
        if (damage <= 0)
            damage = 1;

        std::cout << target->GetName() << " took " << damage << " damage!\n";
        
        return target->TakeDamage(damage);
    }

    std::string GetMoveName()
    {
        return name;
    }
    
private:
    std::string name;
    int power;
};


