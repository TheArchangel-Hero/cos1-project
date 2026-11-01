#pragma once
#include <string>
#include <vector>
#include "AbilityScores.h"

struct Race {
	// Name of the Race
	std::string name;

	// Ability score modifiers (can be positive, negative, or 0)
	// Default is 0
	int strMod = 0;
	int dexMod = 0;
	int conMod = 0;
	int intMod = 0;
	int wisMod = 0;
	int chaMod = 0;

	// Size. Core Races can me small or medium. Large is included in case additional races are added later.
	// Default is medium
	enum class Size {
		Small, Medium, Large
	}
	size = Size::Medium;

	// Base move speed (in feet, not squares)
	// Default is 30
	int baseSpeed = 30;

	// Staring languages
	std::vector<std::string> languages;

	// Racial Traits
	// These are descriptions for now. Mechanical effects will be added as if statements later
	std::vector<std::string> traits;

	// Method to apply racial ability modifiers to AbilityScores object
	void applyAbilityBonuses(AbilityScores& scores) const;

	// Print
	void print() const;
};

// Declaration of functions to apply Race templates
Race makeDwarf();
Race makeElf();
Race makeGnome();
Race makeHalfElf();
Race makeHalfOrc();
Race makeHalfling();
Race makeHuman();
