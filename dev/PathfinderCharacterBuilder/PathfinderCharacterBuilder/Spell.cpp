#include "Spell.h"
#include <iostream>

// Function to determine spell level
// Will return -1 if not on Spellcasting Class's list
int Spell::getSpellLevel(const std::string& className) const {
	auto it = spellLevel.find(className);
	if (it != spellLevel.end()) {
		return it->second;
	}
	return -1;
}

// Function to set spell level by Spellcasting Class
void Spell::setSpellLevel(const std::string& className, int level) {
	spellLevel[className] = level;
}

// Print
void Spell::print() const {
	// Name
	std::cout << name << "\n";

	// School
	std::cout << "  School: ";
	switch (school) {
	case School::Abjuration:
		std::cout << "Abjuration";
		break;
	case School::Conjuration:
		std::cout << "Conjuration";
		break;
	case School::Divination:
		std::cout << "Divination";
		break;
	case School::Enchantment:
		std::cout << "Enchantment";
		break;
	case School::Evocation:
		std::cout << "Evocation";
		break;
	case School::Illusion:
		std::cout << "Illusion";
		break;
	case School::Necromancy:
		std::cout << "Necromancy";
		break;
	case School::Transmutation:
		std::cout << "Transmutation";
		break;
	case School::Universal:
		std::cout << "Universal";
		break;
	}
	std::cout << "\n";

	// Spell Level
	if (!spellLevel.empty()) {
		std::cout << "  Level: ";
		bool first = true;
		for (const auto& pair : spellLevel) {
			if (!first) std::cout << ", ";
			std::cout << pair.first << " " << pair.second;
			first = false;
		}
		std::cout << "\n";
	}

	// Casting Time
	std::cout << "  Casting Time: " << castingTime << "\n";

	// Range
	if (!range.empty()) std::cout << "  Range: " << range << "\n";

	// Duration
	if (!duration.empty()) std::cout << "  Duration: " << duration << "\n";

	// Saving Throw
	if (!savingThrow.empty()) std::cout << "  Saving Throw: " << savingThrow << "\n";

	// Spell Resistance
	std::cout << "  Spell Resistance: " << (spellResistance ? "Yes" : "No") << "\n";

	// Description/Effect
	if (!description.empty()) {
		std::cout << "  Description: " << description << "\n";
	}
}

// Spell Template Functions
// // Note: Currently only 0 and 1st level Spells are implemented.
// 0 level
Spell makeAcidSplash() {
    Spell spell;
    spell.setName("Acid Splash");
    spell.setSchool(Spell::School::Conjuration);
    spell.setSpellLevel("Sorcerer", 0);
    spell.setSpellLevel("Wizard", 0);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("Close (25 ft. + 5 ft./2 levels)");
    spell.setDuration("Instantaneous");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("Ranged touch attack deals 1d3 acid damage.");
    return spell;
}

Spell makeArcaneMark() {
    Spell spell;
    spell.setName("Arcane Mark");
    spell.setSchool(Spell::School::Universal);
    spell.setSpellLevel("Sorcerer", 0);
    spell.setSpellLevel("Wizard", 0);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("Touch");
    spell.setDuration("Permanent");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("Inscribes a personal rune (visible or invisible).");
    return spell;
}

Spell makeBleed() {
    Spell spell;
    spell.setName("Bleed");
    spell.setSchool(Spell::School::Necromancy);
    spell.setSpellLevel("Cleric", 0);
    spell.setSpellLevel("Sorcerer", 0);
    spell.setSpellLevel("Wizard", 0);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("Close (25 ft. + 5 ft./2 levels)");
    spell.setDuration("Instantaneous");
    spell.setSavingThrow("Will negates");
    spell.setSpellResistance(true);
    spell.setDescription("Cause a stabilized creature to resume dying.");
    return spell;
}

