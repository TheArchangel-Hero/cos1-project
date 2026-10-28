#include "AbilityScores.h"

// Getter for modifiers:
int AbilityScores::getModifier(int score) const {

	// Formula to derive modifier from score:
	return (score - 10) / 2;
}

// Getters for modifiers of each individual score:
int AbilityScores::getStrMod() const {
	return getModifier(strength);
}

int AbilityScores::getDexMod() const {
	return getModifier(dexterity);
}

int AbilityScores::getConMod() const {
	return getModifier(constitution);
}

int AbilityScores::getIntMod() const {
	return getModifier(intelligence);
}

int AbilityScores::getWisMod() const {
	return getModifier(wisdom);
}

int AbilityScores::getChaMod() const {
	return getModifier(charisma);
}

// Print
void AbilityScores::print() const {
	std::cout << "Strength: " << strength << " (" << getStrMod() << ")\n";
	std::cout << "Dexterity: " << dexterity << " (" << getDexMod() << ")\n";
	std::cout << "Constitution: " << constitution << " (" << getConMod() << ")\n";
	std::cout << "Intelligence: " << intelligence << " (" << getIntMod() << ")\n";
	std::cout << "Wisdom: " << wisdom << " (" << getWisMod() << ")\n";
	std::cout << "Charisma: " << charisma << " (" << getChaMod() << ")\n";
}