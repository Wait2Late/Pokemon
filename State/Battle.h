#pragma once
#include <memory>
#include <memory>
#include <vector>
#include "BattleState.h"
#include "EnemyTurnState.h"
#include "PlayerTurnState.h"
#include "../PocketMonster/Pokemon.h"


class Battle
{
public:
    Battle(Pokemon& player, Pokemon& opponent)
    {

    }

    void Start();
    void ChangeState(const std::unique_ptr<BattleState>& newState);
    void HandleInput(int input);
    void Update();
    
    // Getters
    Pokemon& GetPlayer() { return *pPlayer; }
    Pokemon& GetOpponent() { return *pOpponent; }
    BattleState* GetCurrentState() const { return pCurrentState.get(); }

private:
    std::unique_ptr<Pokemon> pPlayer;
    std::unique_ptr<Pokemon> pOpponent;
    std::unique_ptr<BattleState> pCurrentState;
};
