#include "PlayerTurnState.h"

#include <iostream>

#include "Battle.h"
#include "BattleOverState.h"
#include "EnemyTurnState.h"

void PlayerTurnState::Enter(Battle& battle)
{
    std::cout << battle.GetPlayer().GetName() << "'s turn!\n";
    DisplayMoves(battle);
}

void PlayerTurnState::Execute(Battle& battle)
{
}

void PlayerTurnState::Exit(Battle& battle)
{
    std::cout << battle.GetPlayer().GetName() << "'s turn ended.\n";
}

void PlayerTurnState::HandleInput(Battle& battle, const int input)
{
    auto& player = battle.GetPlayer();
    auto& opponent = battle.GetOpponent();

    const auto& moveNames = player.GetMoveNames();
    const auto moveName = moveNames[input];

    player.SetRecordMove(moveName);
    // player.UseMove(moveName, opponent);

    if (opponent.getIsAlive())
    {
        battle.SetState(std::make_unique<EnemyTurnState>());
    }
    else
    {
        battle.SetState(std::make_unique<BattleOverState>());
    }
}

void PlayerTurnState::DisplayMoves(Battle& battle)
{
    auto moveNames = battle.GetPlayer().GetMoveNames();
    
    std::cout << "Choose a move: \n";

    for (int i = 0; i < moveNames.size(); ++i)
    {
        std::cout << i+1  <<". " << moveNames[i] << "\n";
    }

    int input;
    std::cin >> input;
    input--;
    if (input < 0 || input > moveNames.size())
    {
        std::cout << "Invalid choice. Please try again.\n";
        return;
    }
    HandleInput(battle, input);
}
