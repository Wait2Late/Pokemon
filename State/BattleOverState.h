#pragma once
#include "BattleState.h"

class BattleOverState : public BattleState
{
public:
    void Enter(Battle& battle) override;
    void Execute(Battle& battle) override;
    void Exit(Battle& battle) override;
    void HandleInput(Battle& battle, int input) override;
};