Spell makeCreateWater() {
    Spell spell;
    spell.setName("Create Water");
    spell.setSchool(Spell::School::Conjuration);
    spell.setSpellLevel("Cleric", 0);
    spell.setSpellLevel("Druid", 0);
    spell.setSpellLevel("Paladin", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("Close (25 ft. + 5 ft./2 levels)");
    spell.setDuration("Instantaneous");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("Creates 2 gallons/level of pure water.");
    return spell;
}

Spell makeDancingLights() {
    Spell spell;
    spell.setName("Dancing Lights");
    spell.setSchool(Spell::School::Evocation);
    spell.setSpellLevel("Bard", 0);
    spell.setSpellLevel("Sorcerer", 0);
    spell.setSpellLevel("Wizard", 0);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("Medium (100 ft. + 10 ft./level)");
    spell.setDuration("1 minute");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("Creates torches or other lights.");
    return spell;
}

Spell makeDaze() {
    Spell spell;
    spell.setName("Daze");
    spell.setSchool(Spell::School::Enchantment);
    spell.setSpellLevel("Bard", 0);
    spell.setSpellLevel("Sorcerer", 0);
    spell.setSpellLevel("Wizard", 0);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, M");
    spell.setRange("Close (25 ft. + 5 ft./2 levels)");
    spell.setDuration("1 round");
    spell.setSavingThrow("Will negates");
    spell.setSpellResistance(true);
    spell.setDescription("Humanoid creature of 4 HD or less loses next action.");
    return spell;
}

Spell makeDetectMagic() {
    Spell spell;
    spell.setName("Detect Magic");
    spell.setSchool(Spell::School::Divination);
    spell.setSpellLevel("Bard", 0);
    spell.setSpellLevel("Cleric", 0);
    spell.setSpellLevel("Druid", 0);
    spell.setSpellLevel("Sorcerer", 0);
    spell.setSpellLevel("Wizard", 0);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("60 ft.");
    spell.setDuration("Concentration, up to 1 min./level (D)");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("Detects spells and magic items within 60 ft.");
    return spell;
}

Spell makeDetectPoison() {
    Spell spell;
    spell.setName("Detect Poison");
    spell.setSchool(Spell::School::Divination);
    spell.setSpellLevel("Cleric", 0);
    spell.setSpellLevel("Druid", 0);
    spell.setSpellLevel("Paladin", 1);
    spell.setSpellLevel("Ranger", 1);
    spell.setSpellLevel("Sorcerer", 0);
    spell.setSpellLevel("Wizard", 0);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("Close (25 ft. + 5 ft./2 levels)");
    spell.setDuration("Instantaneous");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("Detects poison in one creature or small object.");
    return spell;
}

Spell makeDisruptUndead() {
    Spell spell;
    spell.setName("Disrupt Undead");
    spell.setSchool(Spell::School::Necromancy);
    spell.setSpellLevel("Sorcerer", 0);
    spell.setSpellLevel("Wizard", 0);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("Close (25 ft. + 5 ft./2 levels)");
    spell.setDuration("Instantaneous");
    return spell;
}

Spell makeFlare() {
    Spell spell;
    spell.setName("Flare");
    spell.setSchool(Spell::School::Evocation);
    spell.setSpellLevel("Bard", 0);
    spell.setSpellLevel("Druid", 0);
    spell.setSpellLevel("Sorcerer", 0);
    spell.setSpellLevel("Wizard", 0);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V");
    spell.setRange("Close (25 ft. + 5 ft./2 levels)");
    spell.setDuration("Instantaneous");
    spell.setSavingThrow("Fortitude negates");
    spell.setSpellResistance(true);
    spell.setDescription("Dazzles one creature (-1 on attack rolls).");
    return spell;
}

Spell makeGhostSound() {
    Spell spell;
    spell.setName("Ghost Sound");
    spell.setSchool(Spell::School::Illusion);
    spell.setSpellLevel("Bard", 0);
    spell.setSpellLevel("Sorcerer", 0);
    spell.setSpellLevel("Wizard", 0);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, M");
    spell.setRange("Close (25 ft. + 5 ft./2 levels)");
    spell.setDuration("1 round/level (D)");
    spell.setSavingThrow("Will disbelief");
    spell.setSpellResistance(false);
    spell.setDescription("Figment sounds.");
    return spell;
}

Spell makeGuidance() {
    Spell spell;
    spell.setName("Guidance");
    spell.setSchool(Spell::School::Divination);
    spell.setSpellLevel("Cleric", 0);
    spell.setSpellLevel("Druid", 0);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("Touch");
    spell.setDuration("1 minute or until discharged");
    spell.setSavingThrow("Will negates (harmless)");
    spell.setSpellResistance(true);
    spell.setDescription("+1 on one attack roll, saving throw, or skill check.");
    return spell;
}

Spell makeKnowDirection() {
    Spell spell;
    spell.setName("Know Direction");
    spell.setSchool(Spell::School::Divination);
    spell.setSpellLevel("Bard", 0);
    spell.setSpellLevel("Druid", 0);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("Personal");
    spell.setDuration("Instantaneous");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("You discern north.");
    return spell;
}

Spell makeLight() {
    Spell spell;
    spell.setName("Light");
    spell.setSchool(Spell::School::Evocation);
    spell.setSpellLevel("Bard", 0);
    spell.setSpellLevel("Cleric", 0);
    spell.setSpellLevel("Druid", 0);
    spell.setSpellLevel("Sorcerer", 0);
    spell.setSpellLevel("Wizard", 0);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, M/DF");
    spell.setRange("Touch");
    spell.setDuration("10 min./level");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("Object shines like a torch.");
    return spell;
}

Spell makeLullaby() {
    Spell spell;
    spell.setName("Lullaby");
    spell.setSchool(Spell::School::Enchantment);
    spell.setSpellLevel("Bard", 0);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("Medium (100 ft. + 10 ft./level)");
    spell.setDuration("Concentration + 1 round/level (D)");
    spell.setSavingThrow("Will negates");
    spell.setSpellResistance(true);
    spell.setDescription("Makes subject drowsy; -5 on Perception checks, -2 on Will saves against sleep.");
    return spell;
}

Spell makeMageHand() {
    Spell spell;
    spell.setName("Mage Hand");
    spell.setSchool(Spell::School::Transmutation);
    spell.setSpellLevel("Bard", 0);
    spell.setSpellLevel("Sorcerer", 0);
    spell.setSpellLevel("Wizard", 0);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("Close (25 ft. + 5 ft./2 levels)");
    spell.setDuration("Concentration");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("5-pound telekinesis.");
    return spell;
}

Spell makeMending() {
    Spell spell;
    spell.setName("Mending");
    spell.setSchool(Spell::School::Transmutation);
    spell.setSpellLevel("Bard", 0);
    spell.setSpellLevel("Cleric", 0);
    spell.setSpellLevel("Druid", 0);
    spell.setSpellLevel("Sorcerer", 0);
    spell.setSpellLevel("Wizard", 0);
    spell.setCastingTime("10 minutes");
    spell.setComponents("V, S");
    spell.setRange("10 ft.");
    spell.setDuration("Instantaneous");
    spell.setSavingThrow("Will negates (harmless, object)");
    spell.setSpellResistance(true);
    spell.setDescription("Makes minor repairs on an object.");
    return spell;
}

Spell makeMessage() {
    Spell spell;
    spell.setName("Message");
    spell.setSchool(Spell::School::Transmutation);
    spell.setSpellLevel("Bard", 0);
    spell.setSpellLevel("Sorcerer", 0);
    spell.setSpellLevel("Wizard", 0);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, F");
    spell.setRange("Medium (100 ft. + 10 ft./level)");
    spell.setDuration("10 min./level");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("Whisper conversation at distance.");
    return spell;
}

Spell makeOpenClose() {
    Spell spell;
    spell.setName("Open/Close");
    spell.setSchool(Spell::School::Transmutation);
    spell.setSpellLevel("Bard", 0);
    spell.setSpellLevel("Sorcerer", 0);
    spell.setSpellLevel("Wizard", 0);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, F");
    spell.setRange("Close (25 ft. + 5 ft./2 levels)");
    spell.setDuration("Instantaneous");
    spell.setSavingThrow("Will negates (object)");
    spell.setSpellResistance(true);
    spell.setDescription("Opens or closes small or light things.");
    return spell;
}

Spell makePrestidigitation() {
    Spell spell;
    spell.setName("Prestidigitation");
    spell.setSchool(Spell::School::Universal);
    spell.setSpellLevel("Bard", 0);
    spell.setSpellLevel("Sorcerer", 0);
    spell.setSpellLevel("Wizard", 0);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("10 ft.");
    spell.setDuration("1 hour");
    spell.setSavingThrow("See text");
    spell.setSpellResistance(false);
    spell.setDescription("Performs minor tricks.");
    return spell;
}

Spell makePurifyFoodAndDrink() {
    Spell spell;
    spell.setName("Purify Food and Drink");
    spell.setSchool(Spell::School::Transmutation);
    spell.setSpellLevel("Cleric", 0);
    spell.setSpellLevel("Druid", 0);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("10 ft.");
    spell.setDuration("Instantaneous");
    spell.setSavingThrow("Will negates (object)");
    spell.setSpellResistance(true);
    spell.setDescription("Purifies 1 cu. ft./level of food or water.");
    return spell;
}

Spell makeRayOfFrost() {
    Spell spell;
    spell.setName("Ray of Frost");
    spell.setSchool(Spell::School::Evocation);
    spell.setSpellLevel("Sorcerer", 0);
    spell.setSpellLevel("Wizard", 0);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("Close (25 ft. + 5 ft./2 levels)");
    spell.setDuration("Instantaneous");
    spell.setSavingThrow("None");
    spell.setSpellResistance(true);
    spell.setDescription("Ray deals 1d3 cold damage.");
    return spell;
}

Spell makeReadMagic() {
    Spell spell;
    spell.setName("Read Magic");
    spell.setSchool(Spell::School::Divination);
    spell.setSpellLevel("Bard", 0);
    spell.setSpellLevel("Cleric", 0);
    spell.setSpellLevel("Druid", 0);
    spell.setSpellLevel("Paladin", 1);
    spell.setSpellLevel("Ranger", 1);
    spell.setSpellLevel("Sorcerer", 0);
    spell.setSpellLevel("Wizard", 0);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, F");
    spell.setRange("Personal");
    spell.setDuration("10 min./level");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("Read scrolls and spellbooks.");
    return spell;
}

Spell makeResistance() {
    Spell spell;
    spell.setName("Resistance");
    spell.setSchool(Spell::School::Abjuration);
    spell.setSpellLevel("Bard", 0);
    spell.setSpellLevel("Cleric", 0);
    spell.setSpellLevel("Druid", 0);
    spell.setSpellLevel("Paladin", 1);
    spell.setSpellLevel("Sorcerer", 0);
    spell.setSpellLevel("Wizard", 0);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, M/DF");
    spell.setRange("Touch");
    spell.setDuration("1 minute");
    spell.setSavingThrow("Will negates (harmless)");
    spell.setSpellResistance(true);
    spell.setDescription("Subject gains +1 on saving throws.");
    return spell;
}

Spell makeStabilize() {
    Spell spell;
    spell.setName("Stabilize");
    spell.setSchool(Spell::School::Conjuration);
    spell.setSpellLevel("Cleric", 0);
    spell.setSpellLevel("Druid", 0);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("Close (25 ft. + 5 ft./2 levels)");
    spell.setDuration("Instantaneous");
    spell.setSavingThrow("Will negates (harmless)");
    spell.setSpellResistance(true);
    spell.setDescription("Cause a dying creature to stabilize.");
    return spell;
}

Spell makeSummonInstrument() {
    Spell spell;
    spell.setName("Summon Instrument");
    spell.setSchool(Spell::School::Conjuration);
    spell.setSpellLevel("Bard", 0);
    spell.setCastingTime("1 round");
    spell.setComponents("V, S");
    spell.setRange("0 ft.");
    spell.setDuration("1 min./level (D)");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("Summons one musical instrument.");
    return spell;
}

Spell makeTouchOfFatigue() {
    Spell spell;
    spell.setName("Touch of Fatigue");
    spell.setSchool(Spell::School::Necromancy);
    spell.setSpellLevel("Sorcerer", 0);
    spell.setSpellLevel("Wizard", 0);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, M");
    spell.setRange("Touch");
    spell.setDuration("1 round/level");
    spell.setSavingThrow("Fortitude negates");
    spell.setSpellResistance(true);
    spell.setDescription("Touch attack fatigues target.");
    return spell;
}

Spell makeVirtue() {
    Spell spell;
    spell.setName("Virtue");
    spell.setSchool(Spell::School::Transmutation);
    spell.setSpellLevel("Cleric", 0);
    spell.setSpellLevel("Druid", 0);
    spell.setSpellLevel("Paladin", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, DF");
    spell.setRange("Touch");
    spell.setDuration("1 min.");
    spell.setSavingThrow("None");
    spell.setSpellResistance(true);
    spell.setDescription("Subject gains 1 temporary hit point.");
    return spell;
}

// 1st level
Spell makeAlarm() {
    Spell spell;
    spell.setName("Alarm");
    spell.setSchool(Spell::School::Abjuration);
    spell.setSpellLevel("Bard", 1);
    spell.setSpellLevel("Ranger", 1);
    spell.setSpellLevel("Sorcerer", 1);
    spell.setSpellLevel("Wizard", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, F/DF");
    spell.setRange("Close (25 ft. + 5 ft./2 levels)");
    spell.setDuration("2 hours/level (D)");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("Wards an area for 2 hours/level.");
    return spell;
}

Spell makeAnimateRope() {
    Spell spell;
    spell.setName("Animate Rope");
    spell.setSchool(Spell::School::Transmutation);
    spell.setSpellLevel("Bard", 1);
    spell.setSpellLevel("Sorcerer", 1);
    spell.setSpellLevel("Wizard", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("Medium (100 ft. + 10 ft./level)");
    spell.setDuration("1 round/level");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("Makes a rope move at your command.");
    return spell;
}

Spell makeBane() {
    Spell spell;
    spell.setName("Bane");
    spell.setSchool(Spell::School::Enchantment);
    spell.setSpellLevel("Cleric", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, DF");
    spell.setRange("50 ft.");
    spell.setDuration("1 min./level");
    spell.setSavingThrow("Will negates");
    spell.setSpellResistance(true);
    spell.setDescription("Enemies take -1 on attack rolls and saves against fear.");
    return spell;
}

Spell makeBless() {
    Spell spell;
    spell.setName("Bless");
    spell.setSchool(Spell::School::Enchantment);
    spell.setSpellLevel("Cleric", 1);
    spell.setSpellLevel("Paladin", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, DF");
    spell.setRange("50 ft.");
    spell.setDuration("1 min./level");
    spell.setSavingThrow("None");
    spell.setSpellResistance(true);
    spell.setDescription("Allies gain +1 on attack rolls and saves against fear.");
    return spell;
}

Spell makeBlessWater() {
    Spell spell;
    spell.setName("Bless Water");
    spell.setSchool(Spell::School::Transmutation);
    spell.setSpellLevel("Cleric", 1);
    spell.setSpellLevel("Paladin", 1);
    spell.setCastingTime("1 minute");
    spell.setComponents("V, S, M");
    spell.setRange("Touch");
    spell.setDuration("Instantaneous");
    spell.setSavingThrow("Will negates (object)");
    spell.setSpellResistance(true);
    spell.setDescription("Makes holy water.");
    return spell;
}

Spell makeBlessWeapon() {
    Spell spell;
    spell.setName("Bless Weapon");
    spell.setSchool(Spell::School::Transmutation);
    spell.setSpellLevel("Paladin", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("Touch");
    spell.setDuration("1 min./level");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("Weapon strikes true against evil foes.");
    return spell;
}

Spell makeBurningHands() {
    Spell spell;
    spell.setName("Burning Hands");
    spell.setSchool(Spell::School::Evocation);
    spell.setSpellLevel("Sorcerer", 1);
    spell.setSpellLevel("Wizard", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("15 ft.");
    spell.setDuration("Instantaneous");
    spell.setSavingThrow("Reflex half");
    spell.setSpellResistance(true);
    spell.setDescription("1d4 fire damage/level (max 5d4).");
    return spell;
}

Spell makeCalmAnimals() {
    Spell spell;
    spell.setName("Calm Animals");
    spell.setSchool(Spell::School::Enchantment);
    spell.setSpellLevel("Druid", 1);
    spell.setSpellLevel("Ranger", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("Close (25 ft. + 5 ft./2 levels)");
    spell.setDuration("1 min./level");
    spell.setSavingThrow("Will negates");
    spell.setSpellResistance(true);
    spell.setDescription("Calms 2d4 + level HD of animals.");
    return spell;
}

Spell makeCauseFear() {
    Spell spell;
    spell.setName("Cause Fear");
    spell.setSchool(Spell::School::Necromancy);
    spell.setSpellLevel("Bard", 1);
    spell.setSpellLevel("Cleric", 1);
    spell.setSpellLevel("Sorcerer", 1);
    spell.setSpellLevel("Wizard", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("Close (25 ft. + 5 ft./2 levels)");
    spell.setDuration("1d4 rounds or 1 round");
    spell.setSavingThrow("Will partial");
    spell.setSpellResistance(true);
    spell.setDescription("One creature of 5 HD or less flees for 1d4 rounds.");
    return spell;
}

Spell makeCharmAnimal() {
    Spell spell;
    spell.setName("Charm Animal");
    spell.setSchool(Spell::School::Enchantment);
    spell.setSpellLevel("Druid", 1);
    spell.setSpellLevel("Ranger", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("Close (25 ft. + 5 ft./2 levels)");
    spell.setDuration("1 hour/level");
    spell.setSavingThrow("Will negates");
    spell.setSpellResistance(true);
    spell.setDescription("Makes one animal your friend.");
    return spell;
}

Spell makeCharmPerson() {
    Spell spell;
    spell.setName("Charm Person");
    spell.setSchool(Spell::School::Enchantment);
    spell.setSpellLevel("Bard", 1);
    spell.setSpellLevel("Sorcerer", 1);
    spell.setSpellLevel("Wizard", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("Close (25 ft. + 5 ft./2 levels)");
    spell.setDuration("1 hour/level");
    spell.setSavingThrow("Will negates");
    spell.setSpellResistance(true);
    spell.setDescription("Makes one person your friend.");
    return spell;
}

Spell makeChillTouch() {
    Spell spell;
    spell.setName("Chill Touch");
    spell.setSchool(Spell::School::Necromancy);
    spell.setSpellLevel("Sorcerer", 1);
    spell.setSpellLevel("Wizard", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("Touch");
    spell.setDuration("Instantaneous");
    spell.setSavingThrow("Fortitude partial");
    spell.setSpellResistance(true);
    spell.setDescription("One touch/level deals 1d6 damage and possibly 1 Str damage.");
    return spell;
}

Spell makeColorSpray() {
    Spell spell;
    spell.setName("Color Spray");
    spell.setSchool(Spell::School::Illusion);
    spell.setSpellLevel("Sorcerer", 1);
    spell.setSpellLevel("Wizard", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, M");
    spell.setRange("15 ft.");
    spell.setDuration("Instantaneous");
    spell.setSavingThrow("Will negates");
    spell.setSpellResistance(true);
    spell.setDescription("Knocks unconscious, blinds, and/or stuns weak creatures.");
    return spell;
}

Spell makeCommand() {
    Spell spell;
    spell.setName("Command");
    spell.setSchool(Spell::School::Enchantment);
    spell.setSpellLevel("Cleric", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V");
    spell.setRange("Close (25 ft. + 5 ft./2 levels)");
    spell.setDuration("1 round");
    spell.setSavingThrow("Will negates");
    spell.setSpellResistance(true);
    spell.setDescription("One subject obeys selected command for 1 round.");
    return spell;
}

Spell makeComprehendLanguages() {
    Spell spell;
    spell.setName("Comprehend Languages");
    spell.setSchool(Spell::School::Divination);
    spell.setSpellLevel("Bard", 1);
    spell.setSpellLevel("Cleric", 1);
    spell.setSpellLevel("Sorcerer", 1);
    spell.setSpellLevel("Wizard", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, M/DF");
    spell.setRange("Personal");
    spell.setDuration("10 min./level");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("You understand all spoken and written languages.");
    return spell;
}

Spell makeCureLightWounds() {
    Spell spell;
    spell.setName("Cure Light Wounds");
    spell.setSchool(Spell::School::Conjuration);
    spell.setSpellLevel("Bard", 1);
    spell.setSpellLevel("Cleric", 1);
    spell.setSpellLevel("Druid", 1);
    spell.setSpellLevel("Paladin", 1);
    spell.setSpellLevel("Ranger", 2);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("Touch");
    spell.setDuration("Instantaneous");
    spell.setSavingThrow("Will half (harmless)");
    spell.setSpellResistance(true);
    spell.setDescription("Cures 1d8 damage + 1/level (max +5).");
    return spell;
}

Spell makeCurseWater() {
    Spell spell;
    spell.setName("Curse Water");
    spell.setSchool(Spell::School::Transmutation);
    spell.setSpellLevel("Cleric", 1);
    spell.setCastingTime("1 minute");
    spell.setComponents("V, S, M");
    spell.setRange("Touch");
    spell.setDuration("Instantaneous");
    spell.setSavingThrow("Will negates (object)");
    spell.setSpellResistance(true);
    spell.setDescription("Makes unholy water.");
    return spell;
}

Spell makeDeathwatch() {
    Spell spell;
    spell.setName("Deathwatch");
    spell.setSchool(Spell::School::Necromancy);
    spell.setSpellLevel("Cleric", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("30 ft.");
    spell.setDuration("10 min./level");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("Reveals how near death subjects within 30 ft. are.");
    return spell;
}

Spell makeDelayPoison() {
    Spell spell;
    spell.setName("Delay Poison");
    spell.setSchool(Spell::School::Conjuration);
    spell.setSpellLevel("Bard", 2);
    spell.setSpellLevel("Cleric", 2);
    spell.setSpellLevel("Druid", 2);
    spell.setSpellLevel("Paladin", 2);
    spell.setSpellLevel("Ranger", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, DF");
    spell.setRange("Touch");
    spell.setDuration("1 hour/level");
    spell.setSavingThrow("Fortitude negates (harmless)");
    spell.setSpellResistance(true);
    spell.setDescription("Stops poison from harming subject for 1 hour/level.");
    return spell;
}

Spell makeDetectAnimalsOrPlants() {
    Spell spell;
    spell.setName("Detect Animals or Plants");
    spell.setSchool(Spell::School::Divination);
    spell.setSpellLevel("Druid", 1);
    spell.setSpellLevel("Ranger", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("Long (400 ft. + 40 ft./level)");
    spell.setDuration("Concentration, up to 10 min./level (D)");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("Detects kinds of animals or plants.");
    return spell;
}

Spell makeDetectSecretDoors() {
    Spell spell;
    spell.setName("Detect Secret Doors");
    spell.setSchool(Spell::School::Divination);
    spell.setSpellLevel("Bard", 1);
    spell.setSpellLevel("Sorcerer", 1);
    spell.setSpellLevel("Wizard", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("60 ft.");
    spell.setDuration("Concentration, up to 1 min./level (D)");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("Reveals hidden doors within 60 ft.");
    return spell;
}

Spell makeDetectSnaresAndPits() {
    Spell spell;
    spell.setName("Detect Snares and Pits");
    spell.setSchool(Spell::School::Divination);
    spell.setSpellLevel("Druid", 1);
    spell.setSpellLevel("Ranger", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("60 ft.");
    spell.setDuration("Concentration, up to 10 min./level (D)");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("Reveals natural or primitive traps.");
    return spell;
}

Spell makeDetectUndead() {
    Spell spell;
    spell.setName("Detect Undead");
    spell.setSchool(Spell::School::Divination);
    spell.setSpellLevel("Cleric", 1);
    spell.setSpellLevel("Paladin", 1);
    spell.setSpellLevel("Sorcerer", 1);
    spell.setSpellLevel("Wizard", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, M/DF");
    spell.setRange("60 ft.");
    spell.setDuration("Concentration, up to 1 min./level (D)");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("Reveals undead within 60 ft.");
    return spell;
}

Spell makeDisguiseSelf() {
    Spell spell;
    spell.setName("Disguise Self");
    spell.setSchool(Spell::School::Illusion);
    spell.setSpellLevel("Bard", 1);
    spell.setSpellLevel("Sorcerer", 1);
    spell.setSpellLevel("Wizard", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("Personal");
    spell.setDuration("10 min./level (D)");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("Changes your appearance.");
    return spell;
}

Spell makeDivineFavor() {
    Spell spell;
    spell.setName("Divine Favor");
    spell.setSchool(Spell::School::Evocation);
    spell.setSpellLevel("Cleric", 1);
    spell.setSpellLevel("Paladin", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, DF");
    spell.setRange("Personal");
    spell.setDuration("1 minute");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("You gain +1 per three levels on attack and damage rolls.");
    return spell;
}

Spell makeDoom() {
    Spell spell;
    spell.setName("Doom");
    spell.setSchool(Spell::School::Necromancy);
    spell.setSpellLevel("Cleric", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, DF");
    spell.setRange("Medium (100 ft. + 10 ft./level)");
    spell.setDuration("1 min./level");
    spell.setSavingThrow("Will negates");
    spell.setSpellResistance(true);
    spell.setDescription("One subject takes -2 on attack rolls, damage rolls, saves, and checks.");
    return spell;
}

Spell makeEndureElements() {
    Spell spell;
    spell.setName("Endure Elements");
    spell.setSchool(Spell::School::Abjuration);
    spell.setSpellLevel("Cleric", 1);
    spell.setSpellLevel("Druid", 1);
    spell.setSpellLevel("Paladin", 1);
    spell.setSpellLevel("Ranger", 1);
    spell.setSpellLevel("Sorcerer", 1);
    spell.setSpellLevel("Wizard", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("Touch");
    spell.setDuration("24 hours");
    spell.setSavingThrow("Will negates (harmless)");
    spell.setSpellResistance(true);
    spell.setDescription("Exist comfortably in hot or cold environments.");
    return spell;
}

Spell makeEnlargePerson() {
    Spell spell;
    spell.setName("Enlarge Person");
    spell.setSchool(Spell::School::Transmutation);
    spell.setSpellLevel("Sorcerer", 1);
    spell.setSpellLevel("Wizard", 1);
    spell.setCastingTime("1 round");
    spell.setComponents("V, S, M");
    spell.setRange("Close (25 ft. + 5 ft./2 levels)");
    spell.setDuration("1 min./level (D)");
    spell.setSavingThrow("Fortitude negates");
    spell.setSpellResistance(true);
    spell.setDescription("Humanoid creature doubles in size.");
    return spell;
}

Spell makeEntangle() {
    Spell spell;
    spell.setName("Entangle");
    spell.setSchool(Spell::School::Transmutation);
    spell.setSpellLevel("Druid", 1);
    spell.setSpellLevel("Ranger", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, DF");
    spell.setRange("Long (400 ft. + 40 ft./level)");
    spell.setDuration("1 min./level (D)");
    spell.setSavingThrow("Reflex partial");
    spell.setSpellResistance(false);
    spell.setDescription("Plants entangle everyone in 40-ft. radius.");
    return spell;
}

Spell makeEntropicShield() {
    Spell spell;
    spell.setName("Entropic Shield");
    spell.setSchool(Spell::School::Abjuration);
    spell.setSpellLevel("Cleric", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("Personal");
    spell.setDuration("1 min./level (D)");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("Ranged attacks against you have 20% miss chance.");
    return spell;
}

Spell makeExpeditiousRetreat() {
    Spell spell;
    spell.setName("Expeditious Retreat");
    spell.setSchool(Spell::School::Transmutation);
    spell.setSpellLevel("Bard", 1);
    spell.setSpellLevel("Sorcerer", 1);
    spell.setSpellLevel("Wizard", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("Personal");
    spell.setDuration("1 min./level (D)");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("Your speed increases by 30 ft.");
    return spell;
}

Spell makeFaerieFire() {
    Spell spell;
    spell.setName("Faerie Fire");
    spell.setSchool(Spell::School::Evocation);
    spell.setSpellLevel("Druid", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, DF");
    spell.setRange("Long (400 ft. + 40 ft./level)");
    spell.setDuration("1 min./level (D)");
    spell.setSavingThrow("None");
    spell.setSpellResistance(true);
    spell.setDescription("Outlines subjects with light, canceling blur, concealment, etc.");
    return spell;
}

Spell makeFeatherFall() {
    Spell spell;
    spell.setName("Feather Fall");
    spell.setSchool(Spell::School::Transmutation);
    spell.setSpellLevel("Bard", 1);
    spell.setSpellLevel("Sorcerer", 1);
    spell.setSpellLevel("Wizard", 1);
    spell.setCastingTime("1 immediate action");
    spell.setComponents("V");
    spell.setRange("Close (25 ft. + 5 ft./2 levels)");
    spell.setDuration("Until landing or 1 round/level");
    spell.setSavingThrow("Will negates (harmless)");
    spell.setSpellResistance(true);
    spell.setDescription("Objects or creatures fall slowly.");
    return spell;
}

Spell makeFloatingDisk() {
    Spell spell;
    spell.setName("Floating Disk");
    spell.setSchool(Spell::School::Evocation);
    spell.setSpellLevel("Sorcerer", 1);
    spell.setSpellLevel("Wizard", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, M");
    spell.setRange("Close (25 ft. + 5 ft./2 levels)");
    spell.setDuration("1 hour/level");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("Creates 3-ft.-diameter horizontal disk that holds 100 lbs./level.");
    return spell;
}

Spell makeGoodberry() {
    Spell spell;
    spell.setName("Goodberry");
    spell.setSchool(Spell::School::Transmutation);
    spell.setSpellLevel("Druid", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, DF");
    spell.setRange("Touch");
    spell.setDuration("1 day/level");
    spell.setSavingThrow("None");
    spell.setSpellResistance(true);
    spell.setDescription("2d4 berries each cure 1 hp (max 8 hp/24 hours).");
    return spell;
}

Spell makeGrease() {
    Spell spell;
    spell.setName("Grease");
    spell.setSchool(Spell::School::Conjuration);
    spell.setSpellLevel("Bard", 1);
    spell.setSpellLevel("Sorcerer", 1);
    spell.setSpellLevel("Wizard", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, M");
    spell.setRange("Close (25 ft. + 5 ft./2 levels)");
    spell.setDuration("1 min./level (D)");
    spell.setSavingThrow("See text");
    spell.setSpellResistance(false);
    spell.setDescription("Makes 10-ft. square or one object slippery.");
    return spell;
}

Spell makeHideFromAnimals() {
    Spell spell;
    spell.setName("Hide from Animals");
    spell.setSchool(Spell::School::Abjuration);
    spell.setSpellLevel("Druid", 1);
    spell.setSpellLevel("Ranger", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("S, DF");
    spell.setRange("Touch");
    spell.setDuration("10 min./level (D)");
    spell.setSavingThrow("Will negates (harmless)");
    spell.setSpellResistance(true);
    spell.setDescription("Animals can't perceive one subject/level.");
    return spell;
}

Spell makeHideFromUndead() {
    Spell spell;
    spell.setName("Hide from Undead");
    spell.setSchool(Spell::School::Abjuration);
    spell.setSpellLevel("Cleric", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, DF");
    spell.setRange("Touch");
    spell.setDuration("10 min./level (D)");
    spell.setSavingThrow("Will negates (harmless)");
    spell.setSpellResistance(true);
    spell.setDescription("Undead can't perceive one subject/level.");
    return spell;
}

Spell makeHideousLaughter() {
    Spell spell;
    spell.setName("Hideous Laughter");
    spell.setSchool(Spell::School::Enchantment);
    spell.setSpellLevel("Bard", 1);
    spell.setSpellLevel("Sorcerer", 2);
    spell.setSpellLevel("Wizard", 2);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, M");
    spell.setRange("Close (25 ft. + 5 ft./2 levels)");
    spell.setDuration("1 round/level");
    spell.setSavingThrow("Will negates");
    spell.setSpellResistance(true);
    spell.setDescription("Subject loses actions for 1 round/level.");
    return spell;
}

Spell makeHoldPortal() {
    Spell spell;
    spell.setName("Hold Portal");
    spell.setSchool(Spell::School::Abjuration);
    spell.setSpellLevel("Sorcerer", 1);
    spell.setSpellLevel("Wizard", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V");
    spell.setRange("Medium (100 ft. + 10 ft./level)");
    spell.setDuration("1 min./level (D)");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("Holds door shut.");
    return spell;
}

Spell makeHypnotism() {
    Spell spell;
    spell.setName("Hypnotism");
    spell.setSchool(Spell::School::Enchantment);
    spell.setSpellLevel("Bard", 1);
    spell.setSpellLevel("Sorcerer", 1);
    spell.setSpellLevel("Wizard", 1);
    spell.setCastingTime("1 round");
    spell.setComponents("V, S");
    spell.setRange("Close (25 ft. + 5 ft./2 levels)");
    spell.setDuration("2d4 rounds (D)");
    spell.setSavingThrow("Will negates");
    spell.setSpellResistance(true);
    spell.setDescription("Fascinates 2d4 HD of creatures.");
    return spell;
}

Spell makeIdentify() {
    Spell spell;
    spell.setName("Identify");
    spell.setSchool(Spell::School::Divination);
    spell.setSpellLevel("Bard", 1);
    spell.setSpellLevel("Sorcerer", 1);
    spell.setSpellLevel("Wizard", 1);
    spell.setCastingTime("1 hour");
    spell.setComponents("V, S, M");
    spell.setRange("Touch");
    spell.setDuration("Instantaneous");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("Determines properties of magic item.");
    return spell;
}

Spell makeInflictLightWounds() {
    Spell spell;
    spell.setName("Inflict Light Wounds");
    spell.setSchool(Spell::School::Necromancy);
    spell.setSpellLevel("Cleric", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("Touch");
    spell.setDuration("Instantaneous");
    spell.setSavingThrow("Will half");
    spell.setSpellResistance(true);
    spell.setDescription("Touch deals 1d8 damage +1/level (max +5).");
    return spell;
}

Spell makeJump() {
    Spell spell;
    spell.setName("Jump");
    spell.setSchool(Spell::School::Transmutation);
    spell.setSpellLevel("Druid", 1);
    spell.setSpellLevel("Ranger", 1);
    spell.setSpellLevel("Sorcerer", 1);
    spell.setSpellLevel("Wizard", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, M");
    spell.setRange("Touch");
    spell.setDuration("1 min./level (D)");
    spell.setSavingThrow("Will negates (harmless)");
    spell.setSpellResistance(true);
    spell.setDescription("Subject gets bonus on Acrobatics checks.");
    return spell;
}

Spell makeLongstrider() {
    Spell spell;
    spell.setName("Longstrider");
    spell.setSchool(Spell::School::Transmutation);
    spell.setSpellLevel("Druid", 1);
    spell.setSpellLevel("Ranger", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, M");
    spell.setRange("Personal");
    spell.setDuration("1 hour/level (D)");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("Your speed increases by 10 ft.");
    return spell;
}

Spell makeMageArmor() {
    Spell spell;
    spell.setName("Mage Armor");
    spell.setSchool(Spell::School::Conjuration);
    spell.setSpellLevel("Sorcerer", 1);
    spell.setSpellLevel("Wizard", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, F");
    spell.setRange("Touch");
    spell.setDuration("1 hour/level (D)");
    spell.setSavingThrow("Will negates (harmless)");
    spell.setSpellResistance(false);
    spell.setDescription("Gives subject +4 armor bonus.");
    return spell;
}

Spell makeMagicAura() {
    Spell spell;
    spell.setName("Magic Aura");
    spell.setSchool(Spell::School::Illusion);
    spell.setSpellLevel("Bard", 1);
    spell.setSpellLevel("Sorcerer", 1);
    spell.setSpellLevel("Wizard", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, F");
    spell.setRange("Touch");
    spell.setDuration("1 day/level (D)");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("Alters object's magic aura.");
    return spell;
}

Spell makeMagicFang() {
    Spell spell;
    spell.setName("Magic Fang");
    spell.setSchool(Spell::School::Transmutation);
    spell.setSpellLevel("Druid", 1);
    spell.setSpellLevel("Ranger", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, DF");
    spell.setRange("Touch");
    spell.setDuration("1 min./level");
    spell.setSavingThrow("Will negates (harmless)");
    spell.setSpellResistance(true);
    spell.setDescription("One natural weapon of subject creature gets +1 on attack and damage rolls.");
    return spell;
}

Spell makeMagicMissile() {
    Spell spell;
    spell.setName("Magic Missile");
    spell.setSchool(Spell::School::Evocation);
    spell.setSpellLevel("Sorcerer", 1);
    spell.setSpellLevel("Wizard", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("Medium (100 ft. + 10 ft./level)");
    spell.setDuration("Instantaneous");
    spell.setSavingThrow("None");
    spell.setSpellResistance(true);
    spell.setDescription("1d4+1 damage; +1 missile per two levels above 1st (max 5).");
    return spell;
}

Spell makeMagicMouth() {
    Spell spell;
    spell.setName("Magic Mouth");
    spell.setSchool(Spell::School::Illusion);
    spell.setSpellLevel("Bard", 1);
    spell.setSpellLevel("Sorcerer", 2);
    spell.setSpellLevel("Wizard", 2);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, M");
    spell.setRange("Close (25 ft. + 5 ft./2 levels)");
    spell.setDuration("Permanent until discharged");
    spell.setSavingThrow("Will negates (object)");
    spell.setSpellResistance(true);
    spell.setDescription("Speaks once when triggered.");
    return spell;
}

Spell makeMagicStone() {
    Spell spell;
    spell.setName("Magic Stone");
    spell.setSchool(Spell::School::Transmutation);
    spell.setSpellLevel("Cleric", 1);
    spell.setSpellLevel("Druid", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, DF");
    spell.setRange("Touch");
    spell.setDuration("30 minutes or until discharged");
    spell.setSavingThrow("Will negates (harmless, object)");
    spell.setSpellResistance(true);
    spell.setDescription("Three stones gain +1 on attack, deal 1d6+1 damage.");
    return spell;
}

Spell makeMagicWeapon() {
    Spell spell;
    spell.setName("Magic Weapon");
    spell.setSchool(Spell::School::Transmutation);
    spell.setSpellLevel("Cleric", 1);
    spell.setSpellLevel("Paladin", 1);
    spell.setSpellLevel("Sorcerer", 1);
    spell.setSpellLevel("Wizard", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, DF");
    spell.setRange("Touch");
    spell.setDuration("1 min./level");
    spell.setSavingThrow("Will negates (harmless, object)");
    spell.setSpellResistance(true);
    spell.setDescription("Weapon gains +1 bonus.");
    return spell;
}

Spell makeMount() {
    Spell spell;
    spell.setName("Mount");
    spell.setSchool(Spell::School::Conjuration);
    spell.setSpellLevel("Sorcerer", 1);
    spell.setSpellLevel("Wizard", 1);
    spell.setCastingTime("1 round");
    spell.setComponents("V, S, M");
    spell.setRange("Close (25 ft. + 5 ft./2 levels)");
    spell.setDuration("2 hours/level (D)");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("Summons riding horse for 2 hours/level.");
    return spell;
}

Spell makeObscureObject() {
    Spell spell;
    spell.setName("Obscure Object");
    spell.setSchool(Spell::School::Abjuration);
    spell.setSpellLevel("Bard", 1);
    spell.setSpellLevel("Cleric", 3);
    spell.setSpellLevel("Sorcerer", 2);
    spell.setSpellLevel("Wizard", 2);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, M/DF");
    spell.setRange("Touch");
    spell.setDuration("8 hours (D)");
    spell.setSavingThrow("Will negates (object)");
    spell.setSpellResistance(true);
    spell.setDescription("Masks object against scrying.");
    return spell;
}

Spell makeObscuringMist() {
    Spell spell;
    spell.setName("Obscuring Mist");
    spell.setSchool(Spell::School::Conjuration);
    spell.setSpellLevel("Cleric", 1);
    spell.setSpellLevel("Druid", 1);
    spell.setSpellLevel("Sorcerer", 1);
    spell.setSpellLevel("Wizard", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("20 ft.");
    spell.setDuration("1 min./level");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("Fog surrounds you.");
    return spell;
}

Spell makePassWithoutTrace() {
    Spell spell;
    spell.setName("Pass without Trace");
    spell.setSchool(Spell::School::Transmutation);
    spell.setSpellLevel("Druid", 1);
    spell.setSpellLevel("Ranger", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, DF");
    spell.setRange("Touch");
    spell.setDuration("1 hour/level (D)");
    spell.setSavingThrow("Will negates (harmless)");
    spell.setSpellResistance(true);
    spell.setDescription("One subject/level leaves no tracks.");
    return spell;
}

Spell makeProduceFlame() {
    Spell spell;
    spell.setName("Produce Flame");
    spell.setSchool(Spell::School::Evocation);
    spell.setSpellLevel("Druid", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("0 ft.");
    spell.setDuration("1 min./level (D)");
    spell.setSavingThrow("None");
    spell.setSpellResistance(true);
    spell.setDescription("1d6 damage +1/level, touch or thrown.");
    return spell;
}

Spell makeProtectionFromChaos() {
    Spell spell;
    spell.setName("Protection from Chaos");
    spell.setSchool(Spell::School::Abjuration);
    spell.setSpellLevel("Cleric", 1);
    spell.setSpellLevel("Paladin", 1);
    spell.setSpellLevel("Sorcerer", 1);
    spell.setSpellLevel("Wizard", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, M/DF");
    spell.setRange("Touch");
    spell.setDuration("1 min./level (D)");
    spell.setSavingThrow("Will negates (harmless)");
    spell.setSpellResistance(false);
    spell.setDescription("+2 to AC and saves, counter mind control, hedge out elementals and outsiders.");
    return spell;
}

Spell makeProtectionFromEvil() {
    Spell spell;
    spell.setName("Protection from Evil");
    spell.setSchool(Spell::School::Abjuration);
    spell.setSpellLevel("Cleric", 1);
    spell.setSpellLevel("Paladin", 1);
    spell.setSpellLevel("Sorcerer", 1);
    spell.setSpellLevel("Wizard", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, M/DF");
    spell.setRange("Touch");
    spell.setDuration("1 min./level (D)");
    spell.setSavingThrow("Will negates (harmless)");
    spell.setSpellResistance(false);
    spell.setDescription("+2 to AC and saves, counter mind control, hedge out elementals and outsiders.");
    return spell;
}

Spell makeProtectionFromGood() {
    Spell spell;
    spell.setName("Protection from Good");
    spell.setSchool(Spell::School::Abjuration);
    spell.setSpellLevel("Cleric", 1);
    spell.setSpellLevel("Sorcerer", 1);
    spell.setSpellLevel("Wizard", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, M/DF");
    spell.setRange("Touch");
    spell.setDuration("1 min./level (D)");
    spell.setSavingThrow("Will negates (harmless)");
    spell.setSpellResistance(false);
    spell.setDescription("+2 to AC and saves, counter mind control, hedge out elementals and outsiders.");
    return spell;
}

Spell makeProtectionFromLaw() {
    Spell spell;
    spell.setName("Protection from Law");
    spell.setSchool(Spell::School::Abjuration);
    spell.setSpellLevel("Cleric", 1);
    spell.setSpellLevel("Sorcerer", 1);
    spell.setSpellLevel("Wizard", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, M/DF");
    spell.setRange("Touch");
    spell.setDuration("1 min./level (D)");
    spell.setSavingThrow("Will negates (harmless)");
    spell.setSpellResistance(false);
    spell.setDescription("+2 to AC and saves, counter mind control, hedge out elementals and outsiders.");
    return spell;
}

Spell makeRayOfEnfeeblement() {
    Spell spell;
    spell.setName("Ray of Enfeeblement");
    spell.setSchool(Spell::School::Necromancy);
    spell.setSpellLevel("Sorcerer", 1);
    spell.setSpellLevel("Wizard", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("Close (25 ft. + 5 ft./2 levels)");
    spell.setDuration("1 min./level");
    spell.setSavingThrow("Fortitude half");
    spell.setSpellResistance(true);
    spell.setDescription("Ray causes 1d6 Str penalty +1 per 2 levels.");
    return spell;
}

Spell makeReducePerson() {
    Spell spell;
    spell.setName("Reduce Person");
    spell.setSchool(Spell::School::Transmutation);
    spell.setSpellLevel("Sorcerer", 1);
    spell.setSpellLevel("Wizard", 1);
    spell.setCastingTime("1 round");
    spell.setComponents("V, S, M");
    spell.setRange("Close (25 ft. + 5 ft./2 levels)");
    spell.setDuration("1 min./level (D)");
    spell.setSavingThrow("Fortitude negates");
    spell.setSpellResistance(true);
    spell.setDescription("Humanoid creature halves in size.");
    return spell;
}

Spell makeRemoveFear() {
    Spell spell;
    spell.setName("Remove Fear");
    spell.setSchool(Spell::School::Abjuration);
    spell.setSpellLevel("Bard", 1);
    spell.setSpellLevel("Cleric", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("Close (25 ft. + 5 ft./2 levels)");
    spell.setDuration("10 minutes");
    spell.setSavingThrow("Will negates (harmless)");
    spell.setSpellResistance(true);
    spell.setDescription("Suppresses fear or gives +4 on saves against fear for one subject + one per four levels.");
    return spell;
}

Spell makeSanctuary() {
    Spell spell;
    spell.setName("Sanctuary");
    spell.setSchool(Spell::School::Abjuration);
    spell.setSpellLevel("Cleric", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, DF");
    spell.setRange("Touch");
    spell.setDuration("1 round/level");
    spell.setSavingThrow("Will negates");
    spell.setSpellResistance(false);
    spell.setDescription("Opponents can't attack you, and you can't attack.");
    return spell;
}

Spell makeShield() {
    Spell spell;
    spell.setName("Shield");
    spell.setSchool(Spell::School::Abjuration);
    spell.setSpellLevel("Sorcerer", 1);
    spell.setSpellLevel("Wizard", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("Personal");
    spell.setDuration("1 min./level (D)");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("Invisible disc gives +4 to AC, blocks magic missiles.");
    return spell;
}

Spell makeShieldOfFaith() {
    Spell spell;
    spell.setName("Shield of Faith");
    spell.setSchool(Spell::School::Abjuration);
    spell.setSpellLevel("Cleric", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, M");
    spell.setRange("Touch");
    spell.setDuration("1 min./level");
    spell.setSavingThrow("Will negates (harmless)");
    spell.setSpellResistance(true);
    spell.setDescription("Aura grants +2 or higher deflection bonus.");
    return spell;
}

Spell makeShillelagh() {
    Spell spell;
    spell.setName("Shillelagh");
    spell.setSchool(Spell::School::Transmutation);
    spell.setSpellLevel("Druid", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, DF");
    spell.setRange("Touch");
    spell.setDuration("1 min./level");
    spell.setSavingThrow("Will negates (object)");
    spell.setSpellResistance(true);
    spell.setDescription("Cudgel or quarterstaff becomes +1 weapon (1d8 damage) for 1 min./level.");
    return spell;
}

Spell makeShockingGrasp() {
    Spell spell;
    spell.setName("Shocking Grasp");
    spell.setSchool(Spell::School::Evocation);
    spell.setSpellLevel("Sorcerer", 1);
    spell.setSpellLevel("Wizard", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("Touch");
    spell.setDuration("Instantaneous");
    spell.setSavingThrow("None");
    spell.setSpellResistance(true);
    spell.setDescription("Touch delivers 1d6/level electricity damage (max 5d6).");
    return spell;
}

Spell makeSilentImage() {
    Spell spell;
    spell.setName("Silent Image");
    spell.setSchool(Spell::School::Illusion);
    spell.setSpellLevel("Bard", 1);
    spell.setSpellLevel("Sorcerer", 1);
    spell.setSpellLevel("Wizard", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, F");
    spell.setRange("Long (400 ft. + 40 ft./level)");
    spell.setDuration("Concentration");
    spell.setSavingThrow("Will disbelief (if interacted with)");
    spell.setSpellResistance(false);
    spell.setDescription("Creates minor illusion of your design.");
    return spell;
}

Spell makeSleep() {
    Spell spell;
    spell.setName("Sleep");
    spell.setSchool(Spell::School::Enchantment);
    spell.setSpellLevel("Bard", 1);
    spell.setSpellLevel("Sorcerer", 1);
    spell.setSpellLevel("Wizard", 1);
    spell.setCastingTime("1 round");
    spell.setComponents("V, S, M");
    spell.setRange("Medium (100 ft. + 10 ft./level)");
    spell.setDuration("1 min./level");
    spell.setSavingThrow("Will negates");
    spell.setSpellResistance(true);
    spell.setDescription("Puts 4 HD of creatures into magical slumber.");
    return spell;
}

Spell makeSpeakWithAnimals() {
    Spell spell;
    spell.setName("Speak with Animals");
    spell.setSchool(Spell::School::Divination);
    spell.setSpellLevel("Bard", 3);
    spell.setSpellLevel("Druid", 1);
    spell.setSpellLevel("Ranger", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("Personal");
    spell.setDuration("1 min./level");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("You can communicate with animals.");
    return spell;
}

Spell makeSummonMonsterI() {
    Spell spell;
    spell.setName("Summon Monster I");
    spell.setSchool(Spell::School::Conjuration);
    spell.setSpellLevel("Bard", 1);
    spell.setSpellLevel("Cleric", 1);
    spell.setSpellLevel("Sorcerer", 1);
    spell.setSpellLevel("Wizard", 1);
    spell.setCastingTime("1 round");
    spell.setComponents("V, S, F/DF");
    spell.setRange("Close (25 ft. + 5 ft./2 levels)");
    spell.setDuration("1 round/level (D)");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("Calls extraplanar creature to fight for you.");
    return spell;
}

Spell makeSummonNaturesAllyI() {
    Spell spell;
    spell.setName("Summon Nature's Ally I");
    spell.setSchool(Spell::School::Conjuration);
    spell.setSpellLevel("Druid", 1);
    spell.setSpellLevel("Ranger", 1);
    spell.setCastingTime("1 round");
    spell.setComponents("V, S, DF");
    spell.setRange("Close (25 ft. + 5 ft./2 levels)");
    spell.setDuration("1 round/level (D)");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("Calls creature to fight.");
    return spell;
}

Spell makeTrueStrike() {
    Spell spell;
    spell.setName("True Strike");
    spell.setSchool(Spell::School::Divination);
    spell.setSpellLevel("Sorcerer", 1);
    spell.setSpellLevel("Wizard", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, F");
    spell.setRange("Personal");
    spell.setDuration("See text");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("+20 on your next attack roll.");
    return spell;
}

Spell makeUndetectableAlignment() {
    Spell spell;
    spell.setName("Undetectable Alignment");
    spell.setSchool(Spell::School::Abjuration);
    spell.setSpellLevel("Bard", 1);
    spell.setSpellLevel("Cleric", 2);
    spell.setSpellLevel("Paladin", 2);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("Close (25 ft. + 5 ft./2 levels)");
    spell.setDuration("24 hours");
    spell.setSavingThrow("Will negates (object)");
    spell.setSpellResistance(true);
    spell.setDescription("Conceals alignment for 24 hours.");
    return spell;
}

Spell makeUnseenServant() {
    Spell spell;
    spell.setName("Unseen Servant");
    spell.setSchool(Spell::School::Conjuration);
    spell.setSpellLevel("Bard", 1);
    spell.setSpellLevel("Sorcerer", 1);
    spell.setSpellLevel("Wizard", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, M");
    spell.setRange("Close (25 ft. + 5 ft./2 levels)");
    spell.setDuration("1 hour/level");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("Invisible force obeys your commands.");
    return spell;
}

Spell makeVentriloquism() {
    Spell spell;
    spell.setName("Ventriloquism");
    spell.setSchool(Spell::School::Illusion);
    spell.setSpellLevel("Bard", 1);
    spell.setSpellLevel("Sorcerer", 1);
    spell.setSpellLevel("Wizard", 1);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, F");
    spell.setRange("Close (25 ft. + 5 ft./2 levels)");
    spell.setDuration("1 min./level (D)");
    spell.setSavingThrow("Will disbelief (if interacted with)");
    spell.setSpellResistance(false);
    spell.setDescription("Throws voice for 1 min./level.");
    return spell;
}