#pragma once
#include "BattleState.h"

class PlayerTurnState : public BattleState
{
public:
    void Enter(Battle& battle) override;
    void Execute(Battle& battle) override;
    void Exit(Battle& battle) override;
    void HandleInput(Battle& battle, int input) override;

private:
    void DisplayMoves(Battle& battle);
};
