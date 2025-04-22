#pragma once

#include <array>
#include <memory>

#include "../Structs/PokemonData.h"

class MoveBase;

class Pokemon
{
public:
    Pokemon(const std::string& name, const int level, const int health, const int attack, const int defense,
                    const int spAttack, const int spDefense, const int speed);

    virtual ~Pokemon();
    
    void DisplayStats();

    std::array<std::string, 4> CreateMoveList(const std::string& move1, const std::string& move2, const std::string& move3, const std::string& move4);
    // std::vector<std::string> CreateMoveList(const std::string& move1, const std::string& move2, const std::string& move3, const std::string& move4);
    std::array<std::string, 4> GetMoveList() const;
    // std::vector<std::string> GetMoveList() const;
    

    std::string GetName() const;
    int GetLevel() const;
    void SetHealth(int health);
    int GetHealth() const;
    int GetAttack() const;
    int GetDefense() const;
    int GetSpAttack() const;
    int GetSpDefense() const;
    int GetSpeed() const;

    void SetAlive(bool alive);
    bool getIsAlive() const;

    void SetHitAccuracy(int accuracy);
    int GetHitAccuracy() const;

    void SetPriority(bool priority);
    bool GetPriority() const;

    void SetHeldItem(const std::string& item);
    std::string GetHeldItem() const;

    int TakeDamage(int damage);

    void LearnMoves(std::vector<std::unique_ptr<MoveBase>>&& movelist);
    std::vector<std::string> GetMoveNames() const;
    void RemoveMoveName(std::string moveName) const;
    void UseMove(const std::string& moveName, Pokemon& target);

protected:

    bool priorityMove = false;
private:
    PokemonMoveData moveData;
    PokemonData data;
    
    struct Impl;
    std::unique_ptr<Impl> pImpl;
    
    // std::vector<std::string> moveList;
    std::array<std::string, 4> moveList;

};
