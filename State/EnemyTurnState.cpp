#include "EnemyTurnState.h"

#include <iostream>

#include "Battle.h"
#include <random>

#include "TurnState.h"

void EnemyTurnState::Enter(Battle& battle)
{
    // std::cout << battle.GetOpponent().GetName() << "'s turn!\n";
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

    opponent.SetRecordMove(moveName);

    battle.SetState(std::make_unique<TurnState>());
}

void EnemyTurnState::Exit(Battle& battle)
{
    // std::cout << battle.GetOpponent().GetName() << "'s turn ended.\n";
}

void EnemyTurnState::HandleInput(Battle& battle, int input)
{
}
