#include "Character.h"
#include <iostream>

// Print
void Character::print() const {
	// Check if a Character is created yet
	if (!created) {
		std::cout << "No character has been created yet.\n";
		return;
	}

	std::cout << "\n========== Character Sheet ==========\n";
	// Character's Name
	std::cout << "Name:  " << name << "\n";
	// Race
	std::cout << "Race:  " << race.getName() << "\n";
	// Class
	std::cout << "Class:  " << characterClass.getName() << "\n\n";

	// Ability Scores
	std::cout << "Ability Scores:\n";
	scores.print();

	// Race
	std::cout << "\n--- Race ---\n";
	race.print();

	// Character Class
	std::cout << "\n--- Class ---\n";
	characterClass.print();

	// Skills
	if (!skills.empty()) {
		std::cout << "\n--- Skills ---\n";
		for (const auto& skill : skills) {
			skill.print(scores);
		}
	}

	// Feats
	if (!feats.empty()) {
		std::cout << "\n--- Feats ---\n";
		for (const auto& feat : feats) {
			feat.print();
		}
	}

	// Spells
	if (!spells.empty()) {
		std::cout << "\n--- Spells ---\n";
		for (const auto& spell : spells) {
			spell.print();
		}
	}
}