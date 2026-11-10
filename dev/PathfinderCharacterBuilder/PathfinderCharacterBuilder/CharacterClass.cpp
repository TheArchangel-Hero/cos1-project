#include "CharacterClass.h"
#include <iostream>

// Print
void CharacterClass::print() const {
	// Name
	std::cout << name << "\n";

	// Hit Die
	// Hit Die is presented in the form "dx" where d is short for die and x is the number of faces
	std::cout << "  Hit Die: d" << hitDie << "\n";

	// Base Attack Bonus (BAB)
	std::cout << "  BAB: ";
	switch (bab) {
	case BABProgression::Full:
		std::cout << "Full";
		break;
	case BABProgression::ThreeQuarter:
		std::cout << "3/4";
		break;
	case BABProgression::Half:
		std::cout << "1/2";
		break;
	}
	std::cout << "\n";

	// Saving Throws
	std::cout << "  Saves: Fortitude ";
	std::cout << (fortitudeSave == SaveProgression::Good ? "Good" : "Poor");
	std::cout << ", Reflex ";
	std::cout << (reflexSave == SaveProgression::Good ? "Good" : "Poor");
	std::cout << ", Will ";
	std::cout << (willSave == SaveProgression::Good ? "Good" : "Poor");
	std::cout << "\n";

	// Skill Ranks
	std::cout << "  Skill Ranks per Level: " << skillRanksPerLevel << "\n";

	// Class Skills
	if (!classSkills.empty()) {
		std::cout << "  Class Skills:\n";
		for (const auto& skill : classSkills) std::cout << "    - " << skill << "\n";
	}

	// Features
	if (!features.empty()) {
		std::cout << "  Features:\n";
		for (const auto& feature : features) std::cout << "    - " << feature << "\n";
	}
}

// CharacterClass Template Functions
CharacterClass makeBarbarian() {
    CharacterClass barbarian;
    barbarian.setName("Barbarian");
    barbarian.setHitDie(12);
    barbarian.setBAB(CharacterClass::BABProgression::Full);
    barbarian.setFortitudeSave(CharacterClass::SaveProgression::Good);
    barbarian.setReflexSave(CharacterClass::SaveProgression::Poor);
    barbarian.setWillSave(CharacterClass::SaveProgression::Poor);
    barbarian.setSkillRanksPerLevel(4);
    barbarian.setClassSkills({
        "Acrobatics", "Climb", "Craft", "Handle Animal", "Intimidate", "Knowledge (nature)", "Perception", "Ride", "Survival", "Swim"
        });
    barbarian.setFeatures({
        "Fast Movement", "Rage", "Uncanny Dodge", "Trap Sense", "Improved Uncanny Dodge", "Damage Reduction", "Greater Rage", "Indomitable Will", "Tireless Rage", "Mighty Rage"
        });
    return barbarian;
}

CharacterClass makeBard() {
    CharacterClass bard;
    bard.setName("Bard");
    bard.setHitDie(8);
    bard.setBAB(CharacterClass::BABProgression::ThreeQuarter);
    bard.setFortitudeSave(CharacterClass::SaveProgression::Poor);
    bard.setReflexSave(CharacterClass::SaveProgression::Good);
    bard.setWillSave(CharacterClass::SaveProgression::Good);
    bard.setSkillRanksPerLevel(6);
    bard.setClassSkills({
        "Acrobatics", "Appraise", "Bluff", "Climb", "Craft", "Diplomacy", "Disguise", "Escape Artist", "Intimidate", "Knowledge (all)", "Linguistics", "Perception", "Perform", "Profession", "Sense Motive", "Sleight of Hand", "Spellcraft", "Stealth", "Use Magic Device"
        });
    bard.setFeatures({
        "Bardic Knowledge", "Bardic Performance", "Cantrips", "Versatile Performance", "Well-Versed", "Lore Master", "Jack-of-All-Trades"
        });
    return bard;
}

CharacterClass makeCleric() {
    CharacterClass cleric;
    cleric.setName("Cleric");
    cleric.setHitDie(8);
    cleric.setBAB(CharacterClass::BABProgression::ThreeQuarter);
    cleric.setFortitudeSave(CharacterClass::SaveProgression::Good);
    cleric.setReflexSave(CharacterClass::SaveProgression::Poor);
    cleric.setWillSave(CharacterClass::SaveProgression::Good);
    cleric.setSkillRanksPerLevel(2);
    cleric.setClassSkills({
        "Appraise", "Craft", "Diplomacy", "Heal", "Knowledge (arcana)", "Knowledge (history)", "Knowledge (nobility)", "Knowledge (planes)", "Knowledge (religion)", "Linguistics", "Profession", "Sense Motive", "Spellcraft"
        });
    cleric.setFeatures({
        "Aura", "Channel Energy", "Domains", "Orisons", "Spontaneous Casting"
        });
    return cleric;
}

