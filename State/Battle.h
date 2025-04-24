#pragma once
#include <memory>
#include <memory>
#include "BattleState.h"
#include "../PocketMonster/Pokemon.h"


class Battle
{
public:
    Battle(std::unique_ptr<PokemonBase> player, std::unique_ptr<PokemonBase> opponent);

    void Start();
    void SetState(std::unique_ptr<BattleState> newState);
    void HandleInput(int input);
    void Update();
    
    // Getters
    PokemonBase& GetPlayer() { return *pPlayer; }
    PokemonBase& GetOpponent() { return *pOpponent; }
    BattleState* GetCurrentState() const { return pCurrentState.get(); }

private:
    std::unique_ptr<PokemonBase> pPlayer;
    std::unique_ptr<PokemonBase> pOpponent;
    std::unique_ptr<BattleState> pCurrentState;
};
