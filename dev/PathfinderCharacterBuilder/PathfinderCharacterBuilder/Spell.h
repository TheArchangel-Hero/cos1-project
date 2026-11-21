#pragma once
#include <string>
#include <map>

class Spell {
public:
	enum class School {
		Abjuration, Conjuration, Divination, Enchantment, Evocation, Illusion, Necromancy, Transmutation, Universal
	};

private:
	// Spell Name
	std::string name;

	// Spell School
	// Default is Abjuration, only because it is first alphabetically
	School school = School::Abjuration;

	// Casting time
	// Default is "1 standard action" as it is the most common
	std::string castingTime = "1 standard action";

	// Components
	// Verbal (V), Somatic (S) (gestures), Material (M) (items/ingredients), and Focus (F) (casting implement)
	std::string components;

	// Range of targeting/effect
	// Default is personal, as it is the lowest
	std::string range = "personal";

	// Duration of spell
	// Default is "instantaneous", as it is the shortest
	std::string duration = "instantaneous";

	// Saving Throw called for, if needed
	std::string savingThrow;

	// Spell Resistance, if applicaple
	// Default is false
	bool spellResistance = false;

	// Spell description/effect
	std::string description;

	// Spell level
	// This can be different depending on Spellcasting Class, hence map
	// Class name first, then level of the spell for that class
	std::map<std::string, int> spellLevel;

public:
	// Getters
	std::string getName() const {
		return name;
	}
	School getSchool() const {
		return school;
	}
	std::string getCastingTime() const {
		return castingTime;
	}
	std::string getComponents() const {
		return components;
	}
	std::string getRange() const {
		return range;
	}
	std::string getDuration() const {
		return duration;
	}
	std::string getSavingThrow() const {
		return savingThrow;
	}
	bool allowsSpellResistance() const {
		return spellResistance;
	}
	std::string getDescription() const {
		return description;
	}
	int getSpellLevel(const std::string& className) const;

	// Setters
	void setName(const std::string& n) {
		name = n;
	}
	void setSchool(School s) {
		school = s;
	}
	void setCastingTime(const std::string& t) {
		castingTime = t;
	}
	void setComponents(const std::string& c) {
		components = c;
	}
	void setRange(const std::string& r) {
		range = r;
	}
	void setDuration(const std::string& d) {
		duration = d;
	}
	void setSavingThrow(const std::string& s) {
		savingThrow = s;
	}
	void setSpellResistance(bool spellRes) {
		spellResistance = spellRes;
	}
	void setDescription(const std::string& desc) {
		description = desc;
	}
	void setSpellLevel(const std::string& className, int level);

	// Print
	void print() const;
};

// Declaration of functions to apply Spell templates
// Note: Only 0 and 1st level Spells are implemented
// 0 level
Spell makeAcidSplash();
Spell makeArcaneMark();
Spell makeBleed();
Spell makeCreateWater();
Spell makeDancingLights();
Spell makeDaze();
Spell makeDetectMagic();
Spell makeDetectPoison();
Spell makeDisruptUndead();
Spell makeFlare();
Spell makeGhostSound();
Spell makeGuidance();
Spell makeKnowDirection();
Spell makeLight();
Spell makeLullaby();
Spell makeMageHand();
Spell makeMending();
Spell makeMessage();
Spell makeOpenClose();
Spell makePrestidigitation();
Spell makePurifyFoodAndDrink();
Spell makeRayOfFrost();
Spell makeReadMagic();
Spell makeResistance();
Spell makeStabilize();
Spell makeSummonInstrument();
Spell makeTouchOfFatigue();
Spell makeVirtue();

// 1st level
Spell makeAlarm();
Spell makeAnimateRope();
Spell makeBane();
Spell makeBless();
Spell makeBlessWater();
Spell makeBlessWeapon();
Spell makeBurningHands();
Spell makeCalmAnimals();
Spell makeCauseFear();
Spell makeCharmAnimal();
Spell makeCharmPerson();
Spell makeChillTouch();
Spell makeColorSpray();
Spell makeCommand();
Spell makeComprehendLanguages();
Spell makeCureLightWounds();
Spell makeCurseWater();
Spell makeDeathwatch();
Spell makeDelayPoison();
Spell makeDetectAnimalsOrPlants();
Spell makeDetectSecretDoors();
Spell makeDetectSnaresAndPits();
Spell makeDetectUndead();
Spell makeDisguiseSelf();
Spell makeDivineFavor();
Spell makeDoom();
Spell makeEndureElements();
Spell makeEnlargePerson();
Spell makeEntangle();
Spell makeEntropicShield();
Spell makeExpeditiousRetreat();
Spell makeFaerieFire();
Spell makeFeatherFall();
Spell makeFloatingDisk();
Spell makeGoodberry();
Spell makeGrease();
Spell makeHideFromAnimals();
Spell makeHideFromUndead();
Spell makeHideousLaughter();
Spell makeHoldPortal();
Spell makeHypnotism();
Spell makeIdentify();
Spell makeInflictLightWounds();
Spell makeJump();
Spell makeLongstrider();
Spell makeMageArmor();
Spell makeMagicAura();
Spell makeMagicFang();
Spell makeMagicMissile();
Spell makeMagicMouth();
Spell makeMagicStone();
Spell makeMagicWeapon();
Spell makeMount();
Spell makeObscureObject();
Spell makeObscuringMist();
Spell makePassWithoutTrace();
Spell makeProduceFlame();
Spell makeProtectionFromChaos();
Spell makeProtectionFromEvil();
Spell makeProtectionFromGood();
Spell makeProtectionFromLaw();
Spell makeRayOfEnfeeblement();
Spell makeReducePerson();
Spell makeRemoveFear();
Spell makeSanctuary();
Spell makeShield();
Spell makeShieldOfFaith();
Spell makeShillelagh();
Spell makeShockingGrasp();
Spell makeSilentImage();
Spell makeSleep();
Spell makeSpeakWithAnimals();
Spell makeSummonMonsterI();
Spell makeSummonNaturesAllyI();
Spell makeTrueStrike();
Spell makeUndetectableAlignment();
Spell makeUnseenServant();
Spell makeVentriloquism();