CharacterClass makeDruid() {
    CharacterClass druid;
    druid.setName("Druid");
    druid.setHitDie(8);
    druid.setBAB(CharacterClass::BABProgression::ThreeQuarter);
    druid.setFortitudeSave(CharacterClass::SaveProgression::Good);
    druid.setReflexSave(CharacterClass::SaveProgression::Poor);
    druid.setWillSave(CharacterClass::SaveProgression::Good);
    druid.setSkillRanksPerLevel(4);
    druid.setClassSkills({
        "Climb", "Craft", "Fly", "Handle Animal", "Heal", "Knowledge (geography)", "Knowledge (nature)", "Perception", "Profession", "Ride", "Spellcraft", "Survival", "Swim"
        });
    druid.setFeatures({
        "Nature Bond", "Nature Sense", "Wild Empathy", "Woodland Stride", "Trackless Step", "Resist Nature's Lure", "Wild Shape", "Venom Immunity", "A Thousand Faces", "Timeless Body"
        });
    return druid;
}

CharacterClass makeFighter() {
    CharacterClass fighter;
    fighter.setName("Fighter");
    fighter.setHitDie(10);
    fighter.setBAB(CharacterClass::BABProgression::Full);
    fighter.setFortitudeSave(CharacterClass::SaveProgression::Good);
    fighter.setReflexSave(CharacterClass::SaveProgression::Poor);
    fighter.setWillSave(CharacterClass::SaveProgression::Poor);
    fighter.setSkillRanksPerLevel(2);
    fighter.setClassSkills({
        "Climb", "Craft", "Handle Animal", "Intimidate", "Knowledge (engineering)", "Profession", "Ride", "Survival", "Swim"
        });
    fighter.setFeatures({
        "Bonus Feats", "Bravery", "Armor Training", "Weapon Training"
        });
    return fighter;
}

CharacterClass makeMonk() {
    CharacterClass monk;
    monk.setName("Monk");
    monk.setHitDie(8);
    monk.setBAB(CharacterClass::BABProgression::ThreeQuarter);
    monk.setFortitudeSave(CharacterClass::SaveProgression::Good);
    monk.setReflexSave(CharacterClass::SaveProgression::Good);
    monk.setWillSave(CharacterClass::SaveProgression::Good);
    monk.setSkillRanksPerLevel(4);
    monk.setClassSkills({
        "Acrobatics", "Climb", "Craft", "Escape Artist", "Intimidate", "Knowledge (history)", "Knowledge (religion)", "Perception", "Perform", "Profession", "Ride", "Sense Motive", "Stealth", "Swim"
        });
    monk.setFeatures({
        "AC Bonus", "Flurry of Blows", "Unarmed Strike", "Stunning Fist", "Evasion", "Fast Movement", "Maneuver Training", "Still Mind", "Ki Pool", "Slow Fall", "High Jump", "Purity of Body", "Wholeness of Body", "Improved Evasion", "Diamond Body", "Abundant Step", "Diamond Soul", "Quivering Palm", "Timeless Body", "Tongue of the Sun and Moon", "Empty Body", "Perfect Self"
        });
    return monk;
}

CharacterClass makePaladin() {
    CharacterClass paladin;
    paladin.setName("Paladin");
    paladin.setHitDie(10);
    paladin.setBAB(CharacterClass::BABProgression::Full);
    paladin.setFortitudeSave(CharacterClass::SaveProgression::Good);
    paladin.setReflexSave(CharacterClass::SaveProgression::Poor);
    paladin.setWillSave(CharacterClass::SaveProgression::Good);
    paladin.setSkillRanksPerLevel(2);
    paladin.setClassSkills({
        "Craft", "Diplomacy", "Handle Animal", "Heal", "Knowledge (nobility)", "Knowledge (religion)", "Profession", "Ride", "Sense Motive", "Spellcraft"
        });
    paladin.setFeatures({
        "Aura of Good", "Detect Evil", "Smite Evil", "Divine Grace", "Lay on Hands", "Aura of Courage", "Divine Health", "Mercy", "Channel Positive Energy", "Divine Bond", "Aura of Resolve", "Aura of Justice", "Aura of Faith", "Aura of Righteousness", "Holy Champion"
        });
    return paladin;
}

