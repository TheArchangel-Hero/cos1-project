#pragma once
#include <string>
#include <vector>
#include "AbilityScores.h"

class Race {
private:
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

	// Base move speed (in feet, not squares)
	// Default is 30
	int baseSpeed = 30;

	// Starting languages
	std::vector<std::string> languages;

	// Racial Traits
	// These are descriptions for now. Mechanical effects will be added as if statements later.
	std::vector<std::string> traits;

public:
	// Size. Core Races can me small or medium. Large is included in case additional races are added later.
	// Default is medium
	enum class Size {
		Small, Medium, Large
	};
	Size size = Size::Medium;


	// Getters
	std::string getName() const {
		return name;
	}
	int getStrMod() const {
		return strMod;
	}
	int getDexMod() const {
		return dexMod;
	}
	int getConMod() const {
		return conMod;
	}
	int getIntMod() const {
		return intMod;
	}
	int getWisMod() const {
		return wisMod;
	}
	int getChaMod() const {
		return chaMod;
	}
	Size getSize() const {
		return size;
	}
	int getBaseSpeed() const {
		return baseSpeed;
	}
	const std::vector<std::string>& getLanguages() const {
		return languages;
	}
	const std::vector<std::string>& getTraits() const {
		return traits;
	}

	// Setters
	void setName(const std::string& n) {
		name = n;
	}
	void setStrMod(int mod) {
		strMod = mod;
	}
	void setDexMod(int mod) {
		dexMod = mod;
	}
	void setConMod(int mod) {
		conMod = mod;
	}
	void setIntMod(int mod) {
		intMod = mod;
	}
	void setWisMod(int mod) {
		wisMod = mod;
	}
	void setChaMod(int mod) {
		chaMod = mod;
	}
	void setSize(Size newSize) {
		size = newSize;
	}
	void setBaseSpeed(int speed) {
		baseSpeed = speed;
	}
	void setLanguages(const std::vector<std::string>& newLanguages) {
		languages = newLanguages;
	}
	void addLangauge(const std::string& newLanguage) {
		languages.push_back(newLanguage);
	}
	void setTraits(const std::vector<std::string>& newTraits) {
		traits = newTraits;
	}
	void addTrait(const std::string& newTrait) {
		traits.push_back(newTrait);
	}

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
