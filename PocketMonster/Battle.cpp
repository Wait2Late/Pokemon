#include "Battle.h"


void Battle::StartMenu()
{
    std::cout << "Choose between 1-4\n";
    std::cout << "1. Choose a move\n";
    std::cout << "2. Display enemy stats\n";
    std::cout << "2. Exit\n";

    int choice;
    std::cin >> choice;

    switch (choice)
    {
    case 1:

        
        break;
    case 2:
        std::cout << "Exiting the game.\n";
        break;
    default:
        std::cout << "Invalid choice. Please try again.\n";
        StartMenu();
        break;
    }
}

void Battle::MoveList()
{
    std::cout << "1.Endeavor\n";
    std::cout << "2.Quick Attack\n";
    std::cout << "3.Double Team\n";

    int moveChoice;
    std::cin >> moveChoice;
    switch (moveChoice)
    {
    case 1: 
        std::cout << "You used Endeavor!\n";
        break;
    case 2:
        std::cout << "You used Quick Attack!\n";
        break;
    case 3:
        std::cout << "You used Double Team!\n";
        break;
    default:
        std::cout << "Invalid choice. Please try again.\n";
        MoveList();
        break;
    }
}
