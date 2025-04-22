#include "PlayerTurnState.h"

#include <iostream>

#include "Battle.h"
#include "EnemyTurnState.h"

void PlayerTurnState::Enter(Battle& battle)
{
    std::cout << battle.GetPlayer().GetName() << "'s turn!\n";
}

void PlayerTurnState::Execute(Battle& battle)
{
}

void PlayerTurnState::Exit(Battle& battle)
{
}

void PlayerTurnState::HandleInput(Battle& battle, const int input)
{
    auto& player = battle.GetPlayer();
    auto& opponent = battle.GetOpponent();

    const std::string moveName = player.GetMoveNames()[input];
    player.UseMove(moveName, opponent);

    if (!opponent.getIsAlive())
        return;

    battle.ChangeState(std::make_unique<EnemyTurnState>());
}

void PlayerTurnState::DisplayMoves(Battle& battle)
{
    auto moveNames = battle.GetPlayer().GetMoveNames();
    
    std::cout << "Choose a move: ";

    for (int i = 0; i < moveNames.size(); ++i)
    {
        std::cout << i+1  <<". " << moveNames[i] << "\n";
    }

    int input;
    std::cin >> input;
    input--;
    if (input < 1 || input > moveNames.size())
    {
        std::cout << "Invalid choice. Please try again.\n";
        return;
    }
    HandleInput(battle, input);
}
