#include "EnemyTurnState.h"

#include <iostream>

#include "PlayerTurnState.h"
#include "Battle.h"
#include <random>

#include "BattleOverState.h"
#include "TurnState.h"

void EnemyTurnState::Enter(Battle& battle)
{
    std::cout << battle.GetOpponent().GetName() << "'s turn!\n";
}

void EnemyTurnState::Execute(Battle& battle)
{
    auto& opponent = battle.GetOpponent();
    auto& player = battle.GetPlayer();

    if (!opponent.getIsAlive())
        return;
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, opponent.GetMoveNames().size() - 1);

    const int moveIndex = dist(gen);
    const auto moveName= opponent.GetMoveNames()[moveIndex];

    // opponent.UseMove(moveName, player);

    opponent.SetRecordMove(moveName);

    battle.SetState(std::make_unique<TurnState>());
    // if (player.getIsAlive())
    // {
    //     battle.SetState(std::make_unique<PlayerTurnState>());
    // }
    // else
    // {
    //     battle.SetState(std::make_unique<BattleOverState>());
    // }
}

void EnemyTurnState::Exit(Battle& battle)
{
    std::cout << battle.GetOpponent().GetName() << "'s turn ended.\n";
}

void EnemyTurnState::HandleInput(Battle& battle, int input)
{
}
