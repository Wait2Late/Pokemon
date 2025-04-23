#include "Pokemon.h"

#include <array>
#include <iostream>
#include "../Move/Move.h"

struct PokemonBase::Impl {
    std::vector<std::unique_ptr<MoveBase>> moves;
};

PokemonBase::PokemonBase(const std::string& name, const int level, const int health, const int attack, const int defense,
                 const int spAttack, const int spDefense, const int speed):
data(name, level, health, attack, defense, spAttack, spDefense, speed),
pImpl(std::make_unique<Impl>())
{
}

PokemonBase::~PokemonBase() = default;

void PokemonBase::LearnMoves(std::vector<std::unique_ptr<MoveBase>>&& movelist)
{
    if (movelist.size() > 4)
    {
        std::cerr << "Too many moves!\n";
        return;
    }
    pImpl->moves.clear();
    pImpl->moves = std::move(movelist);
}

std::vector<std::string> PokemonBase::GetMoveNames() const
{
    std::vector<std::string> names;
    for (const auto& move : pImpl->moves)
    {
        names.push_back(move->GetMoveName());
    }
    return names;
}

void PokemonBase::EffectBeforeCombat(const std::string& moveName, PokemonBase& target)
{
    for (const auto& move : pImpl->moves)
    {
        if (move->GetMoveName() != moveName)
            continue;

        move->ApplyEffect(this, &target);
        break;
    }
}

void PokemonBase::MoveForCombat(const std::string& moveName, PokemonBase& target)
{
    std::cout << GetName() << " used " << moveName << " on " << target.GetName() << "\n";

    for (const auto& move : pImpl->moves)
    {
        if (move->GetMoveName() != moveName)
            continue;
        
        move->CalculateDamage(this, &target);
        
        std::cout << target.GetName() << " has " << target.GetHealth() << " health remaining.\n\n";
        break;
    }
}

void PokemonBase::RemoveMoveName(std::string moveName) const
{
    const auto it = std::remove_if(
       pImpl->moves.begin(),
       pImpl->moves.end(),
       [&moveName](const std::unique_ptr<MoveBase>& move) {
           return move->GetMoveName() == moveName;
       }
    );

    if (it != pImpl->moves.end())
    {
        pImpl->moves.erase(it, pImpl->moves.end());
        std::cout << "Move " << moveName << " removed successfully.\n";
    }
    else
    {
        std::cerr << "Move: " << moveName << " not found.\n";
    }   
}

void PokemonBase::SetRecordMove(const std::string& moveName)
{
    unleashMove = moveName;
}

std::string PokemonBase::GetRecordedMove() const
{
    return unleashMove;
}

int PokemonBase::TakeDamage(const int damage)
{
    data.health -= damage;
    if (data.health <= 0)
    {
        if (GetHeldItem() == "FocusSash")
        {
            data.health = 1;
            std::cout << data.name << " held a Focus Sash and survived with 1 HP!\n";
            this->SetHeldItem("");
        }
        else
        {
            data.isAlive = false;
        }
    }
    return data.health;
}

std::string PokemonBase::GetName() const
{ return data.name; }

int PokemonBase::GetLevel() const
{ return data.level; }

void PokemonBase::SetHealth(int health)
{ data.health = health; }

int PokemonBase::GetHealth() const
{ return data.health; }

int PokemonBase::GetAttack() const
{ return data.attack; }

int PokemonBase::GetDefense() const
{ return data.defense; }

int PokemonBase::GetSpAttack() const
{ return data.spAttack; }

int PokemonBase::GetSpDefense() const
{ return data.spDefense; }

int PokemonBase::GetSpeed() const
{ return data.speed; }

void PokemonBase::SetAlive(bool alive)
{ data.isAlive = alive; }

bool PokemonBase::getIsAlive() const
{ return data.isAlive; }

void PokemonBase::SetHitAccuracy(int accuracy)
{ data.hitAccuracy = accuracy; }

int PokemonBase::GetHitAccuracy() const
{ return data.hitAccuracy; }

void PokemonBase::SetPriority(bool priority)
{ priorityMove = priority; }

bool PokemonBase::GetPriority() const
{ return priorityMove; }

void PokemonBase::SetHeldItem(const std::string& item)
{ data.heldItem = item; }

std::string PokemonBase::GetHeldItem() const
{ return data.heldItem; }

void PokemonBase::DisplayStats()
{
    std::cout << "Name: " << data.name << "\n";
    std::cout << "Level: " << data.level << "\n";
    std::cout << "Health: " << data.health << "\n";
    std::cout << "Attack: " << data.attack << "\n";
    std::cout << "Defense: " << data.defense << "\n";
    std::cout << "Special Attack: " << data.spAttack << "\n";
    std::cout << "Special Defense: " << data.spDefense << "\n";
    std::cout << "Speed: " << data.speed << "\n";
}
