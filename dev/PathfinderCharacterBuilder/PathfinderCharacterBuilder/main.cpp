#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include "AbilityScores.h"
#include "Skill.h"
#include "Race.h"

// Clear Input Function
void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Prompt User to Continue Function (Pause for ease of use)
void pause() {
    std::cout << "\nPress Enter to continue...";
    clearInput();
    std::cin.get();
}

// Select Race Function
Race chooseRace() {
    while (true) {
        std::cout << "\n--- Choose Race ---\n";
        std::cout << "1. Dwarf\n";
        std::cout << "2. Elf\n";
        std::cout << "3. Gnome\n";
        std::cout << "4. Half-Elf\n";
        std::cout << "5. Half-Orc\n";
        std::cout << "6. Halfling\n";
        std::cout << "7. Human\n";
        std::cout << "Enter the number corresponding to your choice: ";

        int choice;
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cout << "Please enter a number corresponding to an available option.\n";
            clearInput();
            continue;
        }
        clearInput();

        switch (choice) {
        case 1: return makeDwarf();
        case 2: return makeElf();
        case 3: return makeGnome();
        case 4: return makeHalfElf();
        case 5: return makeHalfOrc();
        case 6: return makeHalfling();
        case 7: return makeHuman();
        default:
            std::cout << "Invalid choice. Enter a number corresponding to an available option.\n";
            break;
        }
    }
}

// Human, Half-Elf, Half-Orc Ability Score Bonus Function
// Humans, Half-Elves, and Half-Orcs get to choose which Ability Score their bonus applies to.
void applyChoiceBonus(AbilityScores& scores) {
    while (true) {
        std::cout << "\nThis race gets +2 to one Ability Score of your choice.\n";
        std::cout << "1. Strength\n";
        std::cout << "2. Dexterity\n";
        std::cout << "3. Constitution\n";
        std::cout << "4. Intelligence\n";
        std::cout << "5. Wisdom\n";
        std::cout << "6. Charisma\n";
        std::cout << "Enter the number corresponding to your choice: ";

        int choice;
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cout << "Enter a number corresponding to an available option.\n";
            clearInput();
            continue;
        }
        clearInput();

        switch (choice) {
        case 1: scores.setStrength(scores.getStrength() + 2);
            return;
        case 2: scores.setDexterity(scores.getDexterity() + 2);
            return;
        case 3: scores.setConstitution(scores.getConstitution() + 2);
            return;
        case 4: scores.setIntelligence(scores.getIntelligence() + 2);
            return;
        case 5: scores.setWisdom(scores.getWisdom() + 2);
            return;
        case 6: scores.setCharisma(scores.getCharisma() + 2);
            return;
        default:
            std::cout << "Invalid choice. Enter a number corresponding to an available option.\n";
            break;
        }
    }
}

// Assign Ability Scores
// For now, Ability Scores are assigned as the user chooses
// TO DO: Add a dice roller for Standard Ability Score assignment ruleset
AbilityScores chooseAbilityScores() {
    AbilityScores scores;
    std::cout << "\n--- Assign Ability Scores ---\n";
    std::cout << "Ability Scores are typically between 7 and 18 for a starting character.\n";
    std::cout << "Assign a value of your choice for each Ability Score.\n";

    int value;
    std::cout << "Strength: ";
    std::cin >> value;
    scores.setStrength(value);
    std::cout << "Dexterity: ";
    std::cin >> value;
    scores.setDexterity(value);
    std::cout << "Constitution: ";
    std::cin >> value;
    scores.setConstitution(value);
    std::cout << "Intelligence: ";
    std::cin >> value;
    scores.setIntelligence(value);
    std::cout << "Wisdom: ";
    std::cin >> value;
    scores.setWisdom(value);
    std::cout << "Charisma: ";
    std::cin >> value;
    scores.setCharisma(value);
    clearInput();

    return scores;
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

    // Name
    std::string name;
    std::cout << "Enter a name for the character: ";
    std::getline(std::cin, name);
    if (name.empty()) {
        clearInput();
        std::getline(std::cin, name);
    }

    // Race
    Race race = chooseRace();
    std::cout << "\nSelected Race:\n";
    race.print();

    // Base Ability Scores
    AbilityScores scores = chooseAbilityScores();
    std::cout << "\nBase Ability Scores:\n";
    scores.print();

    // Racial Ability Score Adjustment
    std::string raceName = race.getName();
    if (raceName == "Human" || raceName == "Half-Elf" || raceName == "Half-Orc") {
        applyChoiceBonus(scores);
    }
    else {
        race.applyAbilityBonuses(scores);
    }
    std::cout << "\nAbility Scores after Racial Adjustment:\n";
    scores.print();

    // Creation Summary
    std::cout << "\n--- Character Summary ---\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Race: " << race.getName() << "\n\n";
    scores.print();

    pause();
}

// View Character Menu Option Function
void viewCharacter() {
    std::cout << "\n--- View Current Character ---\n";
    std::cout << "(Placeholder - no Character class created yet)\n";
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
        clearInput();

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
