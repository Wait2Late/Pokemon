#include "BattleOverState.h"

#include <iostream>

#include "Battle.h"

void BattleOverState::Enter(Battle& battle)
{
    const auto& player = battle.GetPlayer();
    const auto& opponent = battle.GetOpponent();
    
    if (!player.getIsAlive())
    {
        std::cout << player.GetName() << " fainted!\n";
        std::cout << "You lost the battle!\n";
    }
    else
    {
        std::cout << opponent.GetName() << " fainted!\n";
        std::cout << "You won the battle!\n";
    }
}

void BattleOverState::Execute(Battle& battle)
{
}

void BattleOverState::Exit(Battle& battle)
{
}

void BattleOverState::HandleInput(Battle& battle, int input)
{
}
