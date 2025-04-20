#pragma once
#include "Move.h"

class Endeavor : public MoveBase
{
public:
    Endeavor() : MoveBase("Endeavor", 0){}

    ~Endeavor() override;
    // void ApplyEffect(Pokemon& user, Pokemon& target) override
    // {
    //     if (target.GetHealth() > user.GetHealth())
    //     {
    //         target.SetHealth(user.GetHealth());
    //     }
    //     else
    //     {
    //         std::cout << "Invalid use of Endeavor " << target.GetName() << " has less health than " << user.GetName() << "\n";
    //     }
    // }
};
