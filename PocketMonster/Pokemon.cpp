#include "Pokemon.h"

#include <array>
#include <iostream>
#include "../Move/Move.h"

struct Pokemon::Impl {
    std::vector<std::unique_ptr<MoveBase>> moves;
};

Pokemon::Pokemon(const std::string& name, const int level, const int health, const int attack, const int defense,
                 const int spAttack, const int spDefense, const int speed):
data(name, level, health, attack, defense, spAttack, spDefense, speed),
pImpl(std::make_unique<Impl>())
{
}

Pokemon::~Pokemon() = default;

void Pokemon::LearnMoves(std::vector<std::unique_ptr<MoveBase>>&& movelist)
{
    if (movelist.size() > 4)
    {
        std::cerr << "Too many moves!\n";
        return;
    }
    pImpl->moves.clear();
    // for (auto& move : movelist)
    // {
    //     if (move == nullptr)
    //     {
    //         std::cerr << "Invalid move!\n";
    //         return;
    //     }
    //     // pImpl->moves.push_back(std::move(move));
    // }
    pImpl->moves = std::move(movelist);
}

std::vector<std::string> Pokemon::GetMoveNames() const
{
    std::vector<std::string> names;
    for (const auto& move : pImpl->moves)
    {
        if (move != nullptr)
        {
            names.push_back(move ? move->GetMoveName() : "Empty");
        }
    }
    return names;
}

void Pokemon::UseMove(std::string moveName, Pokemon& target)
{
    std::cout << GetName() << " used " << moveName << " on " << target.GetName() << "\n";
}


std::array<std::string, 4> Pokemon::CreateMoveList(const std::string& move1, const std::string& move2, const std::string& move3, const std::string& move4)
// std::vector<std::string> PokemonName::CreateMoveList(const std::string& move1, const std::string& move2, const std::string& move3, const std::string& move4)
{
    std::vector<std::string> movesList = moveData.movesList;
    const std::array<std::string, 4> moves = {move1, move2, move3, move4};
    // std::vector<std::string> moves = {move1, move2, move3, move4};
    
    for (const std::string& move : moves)
    {
        //Check if there are any duplicates
        if (std::count(moves.begin(), moves.end(), move) > 1)
        {
            std::cerr << "Duplicate move: " << move << "\n";
            return {};
        }
            
        if (std::find(movesList.begin(), movesList.end(), move) == movesList.end())
        {
            std::cerr << "Invalid move: " << move << "\n";
            return {};
        }
    }
        
    return moveList = moves;
}

std::array<std::string, 4> Pokemon::GetMoveList() const
// std::vector<std::string> PokemonName::GetMoveList() const
{
    return moveList;
}

int Pokemon::TakeDamage(int damage)
{
    data.health -= damage;
    if (data.health <= 0)
    {
        data.isAlive = false;
        std::cout << data.name << " has fainted!\n";
    }
    return data.health;
}

std::string Pokemon::GetName() const
{ return data.name; }

int Pokemon::GetLevel() const
{ return data.level; }

void Pokemon::SetHealth(int health)
{ data.health = health; }

int Pokemon::GetHealth() const
{ return data.health; }

int Pokemon::GetAttack() const
{ return data.attack; }

int Pokemon::GetDefense() const
{ return data.defense; }

int Pokemon::GetSpAttack() const
{ return data.spAttack; }

int Pokemon::GetSpDefense() const
{ return data.spDefense; }

int Pokemon::GetSpeed() const
{ return data.speed; }

void Pokemon::SetAlive(bool alive)
{ data.isAlive = alive; }

bool Pokemon::getIsAlive() const
{ return data.isAlive; }

void Pokemon::SetHitAccuracy(int accuracy)
{ data.hitAccuracy = accuracy; }

int Pokemon::GetHitAccuracy() const
{ return data.hitAccuracy; }

void Pokemon::SetPriority(bool priority)
{ priorityMove = priority; }

bool Pokemon::GetPriority() const
{ return priorityMove; }

void Pokemon::SetHeldItem(const std::string& item)
{ data.heldItem = item; }

std::string Pokemon::GetHeldItem() const
{ return data.heldItem; }

void Pokemon::DisplayStats()
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
