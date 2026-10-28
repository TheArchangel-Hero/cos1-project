#include <iostream>
#include "Skill.h"

// Switch for each key Ability Score.
int Skill::getAbilityMod(const AbilityScores& abilities) const {
	switch (keyAbility) {
	case KeyAbility::Strength:
		return abilities.getStrMod();
	case KeyAbility::Dexterity:
		return abilities.getDexMod();
	case KeyAbility::Constitution:
		return abilities.getConMod();
	case KeyAbility::Intelligence:
		return abilities.getIntMod();
	case KeyAbility::Wisdom:
		return abilities.getWisMod();
	case KeyAbility::Charisma:
		return abilities.getChaMod();
	default: return 0;
	}
}

// Total Skill modifier is key Ability Score modifier + ranks (+3 if class skill and has at least 1 rank) + miscBonus.
int Skill::getTotal(const AbilityScores& abilities) const {
	int total = getAbilityMod(abilities) + ranks + miscBonus;

	if (isClassSkill && ranks > 0) {
		total += 3;
	}

	return total;
}

// Print Skill modifier. If skill is trained only, print [Trained Only].
void Skill::print(const AbilityScores& abilities) const {
	std::cout << name << ": " << getTotal(abilities);
	if (trainedOnly && ranks == 0) std::cout << " [Trained Only]";
	std::cout << "\n";
}