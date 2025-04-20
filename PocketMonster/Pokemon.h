#pragma once

#include <array>

#include "../Structs/PokemonData.h"
#include <iostream>



class Pokemon
{
public:
    Pokemon(const std::string& name, const int level, const int health, const int attack, const int defense, const int spAttack, const int spDefense, const int speed)
        : data(name, level, health, attack, defense, spAttack, spDefense, speed) {}

    void DisplayStats();

    std::array<std::string, 4> CreateMoveList(const std::string& move1, const std::string& move2, const std::string& move3, const std::string& move4);
    // std::vector<std::string> CreateMoveList(const std::string& move1, const std::string& move2, const std::string& move3, const std::string& move4);
    std::array<std::string, 4> GetMoveList() const;
    // std::vector<std::string> GetMoveList() const;
    

    std::string GetName() const { return data.name; }
    int GetLevel() const { return data.level; }
    void SetHealth(int health) { data.health = health; }
    int GetHealth() const { return data.health; }
    int GetAttack() const { return data.attack; }
    int GetDefense() const { return data.defense; }
    int GetSpAttack() const { return data.spAttack; }
    int GetSpDefense() const { return data.spDefense; }
    int GetSpeed() const { return data.speed; }

    void SetAlive(bool alive) { data.isAlive = alive; }
    bool getIsAlive() const { return data.isAlive; }

    void SetHitAccuracy(int accuracy) { data.hitAccuracy = accuracy; }
    int GetHitAccuracy() const { return data.hitAccuracy; }
    
    void SetPriority(bool priority) { priorityMove = priority; }
    bool GetPriority() const { return priorityMove; }

    void SetHeldItem(const std::string& item) { data.heldItem = item; }
    std::string GetHeldItem() const { return data.heldItem; }
private:
    PokemonMoveData moveData;
    PokemonData data;

    // std::vector<std::string> moveList;
    std::array<std::string, 4> moveList;

    bool priorityMove = false;
};
