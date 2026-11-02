#pragma once
#include <iostream>

struct AbilityScores {

	// Ability Scores are set to default to 10.
	int strength = 10;
	int dexterity = 10;
	int constitution = 10;
	int intelligence = 10;
	int wisdom = 10;
	int charisma = 10;

	// Modifiers for each Ability Score are derived from the following formula:
	// (score - 10) / 2
	int getModifier(int score) const;
	int getStrMod() const;
	int getDexMod() const;
	int getConMod() const;
	int getIntMod() const;
	int getWisMod() const;
	int getChaMod() const;

	// Declaration for Print:
	void print() const;
};