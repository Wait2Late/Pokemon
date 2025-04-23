#include "TurnState.h"

#include <algorithm>
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

    // Create a list of Pokémon and sort by priority and speed
    std::vector<std::pair<std::reference_wrapper<PokemonBase>, std::string>> turnOrder =
    {
        {player, playerMove},
        {opponent, opponentMove}
    };

    std::sort(turnOrder.begin(), turnOrder.end(), [](const auto& a, const auto& b)
    {
        if (a.first.get().GetPriority() == b.first.get().GetPriority())
            return a.first.get().GetSpeed() > b.first.get().GetSpeed();
        if (a.first.get().GetPriority() != b.first.get().GetPriority())
            return a.first.get().GetPriority() > b.first.get().GetPriority();
        return a.first.get().GetSpeed() > b.first.get().GetSpeed();
    });

    for (auto& [pokemon, move] : turnOrder)
    {
        auto& target = (&pokemon.get() == &player) ? opponent : player;
        
        pokemon.get().MoveForCombat(move, target);
        if (!target.getIsAlive())
        {
            battle.SetState(std::make_unique<BattleOverState>());
            return;
        }
    }

    if (player.getIsAlive())
    {
        battle.SetState(std::make_unique<PlayerTurnState>());
    }
    else
    {
        battle.SetState(std::make_unique<BattleOverState>());
    }
    
    // if (opponent.GetSpeed() > player.GetSpeed())
    // {
    //     if (player.GetPriority())
    //     {
    //         player.SetPriority(false);
    //         player.MoveForCombat(playerMove, opponent);
    //     }
    //     
    //     std::cout << opponent.GetName() << "'s turn!\n";
    //     opponent.MoveForCombat(opponentMove, player);
    // }
    //
    // if(opponent.GetSpeed() < player.GetSpeed())
    // {
    //     if (opponent.GetPriority())
    //     {
    //         opponent.SetPriority(false);
    //         opponent.MoveForCombat(opponentMove, player);
    //     }
    //     
    //     std::cout << player.GetName() << "'s turn!\n";
    //     player.MoveForCombat(playerMove, opponent);
    // }
    //
    // if (player.getIsAlive())
    // {
    //     battle.SetState(std::make_unique<PlayerTurnState>());
    // }
    // else
    // {
    //     battle.SetState(std::make_unique<BattleOverState>());
    // }
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

