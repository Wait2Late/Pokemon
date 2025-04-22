#pragma once

class Battle; 

class BattleState
{
public:
    virtual ~BattleState();
    virtual void Enter(Battle& battle) = 0;
    virtual void Execute(Battle& battle) = 0;
    virtual void Exit(Battle& battle) = 0;
    virtual void HandleInput(Battle& battle, int input) = 0;
};