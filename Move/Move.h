#pragma once

#include <iostream>
#include <string>
#include "../PocketMonster/Pokemon.h"

class MoveBase
{
public:
    MoveBase(std::string n, const int p) : name(std::move(n)), power(p) {}
    
    virtual ~MoveBase();

    virtual void ApplyEffect(Pokemon* user, Pokemon* target)
    {
        // const int damage = CalculateDamage(*user, *target);
        // target->TakeDamage(damage);

        // std::cout << target->GetName() << " took " << damage << " damage!\n";
        // std::cout << target->GetName() << " has " << target->GetHealth() << " health left.\n\n";
    }
    
    virtual int CalculateDamage(Pokemon* user, Pokemon* target)
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
protected:
    std::string name;
    int power;
};


