#include <iostream>
#include <string>
#include <limits>
#include "AbilityScores.h"
#include "Skill.h"
#include "Race.h"

// Clear Input Function
void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Main Menu Function
void showMainMenu() {
    std::cout << "\n==============================\n";
    std::cout << "  Pathfinder 1e Character Builder\n";
    std::cout << "==============================\n";
    std::cout << "1. Create New Character\n";
    std::cout << "2. View Current Character\n";
    std::cout << "3. Load Character (placeholder)\n";
    std::cout << "4. Exit\n";
    std::cout << "Choice: ";
}

// Create Character Menu Option Function
void createCharacter() {
    std::cout << "\n--- Create New Character ---\n";
    std::cout << "(Placeholder - real creation steps will go here)\n\n";

    // Temp data for menu test
    AbilityScores scores;
    scores.strength = 14;
    scores.dexterity = 12;
    scores.constitution = 10;
    scores.intelligence = 18;
    scores.wisdom = 8;
    scores.charisma = 16;

    Race elf = makeElf();
    elf.applyAbilityBonuses(scores);
    std::cout << "Placeholder Character:\n";
    elf.print();
    std::cout << "\nAbility Scores after racial adjustment:\n";
    scores.print();

    std::cout << "\nPress Enter to return to main menu...";
    clearInput();
    std::cin.get();
}

// View Character Menu Option Function
void viewCharacter() {
    std::cout << "\n--- View Current Character ---\n";
    std::cout << "(Placeholder - no character created yet)\n";
    std::cout << "\nPress Enter to return to main menu...";
    clearInput();
    std::cin.get();
}

// Load Character Menu Option Function
void loadCharacter() {
    std::cout << "\n--- Load Character ---\n";
    std::cout << "(Placeholder - not implemented yet)\n";
    std::cout << "\nPress Enter to return to main menu...";
    clearInput();
    std::cin.get();
}

int main()
{
    // Test for AbilityScores:
    //AbilityScores scores;
    //scores.dexterity = 16;
    //scores.print();
    //return 0;

    // Test for Skill:
    //Skill acrobatics;
    //acrobatics.name = "Acrobatics";
    //acrobatics.keyAbility = Skill::KeyAbility::Dexterity;
    //acrobatics.ranks = 0;
    //acrobatics.isClassSkill = true;
    //acrobatics.trainedOnly = true;
    //acrobatics.print(scores);
    //return 0;

    // Test for Race:
    //AbilityScores scores;
    //scores.strength = 14;
    //scores.dexterity = 12;
    //scores.constitution = 10;
    //scores.intelligence = 18;
    //scores.wisdom = 8;
    //scores.charisma = 16;
    //Race elf = makeElf();
    //elf.applyAbilityBonuses(scores);
    //elf.print();
    //scores.print();
    //return 0;

    bool running = true;

    while (running) {
        showMainMenu();

        int choice;
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number corresponding to options 1-4.\n";
            clearInput();
            continue;
        }

        switch (choice) {
        case 1:
            createCharacter();
            break;
        case 2:
            viewCharacter();
            break;
        case 3:
            loadCharacter();
            break;
        case 4:
            std::cout << "\nExiting\n";
            running = false;
            break;
        default:
            std::cout << "Invalid input. Please enter a number corresponding to options 1-4.\n";
            break;
        }
    }

    return 0;
}
