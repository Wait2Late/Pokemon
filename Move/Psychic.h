#pragma once
#include "Move.h"

class  Psychic : public MoveBase
{
public:
    Psychic() : MoveBase("Psychic", 90) {}
    ~Psychic() override;

    // void ApplyEffect(Pokemon& user, Pokemon& target) override
    // {
    //     Move::ApplyEffect(user, target);
    // }
};
