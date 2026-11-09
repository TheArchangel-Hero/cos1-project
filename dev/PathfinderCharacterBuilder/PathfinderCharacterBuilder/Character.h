#pragma once
#include <string>
#include <vector>
#include "AbilityScores.h"
#include "CharacterClass.h"
#include "Feat.h"
#include "Race.h"
#include "Skill.h"
#include "Spell.h"

// This will be the working storage for parameters drawn from the other classes during Creation
class Character {
private:
	std::string name;
	Race race;
	CharacterClass characterClass;
	AbilityScores scores;
	std::vector<Skill> skills;
	std::vector<Feat> feats;
	std::vector<Spell> spells;
	// A boolean to allow for an error return if a Character hasn't been created yet
	bool created = false;

public:
	// Getters
	bool isCreated() const {
		return created;
	}
	std::string getName() const {
		return name;
	}
	const Race& getRace() const {
		return race;
	}
	const CharacterClass& getClass() const {
		return characterClass;
	}
	const AbilityScores& getScores() const {
		return scores;
	}
	const std::vector<Skill>& getSkills() const {
		return skills;
	}
	const std::vector<Feat>& getFeats() const {
		return feats;
	}
	const std::vector<Spell>& getSpells() const {
		return spells;
	}

	// Setters
	void setName(const std::string& n) {
		name = n;
	}
	void setRace(const Race& r) {
		race = r;
	}
	void setClass(const CharacterClass& c) {
		characterClass = c;
	}
	void setScores(const AbilityScores& s) {
		scores = s;
	}
	void setSkills(const std::vector<Skill>& s) {
		skills = s;
	}
	void addSkill(const Skill& skill) {
		skills.push_back(skill);
	}
	void addFeat(const Feat& feat) {
		feats.push_back(feat);
	}
	void addSpell(const Spell& spell) {
		spells.push_back(spell);
	}
	void markCreated() {
		created = true;
	}

	// Print
	void print() const;
};