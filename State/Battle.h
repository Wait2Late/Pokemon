#pragma once
#include <memory>
#include <memory>
#include "BattleState.h"
#include "../PocketMonster/Pokemon.h"


class Battle
{
public:
    Battle(std::unique_ptr<Pokemon> player, std::unique_ptr<Pokemon> opponent);

    void Start();
    void SetState(std::unique_ptr<BattleState> newState);
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
