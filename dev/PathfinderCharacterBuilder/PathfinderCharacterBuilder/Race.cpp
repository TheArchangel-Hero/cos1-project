#include "Race.h"
#include "AbilityScores.h"
#include <iostream>

// Apply Ability Score Modifiers
void Race::applyAbilityBonuses(AbilityScores& scores) const {
	scores.strength += strMod;
	scores.dexterity += dexMod;
	scores.constitution += conMod;
	scores.intelligence += intMod;
	scores.wisdom += wisMod;
	scores.charisma += chaMod;
}

// Print
void Race::print() const {
	// Name
	std::cout << name << "\n";
	// Size
	std::cout << " -> Size: ";
	switch (size) {
	case Size::Small: std::cout << "Small\n";
		break;
	case Size::Medium: std::cout << "Medium\n";
		break;
	case Size::Large: std::cout << "Large\n";
		break;
	}
	// Speed
	std::cout << " -> Speed: " << baseSpeed << " feet\n";
	// Racial Ability Score Modifiers
	std::cout << " -> Ability Modifiers: ";
	if (strMod) std::cout << "Str " << (strMod > 0 ? "+" : "") << strMod << "  ";
	if (dexMod) std::cout << "Dex " << (dexMod > 0 ? "+" : "") << dexMod << "  ";
	if (conMod) std::cout << "Con " << (conMod > 0 ? "+" : "") << conMod << "  ";
	if (intMod) std::cout << "Int " << (intMod > 0 ? "+" : "") << intMod << "  ";
	if (wisMod) std::cout << "Wis " << (wisMod > 0 ? "+" : "") << wisMod << "  ";
	if (chaMod) std::cout << "Cha " << (chaMod > 0 ? "+" : "") << chaMod << "  ";
	std::cout << "\n";
	// Languages
	if (!languages.empty()) {
		std::cout << " -> Languages:\n";
		for (const auto& language : languages) std::cout << "     - " << language << "\n";
	}
	// Racial Traits
	if (!traits.empty()) {
		std::cout << " -> Traits:\n";
		for (const auto& trait : traits) std::cout << "     - " << trait << "\n";
	}
}

// Race Template Functions
Race makeDwarf() {
	Race dwarf;
	dwarf.name = "Dwarf";
	dwarf.conMod = 2;
	dwarf.wisMod = 2;
	dwarf.chaMod = -2;
	dwarf.size = Race::Size::Medium;
	dwarf.baseSpeed = 20;
	dwarf.languages = { "Common", "Dwarven" };
	dwarf.traits = {
		"Slow and Steady: Dwarves have a base speed of 20 feet, but their speed is never modified by armor or encumbrance.",
		"Darkvision: Dwarves can see in the dark up to 60 feet.",
		"Defensive Training: Dwarves get a +4 dodge bonus to their AC against monsters of the giant subtype.",
		"Greed: Dwarves receive a +2 racial bonus on Appraise checks made to determine the price of nonmagical goods that contain precious metals or gemstones.",
		"Hatred: Dwarves receive a +1 bonus on attack rolls against humanoid creatures of the orc and goblinoid subtypes because of their special training against these hated foes.",
		"Hardy: Dwarves receive a +2 racial bonus on saving throws against poison, spells, and spell-like abilities.",
		"Stability: Dwarves receive a +4 racial bonus to their Combat Maneuver Defense when resisting a bull rush or trip attempt while standing on the ground.",
		"Stonecunning: Dwarves receive a +2 bonus on Perception checks to potentially notice unusual stonework, such as traps and hidden doors located in stone walls or floors. They receive a check to notice any such features that they pass within 10 feet of, whether or not they are actively looking.",
		"Weapon Familiarity: Dwarves are proficient with battleaxes, heavy picks, and warhammers, and treat any weapon with the word “dwarven” in its name as a martial weapon."
	};
	return dwarf;
}

Race makeElf() {
	Race elf;
	elf.name = "Elf";
	elf.dexMod = 2;
	elf.conMod = -2;
	elf.intMod = 2;
	elf.size = Race::Size::Medium;
	elf.baseSpeed = 30;
	elf.languages = { "Common", "Elven" };
	elf.traits = {
		"Low-Light Vision: Elves can see twice as far as humans in conditions of dim light.",
		"Elven Immunities: Elves are immune to magic sleep effects and get a +2 racial bonus on saving throws against enchantment spells and effects.",
		"Elven Magic: Elves receive a +2 racial bonus on caster level checks made to overcome spell resistance. In addition, elves receive a +2 racial bonus on Spellcraft checks made to identify the properties of magic items.",
		"Keen Senses: Elves receive a +2 racial bonus on Perception checks.",
		"Weapon Familiarity: Elves are proficient with longbows (including composite longbows), longswords, rapiers, and shortbows (including composite shortbows), and treat any weapon with the word “elven” in its name as a martial weapon."
	};
	return elf;
}

