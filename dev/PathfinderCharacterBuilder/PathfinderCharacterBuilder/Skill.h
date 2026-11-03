#pragma once
#include <string>
#include "AbilityScores.h"

class Skill {
private:
	std::string name;
	
	// Skill ranks spent. Each increases value of skill modifier by 1.
	// TO DO: Maximum value is equal to Character Level. Minimum is 0.
	int ranks = 0;

	// Bonuses/Penalties from variable locations, such as racial traits or equipment.
	int miscBonus = 0;

	// Class skills grant a +3 bonus as long as rank is at least 1.
	bool isClassSkill = false;

	// Trained-only skills can only be used as long as rank is at least 1.
	bool trainedOnly = false;

public:
	// Each skill is tied to a key Ability Score
	enum class KeyAbility {
		Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma
	};
	// The majority of skills are tied to Intelligence, so it is set as default.
	KeyAbility keyAbility = KeyAbility::Intelligence;

	//Getters
	std::string getName() const {
		return name;
	}
	int getRanks() const {
		return ranks;
	}
	int getMiscBonus() const {
		return miscBonus;
	}
	bool getClassSkill() const {
		return isClassSkill;
	}
	bool getTrainedOnly() const {
		return trainedOnly;
	}

	//Setter
	void setName(const std::string& n) {
		name = n;
	}
	bool setRanks(int newRanks, int maxRanks);
	void setMiscBonus(int bonus) {
		miscBonus = bonus;
	}
	void setClassSkill(bool value) {
		isClassSkill = value;
	}
	void setTrainedOnly(bool value) {
		trainedOnly = value;
	}
	void setKeyAbility(KeyAbility ability) {
		keyAbility = ability;
	}

	// Each skill will need its total modifier value calculated.
	int getTotal(const AbilityScores& abilities) const;

	// Way to derive only the modifier from Ability Scores.
	int getAbilityMod(const AbilityScores& abilities) const;

	// Print.
	void print(const AbilityScores& abilities) const;
};