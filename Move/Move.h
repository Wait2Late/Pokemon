#pragma once

#include <string>
#include "../PocketMonster/Pokemon.h"
// class Pokemon;

class MoveBase
{
public:
    MoveBase(std::string n, int p) : name(std::move(n)), power(p) {}
    
    virtual ~MoveBase() = default;

    virtual void ApplyEffect(Pokemon& user, Pokemon& target)
    {
        int damage = CalculateDamage(user, target);
        // int damage = 5;
        target.TakeDamage(damage);
    }
    
    virtual int CalculateDamage(Pokemon& user, Pokemon& target)
    {
        int damage = (user.GetAttack() + power) - target.GetDefense();
        if (damage <= 0)
            damage = 1;
        
        return damage;
    }

protected:
    std::string name;
    int power;
};