Race makeGnome() {
	Race gnome;
	gnome.name = "Gnome";
	gnome.strMod = -2;
	gnome.conMod = 2;
	gnome.chaMod = 2;
	gnome.size = Race::Size::Small;
	gnome.baseSpeed = 20;
	gnome.languages = { "Common", "Gnome", "Sylvan" };
	gnome.traits = {
		"Low-Light Vision: Gnomes can see twice as far as humans in conditions of dim light.",
		"Defensive Training: Gnomes get a +4 dodge bonus to their AC against monsters of the giant type.",
		"Gnome Magic: Gnomes add 1 to the DCs of any saving throws to resist illusion spells that they cast. Gnomes with a Charisma of 11 or higher also gain the following spell-like abilities: 1/day—dancing lights, ghost sound, prestidigitation, and speak with animals. The caster level for these effects is equal to the gnome’s character level. The DC for these spells is equal to 10 + the spell’s level + the gnome’s Charisma modifier.",
		"Hatred: Gnomes receive a +1 bonus on attack rolls against humanoid creatures of the reptilian and goblinoid subtypes because of their special training against these hated foes.",
		"Illusion Resistance: Gnomes get a +2 racial bonus on saving throws against illusion spells or effects.",
		"Keen Senses: Gnomes receive a +2 racial bonus on Perception checks.",
		"Obsessive: Gnomes receive a +2 racial bonus on a Craft or Profession skill of their choice.",
		"Weapon Familiarity: Gnomes treat any weapon with the word “gnome” in its name as a martial weapon."
	};
	return gnome;
}

Race makeHalfElf() {
	Race halfElf;
	halfElf.name = "Half-Elf";
	halfElf.size = Race::Size::Medium;
	halfElf.baseSpeed = 30;
	halfElf.languages = { "Common", "Elven" };
	halfElf.traits = {
		"Low-Light Vision: Half-elves can see twice as far as humans in conditions of dim light.",
		"Adaptability: Half-elves receive Skill Focus as a bonus feat at 1st level.",
		"Elf Blood: Half-elves count as both elves and humans for any effect related to race.",
		"Elven Immunities: Half-elves are immune to magic sleep effects and get a +2 racial bonus on saving throws against enchantment spells and effects.",
		"Keen Senses: Half-elves receive a +2 racial bonus on Perception checks.",
		"Multitalented: Half-elves choose two favored classes at 1st level and gain 1 additional hit point or skill point whenever they take a level in either one of those classes."
	};
	return halfElf;
}

Race makeHalfOrc() {
	Race halfOrc;
	halfOrc.name = "Half-Orc";
	halfOrc.size = Race::Size::Medium;
	halfOrc.baseSpeed = 30;
	halfOrc.languages = { "Common", "Orc" };
	halfOrc.traits = {
		"Darkvision: Half-orcs can see in the dark up to 60 feet.",
		"Intimidating: Half-orcs receive a +2 racial bonus on Intimidate checks because of their fearsome nature.",
		"Orc Blood: Half-orcs count as both humans and orcs for any effect related to race.",
		"Orc Ferocity: Once per day, when a half-orc is brought below 0 hit points but not killed, he can fight on for 1 more round as if disabled. At the end of his next turn, unless brought to 1 or more hit points, he immediately falls unconscious and begins dying.",
		"Weapon Familiarity: Half-orcs are proficient with greataxes and falchions, and treat any weapon with the word “orc” in its name as a martial weapon."
	};
	return halfOrc;
}

Race makeHalfling() {
	Race halfling;
	halfling.name = "Halfling";
	halfling.strMod = -2;
	halfling.dexMod = 2;
	halfling.chaMod = 2;
	halfling.size = Race::Size::Small;
	halfling.baseSpeed = 20;
	halfling.languages = { "Common", "Halfling" };
	halfling.traits = {
		"Fearless: Halflings receive a +2 racial bonus on all saving throws against fear. This bonus stacks with the bonus granted by halfling luck.",
		"Halfling Luck: Halflings receive a +1 racial bonus on all saving throws.",
		"Keen Senses: Halflings receive a +2 racial bonus on Perception checks.",
		"Sure-Footed: Halflings receive a +2 racial bonus on Acrobatics and Climb checks.",
		"Weapon Familiarity: Halflings are proficient with slings and treat any weapon with the word “halfling” in its name as a martial weapon."
	};
	return halfling;
}

Race makeHuman() {
	Race human;
	human.name = "Human";
	human.size = Race::Size::Medium;
	human.baseSpeed = 30;
	human.languages = { "Common" };
	human.traits = {
		"Bonus Feat: Humans select one extra feat at 1st level.",
		"Skilled: Humans gain 1 additional skill rank at 1st level and 1 additional rank whenever they gain a level."
	};
	return human;
}