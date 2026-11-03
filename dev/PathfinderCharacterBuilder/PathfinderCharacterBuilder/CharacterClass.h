#pragma once
#include <string>
#include <vector>

class CharacterClass {
public:
	// To maintain organization structure across classes, these enumerators needed to be defined before they were utilized in the private section
	enum class BABProgression {
		Full, ThreeQuarter, Half
	};
	enum class SaveProgression {
		Good, Poor
	};

private:
	// Name of the class
	std::string name;

	// Number of faces for Hit die
	// Default is 8, as d8 is most common
	int hitDie = 8;

	// Base Attack Bonus (BAB) progression
	// Default is 3/4
	BABProgression bab = BABProgression::ThreeQuarter;

	// Saving Throw progression
	// Default is poor
	SaveProgression fortitudeSave = SaveProgression::Poor;
	SaveProgression reflexSave = SaveProgression::Poor;
	SaveProgression willSave = SaveProgression::Poor;

	// Skill Ranks per level
	// Default is 2, as it is the lowest listed value
	int skillRanksPerLevel = 2;

	// Class Skills
	// These recieve a +3 bonus to total Skill value as long as at least 1 Rank is assigned
	std::vector<std::string> classSkills;

	// Class Features
	// These are descriptions for now. Mechanical effects will be added as if statements later.
	// Note: Not to be confused with Feats
	std::vector<std::string> features;

public:
	// Getters
	std::string getName() const {
		return name;
	}
	int getHitDie() const {
		return hitDie;
	}
	BABProgression getBAB() const {
		return bab;
	}
	SaveProgression getFortitudeSave() const {
		return fortitudeSave;
	}
	SaveProgression getReflexSave() const {
		return reflexSave;
	}
	SaveProgression getWillSave() const {
		return willSave;
	}
	int getSkillRanksPerLevel() const {
		return skillRanksPerLevel;
	}
	const std::vector<std::string>& getClassSkills() const {
		return classSkills;
	}
	const std::vector<std::string>& getFeatures() const {
		return features;
	}

	// Setters
	void setName(const std::string& n) {
		name = n;
	}
	void setHitDie(int die) {
		hitDie = die;
	}
	void setBAB(BABProgression progression) {
		bab = progression;
	}
	void setFortitudeSave(SaveProgression save) {
		fortitudeSave = save;
	}
	void setReflexSave(SaveProgression save) {
		reflexSave = save;
	}
	void setWillSave(SaveProgression save) {
		willSave = save;
	}
	void setSkillRanksPerLevel(int ranks) {
		skillRanksPerLevel = ranks;
	}
	void setClassSkills(const std::vector<std::string>& skills) {
		classSkills = skills;
	}
	void addClassSkill(const std::string& skill) {
		classSkills.push_back(skill);
	}
	void setFeatures(const std::vector<std::string>& newFeatures) {
		features = newFeatures;
	}
	void addFeature(const std::string& feature) {
		features.push_back(feature);
	}

	// Print
	void print() const;
};

// Declaration of functions to apply CharacterClass templates
CharacterClass makeBarbarian();
CharacterClass makeBard();
CharacterClass makeCleric();
CharacterClass makeDruid();
CharacterClass makeFighter();
CharacterClass makeMonk();
CharacterClass makePaladin();
CharacterClass makeRanger();
CharacterClass makeRogue();
CharacterClass makeSorcerer();
CharacterClass makeWizard();