#pragma once
#include <iostream>

class AbilityScores {
private:
	// Ability Scores are set to default to 10.
	int strength = 10;
	int dexterity = 10;
	int constitution = 10;
	int intelligence = 10;
	int wisdom = 10;
	int charisma = 10;

public:
	// Getters
	int getStrength() const {
		return strength;
	}
	int getDexterity() const {
		return dexterity;
	}
	int getConstitution() const {
		return constitution;
	}
	int getIntelligence() const {
		return intelligence;
	}
	int getWisdom() const {
		return wisdom;
	}
	int getCharisma() const {
		return charisma;
	}

	//Setters
	void setStrength(int value) {
		strength = value;
	}
	void setDexterity(int value) {
		dexterity = value;
	}
	void setConstitution(int value) {
		constitution = value;
	}
	void setIntelligence(int value) {
		intelligence = value;
	}
	void setWisdom(int value) {
		wisdom = value;
	}
	void setCharisma(int value) {
		charisma = value;
	}

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