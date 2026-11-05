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
// // Note: Currently only Spells beginning with A are implemented.
// TO DO: Implement remaining Spells
// A
Spell makeAcidArrow() {
	Spell spell;
	spell.setName("Acid Arrow");
	spell.setSchool(Spell::School::Conjuration);
	spell.setSpellLevel("Sorcerer", 2);
	spell.setSpellLevel("Wizard", 2);
	spell.setCastingTime("1 standard action");
	spell.setComponents("V, S, M (rhubarb leaf and an adder's stomach), F (a dart)");
	spell.setRange("long (400 ft. + 40 ft./level)");
	spell.setDuration("1 round + 1 round per three levels");
	spell.setSavingThrow("none");
	spell.setSpellResistance(false);
	spell.setDescription("Ranged touch attack deals 2d4 acid damage for 1 round + 1 round/3 levels.");
	return spell;
}
Spell makeAcidFog() {
    Spell spell;
    spell.setName("Acid Fog");
    spell.setSchool(Spell::School::Conjuration);
    spell.setSpellLevel("Sorcerer", 6);
    spell.setSpellLevel("Wizard", 6);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, M/DF");
    spell.setRange("Medium (100 ft. + 10 ft./level)");
    spell.setDuration("1 round/level");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("Fog deals 2d6 acid damage per round and slows creatures.");
    return spell;
}
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
Spell makeAid() {
    Spell spell;
    spell.setName("Aid");
    spell.setSchool(Spell::School::Enchantment);
    spell.setSpellLevel("Cleric", 2);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, DF");
    spell.setRange("Touch");
    spell.setDuration("1 min./level");
    spell.setSavingThrow("None");
    spell.setSpellResistance(true);
    spell.setDescription("+1 on attack rolls and saves against fear, plus 1d8 temporary hit points +1/level (max +10).");
    return spell;
}
Spell makeAirWalk() {
    Spell spell;
    spell.setName("Air Walk");
    spell.setSchool(Spell::School::Transmutation);
    spell.setSpellLevel("Cleric", 4);
    spell.setSpellLevel("Druid", 4);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, DF");
    spell.setRange("Touch");
    spell.setDuration("10 min./level");
    spell.setSavingThrow("None");
    spell.setSpellResistance(true);
    spell.setDescription("Subject treads on air as if solid (climb or descend at 45-degree angle).");
    return spell;
}
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
    spell.setDuration("2 hours/level");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("Wards an area for 2 hours/level. Mental or audible alarm when a creature enters.");
    return spell;
}
Spell makeAlignWeapon() {
    Spell spell;
    spell.setName("Align Weapon");
    spell.setSchool(Spell::School::Transmutation);
    spell.setSpellLevel("Cleric", 2);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, DF");
    spell.setRange("Touch");
    spell.setDuration("1 min./level");
    spell.setSavingThrow("Will negates (harmless, object)");
    spell.setSpellResistance(true);
    spell.setDescription("Weapon becomes chaotic, evil, good, or lawful.");
    return spell;
}
Spell makeAlterSelf() {
    Spell spell;
    spell.setName("Alter Self");
    spell.setSchool(Spell::School::Transmutation);
    spell.setSpellLevel("Bard", 2);
    spell.setSpellLevel("Sorcerer", 2);
    spell.setSpellLevel("Wizard", 2);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, M");
    spell.setRange("Personal");
    spell.setDuration("1 min./level");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("Assume the form of a Small or Medium humanoid.");
    return spell;
}
Spell makeAnalyzeDweomer() {
    Spell spell;
    spell.setName("Analyze Dweomer");
    spell.setSchool(Spell::School::Divination);
    spell.setSpellLevel("Sorcerer", 6);
    spell.setSpellLevel("Wizard", 6);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, F");
    spell.setRange("Close (25 ft. + 5 ft./2 levels)");
    spell.setDuration("1 round/level");
    spell.setSavingThrow("None or Will negates (see text)");
    spell.setSpellResistance(false);
    spell.setDescription("Reveals magical aspects of a creature or object.");
    return spell;
}
Spell makeAnimalGrowth() {
    Spell spell;
    spell.setName("Animal Growth");
    spell.setSchool(Spell::School::Transmutation);
    spell.setSpellLevel("Druid", 5);
    spell.setSpellLevel("Ranger", 4);
    spell.setSpellLevel("Sorcerer", 5);
    spell.setSpellLevel("Wizard", 5);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("Medium (100 ft. + 10 ft./level)");
    spell.setDuration("1 min./level");
    spell.setSavingThrow("Fortitude negates");
    spell.setSpellResistance(true);
    spell.setDescription("One animal/2 levels doubles in size and gains +8 Str, +4 Con, +2 natural armor.");
    return spell;
}
Spell makeAnimalMessenger() {
    Spell spell;
    spell.setName("Animal Messenger");
    spell.setSchool(Spell::School::Enchantment);
    spell.setSpellLevel("Bard", 2);
    spell.setSpellLevel("Druid", 2);
    spell.setSpellLevel("Ranger", 1);
    spell.setCastingTime("1 minute");
    spell.setComponents("V, S, M");
    spell.setRange("Close (25 ft. + 5 ft./2 levels)");
    spell.setDuration("1 day/level");
    spell.setSavingThrow("None");
    spell.setSpellResistance(true);
    spell.setDescription("Sends a Tiny animal to a specific place.");
    return spell;
}
Spell makeAnimalShapes() {
    Spell spell;
    spell.setName("Animal Shapes");
    spell.setSchool(Spell::School::Transmutation);
    spell.setSpellLevel("Druid", 8);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, DF");
    spell.setRange("Close (25 ft. + 5 ft./2 levels)");
    spell.setDuration("1 hour/level");
    spell.setSavingThrow("None");
    spell.setSpellResistance(true);
    spell.setDescription("One ally/level polymorphs into chosen animal.");
    return spell;
}
Spell makeAnimalTrance() {
    Spell spell;
    spell.setName("Animal Trance");
    spell.setSchool(Spell::School::Enchantment);
    spell.setSpellLevel("Bard", 2);
    spell.setSpellLevel("Druid", 2);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("Close (25 ft. + 5 ft./2 levels)");
    spell.setDuration("Concentration");
    spell.setSavingThrow("Will negates");
    spell.setSpellResistance(true);
    spell.setDescription("Fascinates 2d6 HD of animals.");
    return spell;
}
Spell makeAnimateDead() {
    Spell spell;
    spell.setName("Animate Dead");
    spell.setSchool(Spell::School::Necromancy);
    spell.setSpellLevel("Cleric", 3);
    spell.setSpellLevel("Sorcerer", 4);
    spell.setSpellLevel("Wizard", 4);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, M");
    spell.setRange("Touch");
    spell.setDuration("Instantaneous");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("Creates undead skeletons and zombies.");
    return spell;
}
Spell makeAnimateObjects() {
    Spell spell;
    spell.setName("Animate Objects");
    spell.setSchool(Spell::School::Transmutation);
    spell.setSpellLevel("Bard", 6);
    spell.setSpellLevel("Cleric", 6);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("Medium (100 ft. + 10 ft./level)");
    spell.setDuration("1 round/level");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("Objects attack your foes.");
    return spell;
}
Spell makeAnimatePlants() {
    Spell spell;
    spell.setName("Animate Plants");
    spell.setSchool(Spell::School::Transmutation);
    spell.setSpellLevel("Druid", 7);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V");
    spell.setRange("Close (25 ft. + 5 ft./2 levels)");
    spell.setDuration("1 round/level");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("One or more plants animate and fight for you.");
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
Spell makeAntilifeShell() {
    Spell spell;
    spell.setName("Antilife Shell");
    spell.setSchool(Spell::School::Abjuration);
    spell.setSpellLevel("Cleric", 6);
    spell.setSpellLevel("Druid", 6);
    spell.setCastingTime("1 round");
    spell.setComponents("V, S, DF");
    spell.setRange("10 ft.");
    spell.setDuration("1 min./level");
    spell.setSavingThrow("None");
    spell.setSpellResistance(true);
    spell.setDescription("10-ft.-radius field hedges out living creatures.");
    return spell;
}
Spell makeAntimagicField() {
    Spell spell;
    spell.setName("Antimagic Field");
    spell.setSchool(Spell::School::Abjuration);
    spell.setSpellLevel("Cleric", 8);
    spell.setSpellLevel("Sorcerer", 6);
    spell.setSpellLevel("Wizard", 6);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, M/DF");
    spell.setRange("10 ft.");
    spell.setDuration("10 min./level");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("Negates magic within 10 ft.");
    return spell;
}
Spell makeAntipathy() {
    Spell spell;
    spell.setName("Antipathy");
    spell.setSchool(Spell::School::Enchantment);
    spell.setSpellLevel("Druid", 9);
    spell.setSpellLevel("Sorcerer", 8);
    spell.setSpellLevel("Wizard", 8);
    spell.setCastingTime("1 hour");
    spell.setComponents("V, S, M/DF");
    spell.setRange("Close (25 ft. + 5 ft./2 levels)");
    spell.setDuration("2 hours/level");
    spell.setSavingThrow("Will partial");
    spell.setSpellResistance(true);
    spell.setDescription("Object or location affected by spell repels certain creatures.");
    return spell;
}
Spell makeAntiplantShell() {
    Spell spell;
    spell.setName("Antiplant Shell");
    spell.setSchool(Spell::School::Abjuration);
    spell.setSpellLevel("Druid", 4);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, DF");
    spell.setRange("10 ft.");
    spell.setDuration("1 min./level");
    spell.setSavingThrow("None");
    spell.setSpellResistance(true);
    spell.setDescription("Keeps animated plants at bay.");
    return spell;
}
Spell makeArcaneEye() {
    Spell spell;
    spell.setName("Arcane Eye");
    spell.setSchool(Spell::School::Divination);
    spell.setSpellLevel("Sorcerer", 4);
    spell.setSpellLevel("Wizard", 4);
    spell.setCastingTime("10 minutes");
    spell.setComponents("V, S, M");
    spell.setRange("Unlimited");
    spell.setDuration("1 min./level");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("Invisible floating eye moves 30 ft./round.");
    return spell;
}
Spell makeArcaneLock() {
    Spell spell;
    spell.setName("Arcane Lock");
    spell.setSchool(Spell::School::Abjuration);
    spell.setSpellLevel("Sorcerer", 2);
    spell.setSpellLevel("Wizard", 2);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S, M");
    spell.setRange("Touch");
    spell.setDuration("Permanent");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("Magically locks a portal or chest.");
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
Spell makeArcaneSight() {
    Spell spell;
    spell.setName("Arcane Sight");
    spell.setSchool(Spell::School::Divination);
    spell.setSpellLevel("Sorcerer", 3);
    spell.setSpellLevel("Wizard", 3);
    spell.setCastingTime("1 standard action");
    spell.setComponents("V, S");
    spell.setRange("Personal");
    spell.setDuration("1 min./level");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("Magical auras become visible to you.");
    return spell;
}
Spell makeAstralProjection() {
    Spell spell;
    spell.setName("Astral Projection");
    spell.setSchool(Spell::School::Necromancy);
    spell.setSpellLevel("Cleric", 9);
    spell.setSpellLevel("Sorcerer", 9);
    spell.setSpellLevel("Wizard", 9);
    spell.setCastingTime("30 minutes");
    spell.setComponents("V, S, M");
    spell.setRange("Touch");
    spell.setDuration("See text");
    spell.setSavingThrow("None");
    spell.setSpellResistance(true);
    spell.setDescription("Projects you and companions onto the Astral Plane.");
    return spell;
}
Spell makeAtonement() {
    Spell spell;
    spell.setName("Atonement");
    spell.setSchool(Spell::School::Abjuration);
    spell.setSpellLevel("Cleric", 5);
    spell.setCastingTime("1 hour");
    spell.setComponents("V, S, M, F, DF, XP");
    spell.setRange("Touch");
    spell.setDuration("Instantaneous");
    spell.setSavingThrow("None");
    spell.setSpellResistance(true);
    spell.setDescription("Removes burden of misdeeds from subject.");
    return spell;
}
Spell makeAugury() {
    Spell spell;
    spell.setName("Augury");
    spell.setSchool(Spell::School::Divination);
    spell.setSpellLevel("Cleric", 2);
    spell.setCastingTime("1 minute");
    spell.setComponents("V, S, M, F");
    spell.setRange("Personal");
    spell.setDuration("Instantaneous");
    spell.setSavingThrow("None");
    spell.setSpellResistance(false);
    spell.setDescription("Learns whether an action will be good or bad.");
    return spell;
}
Spell makeAwaken() {
    Spell spell;
    spell.setName("Awaken");
    spell.setSchool(Spell::School::Transmutation);
    spell.setSpellLevel("Druid", 5);
    spell.setCastingTime("24 hours");
    spell.setComponents("V, S, DF, M");
    spell.setRange("Touch");
    spell.setDuration("Instantaneous");
    spell.setSavingThrow("Will negates");
    spell.setSpellResistance(true);
    spell.setDescription("Animal or tree gains human-like intellect.");
    return spell;
}