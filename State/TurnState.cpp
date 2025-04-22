#include "TurnState.h"

#include <iostream>

#include "Battle.h"
#include "BattleOverState.h"
#include "PlayerTurnState.h"

void TurnState::Enter(Battle& battle)
{
    auto& player = battle.GetPlayer();
    auto& opponent = battle.GetOpponent();

    const auto playerMove = player.GetRecordedMove();
    const auto opponentMove = opponent.GetRecordedMove();
    
    player.EffectBeforeCombat(playerMove, opponent);
    opponent.EffectBeforeCombat(opponentMove, player);

    if (opponent.GetSpeed() > player.GetSpeed())
    {
        if (player.GetPriority())
        {
            player.SetPriority(false);
            player.MoveForCombat(playerMove, opponent);
        }
        
        std::cout << opponent.GetName() << "'s turn!\n";
        opponent.MoveForCombat(opponentMove, player);
    }

    if(opponent.GetSpeed() < player.GetSpeed())
    {
        if (opponent.GetPriority())
        {
            opponent.SetPriority(false);
            opponent.MoveForCombat(opponentMove, player);
        }
        
        std::cout << player.GetName() << "'s turn!\n";
        player.MoveForCombat(playerMove, opponent);
    }

    if (player.getIsAlive())
    {
        battle.SetState(std::make_unique<PlayerTurnState>());
    }
    else
    {
        battle.SetState(std::make_unique<BattleOverState>());
    }
}

void TurnState::Execute(Battle& battle)
{
}

void TurnState::Exit(Battle& battle)
{
}

void TurnState::HandleInput(Battle& battle, int input)
{
}