CharacterClass makeRanger() {
    CharacterClass ranger;
    ranger.setName("Ranger");
    ranger.setHitDie(10);
    ranger.setBAB(CharacterClass::BABProgression::Full);
    ranger.setFortitudeSave(CharacterClass::SaveProgression::Good);
    ranger.setReflexSave(CharacterClass::SaveProgression::Good);
    ranger.setWillSave(CharacterClass::SaveProgression::Poor);
    ranger.setSkillRanksPerLevel(6);
    ranger.setClassSkills({
        "Climb", "Craft", "Handle Animal", "Heal", "Intimidate", "Knowledge (dungeoneering)", "Knowledge (geography)", "Knowledge (nature)", "Perception", "Profession", "Ride", "Spellcraft", "Stealth", "Survival", "Swim"
        });
    ranger.setFeatures({
        "Favored Enemy", "Track", "Wild Empathy", "Combat Style Feat", "Endurance", "Favored Terrain", "Hunter's Bond", "Woodland Stride", "Swift Tracker", "Evasion", "Quarry", "Camouflage", "Improved Evasion", "Hide in Plain Sight", "Improved Quarry", "Master Hunter"
        });
    return ranger;
}

CharacterClass makeRogue() {
    CharacterClass rogue;
    rogue.setName("Rogue");
    rogue.setHitDie(8);
    rogue.setBAB(CharacterClass::BABProgression::ThreeQuarter);
    rogue.setFortitudeSave(CharacterClass::SaveProgression::Poor);
    rogue.setReflexSave(CharacterClass::SaveProgression::Good);
    rogue.setWillSave(CharacterClass::SaveProgression::Poor);
    rogue.setSkillRanksPerLevel(8);
    rogue.setClassSkills({
        "Acrobatics", "Appraise", "Bluff", "Climb", "Craft", "Diplomacy", "Disable Device", "Disguise", "Escape Artist", "Intimidate", "Knowledge (dungeoneering)", "Knowledge (local)", "Linguistics", "Perception", "Perform", "Profession", "Sense Motive", "Sleight of Hand", "Stealth", "Swim", "Use Magic Device"
        });
    rogue.setFeatures({
        "Sneak Attack", "Trapfinding", "Evasion", "Rogue Talents", "Trap Sense", "Uncanny Dodge", "Improved Uncanny Dodge", "Master Strike"
        });
    return rogue;
}

CharacterClass makeSorcerer() {
    CharacterClass sorcerer;
    sorcerer.setName("Sorcerer");
    sorcerer.setHitDie(6);
    sorcerer.setBAB(CharacterClass::BABProgression::Half);
    sorcerer.setFortitudeSave(CharacterClass::SaveProgression::Poor);
    sorcerer.setReflexSave(CharacterClass::SaveProgression::Poor);
    sorcerer.setWillSave(CharacterClass::SaveProgression::Good);
    sorcerer.setSkillRanksPerLevel(2);
    sorcerer.setClassSkills({
        "Appraise", "Bluff", "Craft", "Fly", "Intimidate", "Knowledge (arcana)", "Profession", "Spellcraft", "Use Magic Device"
        });
    sorcerer.setFeatures({
        "Bloodline", "Cantrips", "Eschew Materials", "Bloodline Arcana", "Bloodline Powers", "Bloodline Feats", "Bloodline Spells"
        });
    return sorcerer;
}

CharacterClass makeWizard() {
    CharacterClass wizard;
    wizard.setName("Wizard");
    wizard.setHitDie(6);
    wizard.setBAB(CharacterClass::BABProgression::Half);
    wizard.setFortitudeSave(CharacterClass::SaveProgression::Poor);
    wizard.setReflexSave(CharacterClass::SaveProgression::Poor);
    wizard.setWillSave(CharacterClass::SaveProgression::Good);
    wizard.setSkillRanksPerLevel(2);
    wizard.setClassSkills({
        "Appraise", "Craft", "Fly", "Knowledge (all)", "Linguistics", "Profession", "Spellcraft"
        });
    wizard.setFeatures({
        "Arcane Bond", "Arcane School", "Cantrips", "Scribe Scroll"
        });
    return wizard;
}