#include "EnemyTurnState.h"

#include <iostream>

#include "PlayerTurnState.h"
#include "Battle.h"
#include <random>

#include "BattleOverState.h"

void EnemyTurnState::Enter(Battle& battle)
{
    std::cout << battle.GetOpponent().GetName() << "'s turn!\n";
}

void EnemyTurnState::Execute(Battle& battle)
{
    auto& opponent = battle.GetOpponent();
    auto& player = battle.GetPlayer();
    
    // Simple AI: Random move selection
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, opponent.GetMoveNames().size() - 1);

    const int moveIndex = dist(gen);
    const auto moveName= opponent.GetMoveNames()[moveIndex];
    opponent.UseMove(moveName, player);
    
    // Transition to appropriate state
    if (player.getIsAlive())
    {
        battle.ChangeState(std::make_unique<PlayerTurnState>());
    }
    else
    {
        battle.ChangeState(std::make_unique<BattleOverState>());
    }
}

void EnemyTurnState::Exit(Battle& battle)
{
}

void EnemyTurnState::HandleInput(Battle& battle, int input)
{
}

// ... other methods ...
