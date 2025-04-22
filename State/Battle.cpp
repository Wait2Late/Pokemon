#include "Battle.h"

#include <random>

#include "PlayerTurnState.h"

Battle::Battle(std::unique_ptr<Pokemon> player, std::unique_ptr<Pokemon> opponent):
    pPlayer(std::move(player)), pOpponent(std::move(opponent))
{}

void Battle::Start()
{
    SetState(std::make_unique<PlayerTurnState>());
}

void Battle::SetState(std::unique_ptr<BattleState> newState)
{
    if (pCurrentState)
    {
        pCurrentState->Exit(*this);
    }

    pCurrentState = std::move(newState);

    if (pCurrentState)
    {
        pCurrentState->Enter(*this);
    }
}

void Battle::HandleInput(const int input)
{
    if (pCurrentState)
    {
        pCurrentState->HandleInput(*this, input);
    }
}

void Battle::Update()
{
    if (pCurrentState)
    {
        pCurrentState->Execute(*this);
    }
}

