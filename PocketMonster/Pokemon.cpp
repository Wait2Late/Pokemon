#include "Pokemon.h"

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
