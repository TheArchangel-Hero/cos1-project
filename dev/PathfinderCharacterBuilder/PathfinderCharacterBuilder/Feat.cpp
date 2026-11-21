#include "Feat.h"
#include <iostream>

// Print
void Feat::print() const {
	std::cout << name;

	std::cout << " [";
	switch (type) {
	case FeatType::General:
		std::cout << "General";
		break;
	case FeatType::Combat:
		std::cout << "Combat";
		break;
	case FeatType::Critical:
		std::cout << "Critical";
		break;
	case FeatType::ItemCreation:
		std::cout << "Item Creation";
		break;
	case FeatType::Metamagic:
		std::cout << "Metamagic";
		break;
	}
	std::cout << "]\n";

	if (!prerequisites.empty()) {
		std::cout << "  Prerequisites: ";
		for (size_t i = 0; i < prerequisites.size(); ++i) {
			std::cout << prerequisites[i];
			if (i + 1 < prerequisites.size()) std::cout << ", ";
		}
		std::cout << "\n";
	}

	std::cout << "  Benefit: " << benefit << "\n";
}

// Feat Template Functions
// Note: Currently only Feats beginning with A are implemented.
// TO DO: Implement remaining Feats
// A
Feat makeAcrobatic() {
	Feat feat;
	feat.setName("Acrobatic");
	feat.setType(Feat::FeatType::General);
	feat.setBenefit("You get a +2 bonus on all Acrobatics and Fly skill checks. If you have 10 or more ranks in one of these skills, the bonus increases to +4 for that skill.");
	return feat;
}
Feat makeAcrobaticSteps() {
	Feat feat;
	feat.setName("Acrobatic Steps");
	feat.setType(Feat::FeatType::General);
	feat.setPrerequisites({ "Dex 15", "Nimble Moves" });
	feat.setBenefit("Whenever you move, you may move through up to 15 feet of difficult terrain each round as if it were normal terrain. The effects of this feat stack with those provided by Nimble Moves (allowing you to move normally through a total of 20 feet of difficult terrain each round).");
	return feat;
}
Feat makeAgileManeuvers() {
	Feat feat;
	feat.setName("Agile Maneuvers");
	feat.setType(Feat::FeatType::Combat);
	feat.setBenefit("You add your Dexterity bonus to your base attack bonus and size bonus when determining your Combat Maneuver Bonus (see Combat) instead of your Strength bonus.\nNormal: You add your Strength bonus to your base attack bonus and size bonus when determining your Combat Maneuver Bonus.");
	return feat;
}
Feat makeAlertness() {
	Feat feat;
	feat.setName("Alertness");
	feat.setType(Feat::FeatType::General);
	feat.setBenefit("You get a +2 bonus on Perception and Sense Motive skill checks. If you have 10 or more ranks in one of these skills, the bonus increases to +4 for that skill.");
	return feat;
}
Feat makeAlignmentChannel() {
	Feat feat;
	feat.setName("Alignment Channel");
	feat.setType(Feat::FeatType::General);
	feat.setPrerequisites({ "Ability to channel energy." });
	feat.setBenefit("Instead of its normal effect, you can choose to have your ability to channel energy heal or harm outsiders of the chosen alignment subtype. You must make this choice each time you channel energy. If you choose to heal or harm creatures of the chosen alignment subtype, your channel energy has no effect on other creatures. The amount of damage healed or dealt and the DC to halve the damage is otherwise unchanged.\nSpecial: You can gain this feat multiple times. Its effects do not stack. Each time you take this feat, it applies to a new alignment subtype. Whenever you channel energy, you must choose which type to effect.");
	return feat;
}
Feat makeAnimalAffinity() {
	Feat feat;
	feat.setName("Animal Affinity");
	feat.setType(Feat::FeatType::General);
	feat.setBenefit("You get a +2 bonus on all Handle Animal and Ride skill checks. If you have 10 or more ranks in one of these skills, the bonus increases to +4 for that skill.");
	return feat;
}
Feat makeArcaneArmorMastery() {
	Feat feat;
	feat.setName("Arcane Armor Mastery");
	feat.setType(Feat::FeatType::Combat);
	feat.setPrerequisites({ "Arcane Armor Training", "Medium Armor Proficiency", "caster level 7th." });
	feat.setBenefit("As a swift action, reduce the arcane spell failure chance due to the armor you are wearing by 20% for any spells you cast this round. This bonus replaces, and does not stack with, the bonus granted by Arcane Armor Training.");
	return feat;
}
Feat makeArcaneArmorTraining() {
	Feat feat;
	feat.setName("Arcane Armor Training");
	feat.setType(Feat::FeatType::Combat);
	feat.setPrerequisites({ "Light Armor Proficiency", "caster level 3rd." });
	feat.setBenefit("As a swift action, reduce the arcane spell failure chance due to the armor you are wearing by 10% for any spells you cast this round.");
	return feat;
}
Feat makeArcaneStrike() {
	Feat feat;
	feat.setName("Arcane Strike");
	feat.setType(Feat::FeatType::Combat);
	feat.setPrerequisites({ "Ability to cast arcane spells." });
	feat.setBenefit("As a swift action, you can imbue your weapons with a fraction of your power. For 1 round, your weapons deal +1 damage and are treated as magic for the purpose of overcoming damage reduction. For every five caster levels you possess, this bonus increases by +1, to a maximum of +5 at 20th level.");
	return feat;
}
Feat makeArmorProficiencyHeavy() {
	Feat feat;
	feat.setName("Armor Proficiency, Heavy");
	feat.setType(Feat::FeatType::Combat);
	feat.setPrerequisites({ "Light Armor Proficiency", "Medium Armor Proficiency." });
	feat.setBenefit("When you wear a type of armor with which you are proficient, the armor check penalty for that armor applies only to Dexterity- and Strength-based skill checks.\nNormal: A character who is wearing armor with which he is not proficient applies its armor check penalty to attack rolls and to all skill checks that involve moving.\nSpecial: Fighters and paladins automatically have Heavy Armor Proficiency as a bonus feat. They need not select it.");
	return feat;
}
Feat makeArmorProficiencyLight() {
	Feat feat;
	feat.setName("Armor Proficiency, Light");
	feat.setType(Feat::FeatType::Combat);
	feat.setBenefit("When you wear a type of armor with which you are proficient, the armor check penalty for that armor applies only to Dexterity- and Strength-based skill checks.\nNormal: A character who is wearing armor with which he is not proficient applies its armor check penalty to attack rolls and to all skill checks that involve moving.\nSpecial: All characters except monks, sorcerers, and wizards automatically have Light Armor Proficiency as a bonus feat. They need not select it.");
	return feat;
}
Feat makeArmorProficiencyMedium() {
	Feat feat;
	feat.setName("Armor Proficiency, Medium");
	feat.setType(Feat::FeatType::Combat);
	feat.setPrerequisites({ "Light Armor Proficiency." });
	feat.setBenefit("When you wear a type of armor with which you are proficient, the armor check penalty for that armor applies only to Dexterity- and Strength-based skill checks.\nNormal: A character who is wearing armor with which he is not proficient applies its armor check penalty to attack rolls and to all skill checks that involve moving.\nSpecial: Barbarians, clerics, druids, fighters, paladins, and rangers automatically have Medium Armor Proficiency as a bonus feat. They need not select it.");
	return feat;
}
Feat makeAthletic() {
	Feat feat;
	feat.setName("Athletic");
	feat.setType(Feat::FeatType::General);
	feat.setBenefit("You get a +2 bonus on Climb and Swim skill checks. If you have 10 or more ranks in one of these skills, the bonus increases to +4 for that skill.");
	return feat;
}
Feat makeAugmentSummoning() {
	Feat feat;
	feat.setName("Augment Summoning");
	feat.setType(Feat::FeatType::General);
	feat.setPrerequisites({ "Spell Focus (conjuration)." });
	feat.setBenefit("Each creature you conjure with any summon spell gains a +4 enhancement bonus to Strength and Constitution for the duration of the spell that summoned it.");
	return feat;
}
// B
Feat makeBleedingCritical() {
    Feat feat;
    feat.setName("Bleeding Critical");
    feat.setType(Feat::FeatType::Critical);
    feat.setPrerequisites({ "Critical Focus", "base attack bonus +11" });
    feat.setBenefit("Whenever you score a critical hit with a slashing or piercing weapon, the target takes 2d6 bleed damage each round. The bleed can be stopped with a DC 15 Heal check or any magical healing.");
    return feat;
}
Feat makeBlindFight() {
    Feat feat;
    feat.setName("Blind-Fight");
    feat.setType(Feat::FeatType::Combat);
    feat.setBenefit("In melee, every time you miss because of concealment, you can reroll your miss chance percentile roll one time to see if you actually hit. You take only half the usual penalty to speed for being unable to see. Darkness and poor visibility in general reduces your melee attack rolls by only 1.");
    return feat;
}
Feat makeBlindingCritical() {
    Feat feat;
    feat.setName("Blinding Critical");
    feat.setType(Feat::FeatType::Critical);
    feat.setPrerequisites({ "Critical Focus", "base attack bonus +15" });
    feat.setBenefit("Whenever you score a critical hit, your opponent is permanently blinded. A successful Fortitude save reduces this to dazzled for 1d4 rounds. The DC of this Fortitude save is equal to 10 + your base attack bonus.");
    return feat;
}
Feat makeBrewPotion() {
    Feat feat;
    feat.setName("Brew Potion");
    feat.setType(Feat::FeatType::ItemCreation);
    feat.setPrerequisites({ "Caster level 3rd" });
    feat.setBenefit("You can create a potion of any 3rd-level or lower spell that you know and that targets one or more creatures or objects.");
    return feat;
}
// C
Feat makeCatchOffGuard() {
    Feat feat;
    feat.setName("Catch Off-Guard");
    feat.setType(Feat::FeatType::Combat);
    feat.setBenefit("You do not suffer any penalties for using an improvised melee weapon. Unarmed opponents are flat-footed against any attacks you make with an improvised melee weapon.");
    return feat;
}
Feat makeChannelSmite() {
    Feat feat;
    feat.setName("Channel Smite");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Channel energy class feature" });
    feat.setBenefit("Before making a melee attack roll, you can choose to spend one use of your channel energy ability as a swift action. If you channel positive energy and you hit an undead creature, that creature takes an amount of additional damage equal to the damage dealt by your channel positive energy ability. If you channel negative energy and you hit a living creature, that creature takes an amount of additional damage equal to the damage dealt by your channel negative energy ability.");
    return feat;
}
Feat makeCleave() {
    Feat feat;
    feat.setName("Cleave");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Str 13", "Power Attack", "base attack bonus +1" });
    feat.setBenefit("As a standard action, you can make a single attack at your full base attack bonus against a foe within reach. If you hit, you deal damage normally and can make an additional attack (using your full base attack bonus) against a foe that is adjacent to the first and also within reach. You can only make one additional attack per round with this feat.");
    return feat;
}
Feat makeCombatCasting() {
    Feat feat;
    feat.setName("Combat Casting");
    feat.setType(Feat::FeatType::Combat);
    feat.setBenefit("You get a +4 bonus on concentration checks made to cast a spell or use a spell-like ability when casting on the defensive or while grappled.");
    return feat;
}
Feat makeCombatExpertise() {
    Feat feat;
    feat.setName("Combat Expertise");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Int 13" });
    feat.setBenefit("You can choose to take a –1 penalty on melee attack rolls and combat maneuver checks to gain a +1 dodge bonus to your Armor Class. When your base attack bonus reaches +4, and every +4 thereafter, the penalty increases by –1 and the dodge bonus increases by +1. You can only choose to use this feat when you declare that you are making an attack or a full-attack action with a melee weapon. The effects of this feat last until your next turn.");
    return feat;
}
Feat makeCombatReflexes() {
    Feat feat;
    feat.setName("Combat Reflexes");
    feat.setType(Feat::FeatType::Combat);
    feat.setBenefit("You may make a number of additional attacks of opportunity per round equal to your Dexterity bonus. With this feat, you may also make attacks of opportunity while flat-footed.");
    return feat;
}
Feat makeCommandUndeadFeat() {
    Feat feat;
    feat.setName("Command Undead");
    feat.setType(Feat::FeatType::General);
    feat.setPrerequisites({ "Channel negative energy class feature" });
    feat.setBenefit("As a standard action, you can use one of your uses of channel negative energy to enslave undead within 30 feet. Undead receive a Will save to negate the effect. The DC for this Will save is equal to 10 + 1/2 your cleric level + your Charisma modifier. Undead that fail their saves fall under your control, obeying your commands to the best of their ability, as if under the effects of control undead. Intelligent undead receive a new saving throw each day to resist your command. You can control any number of undead, so long as their total Hit Dice do not exceed your cleric level. If you use channel energy in this way, it has no other effect (it does not heal or harm nearby creatures). If an undead creature is under the control of another creature, you must make an opposed Charisma check whenever your orders conflict.");
    return feat;
}
Feat makeCraftMagicArmsAndArmor() {
    Feat feat;
    feat.setName("Craft Magic Arms and Armor");
    feat.setType(Feat::FeatType::ItemCreation);
    feat.setPrerequisites({ "Caster level 5th" });
    feat.setBenefit("You can create magic weapons, armor, or shields.");
    return feat;
}
Feat makeCraftRod() {
    Feat feat;
    feat.setName("Craft Rod");
    feat.setType(Feat::FeatType::ItemCreation);
    feat.setPrerequisites({ "Caster level 9th" });
    feat.setBenefit("You can create magic rods.");
    return feat;
}
Feat makeCraftStaff() {
    Feat feat;
    feat.setName("Craft Staff");
    feat.setType(Feat::FeatType::ItemCreation);
    feat.setPrerequisites({ "Caster level 11th" });
    feat.setBenefit("You can create magic staves.");
    return feat;
}
Feat makeCraftWand() {
    Feat feat;
    feat.setName("Craft Wand");
    feat.setType(Feat::FeatType::ItemCreation);
    feat.setPrerequisites({ "Caster level 5th" });
    feat.setBenefit("You can create wands.");
    return feat;
}
Feat makeCraftWonderousItem() {
    Feat feat;
    feat.setName("Craft Wondrous Item");
    feat.setType(Feat::FeatType::ItemCreation);
    feat.setPrerequisites({ "Caster level 3rd" });
    feat.setBenefit("You can create wondrous items.");
    return feat;
}
Feat makeCriticalFocus() {
    Feat feat;
    feat.setName("Critical Focus");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Base attack bonus +9" });
    feat.setBenefit("You receive a +4 circumstance bonus on attack rolls made to confirm critical hits.");
    return feat;
}
Feat makeCriticalMastery() {
    Feat feat;
    feat.setName("Critical Mastery");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Critical Focus", "any two critical feats", "14th-level fighter" });
    feat.setBenefit("When you score a critical hit, you can apply the effects of two critical feats in addition to the damage dealt.");
    return feat;
}
// D
Feat makeDazzlingDisplay() {
    Feat feat;
    feat.setName("Dazzling Display");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Weapon Focus", "Proficiency with selected weapon" });
    feat.setBenefit("While wielding the weapon in which you have Weapon Focus, you can perform a bewildering show of prowess as a full-round action. Make an Intimidate check to demoralize all foes within 30 feet who can see your display.");
    return feat;
}
Feat makeDeadlyAim() {
    Feat feat;
    feat.setName("Deadly Aim");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Dex 13", "base attack bonus +1" });
    feat.setBenefit("You can choose to take a –1 penalty on all ranged attack rolls to gain a +2 bonus on all ranged damage rolls. When your base attack bonus reaches +4, and every +4 thereafter, the penalty increases by –1 and the bonus to damage increases by +2. You must choose to use this feat before making an attack roll and its effects last until your next turn. The bonus damage does not apply to touch attacks or effects that do not deal hit point damage.");
    return feat;
}
Feat makeDeadlyStroke() {
    Feat feat;
    feat.setName("Deadly Stroke");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Greater Weapon Focus", "Shatter Defenses", "base attack bonus +11" });
    feat.setBenefit("As a standard action, make a single attack with the weapon for which you have Greater Weapon Focus against a stunned or flat-footed opponent. If you hit, you deal double the normal damage and the target takes 1 point of Constitution bleed. The additional damage and bleed is not multiplied on a critical hit.");
    return feat;
}
Feat makeDeafeningCritical() {
    Feat feat;
    feat.setName("Deafening Critical");
    feat.setType(Feat::FeatType::Critical);
    feat.setPrerequisites({ "Critical Focus", "base attack bonus +13" });
    feat.setBenefit("Whenever you score a critical hit, your opponent is permanently deafened. A successful Fortitude save reduces the deafness to 1 round. The DC of this Fortitude save is equal to 10 + your base attack bonus.");
    return feat;
}
Feat makeDeceitful() {
    Feat feat;
    feat.setName("Deceitful");
    feat.setType(Feat::FeatType::General);
    feat.setBenefit("You get a +2 bonus on all Bluff and Disguise skill checks. If you have 10 or more ranks in one of these skills, the bonus increases to +4 for that skill.");
    return feat;
}
Feat makeDefensiveCombatTraining() {
    Feat feat;
    feat.setName("Defensive Combat Training");
    feat.setType(Feat::FeatType::Combat);
    feat.setBenefit("You treat your total Hit Dice as your base attack bonus when calculating your Combat Maneuver Defense.");
    return feat;
}
Feat makeDeflectArrows() {
    Feat feat;
    feat.setName("Deflect Arrows");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Dex 13", "Improved Unarmed Strike" });
    feat.setBenefit("You must have at least one hand free (holding nothing) to use this feat. Once per round when you would normally be hit with an attack from a ranged weapon, you may deflect it so that you take no damage from it. You must be aware of the attack and not flat-footed. Attempting to deflect a ranged attack doesn’t count as an action. Unusually massive ranged weapons (such as boulders or ballista bolts) and ranged attacks generated by natural attacks or spell effects can’t be deflected.");
    return feat;
}
Feat makeDeftHands() {
    Feat feat;
    feat.setName("Deft Hands");
    feat.setType(Feat::FeatType::General);
    feat.setBenefit("You get a +2 bonus on Disable Device and Sleight of Hand skill checks. If you have 10 or more ranks in one of these skills, the bonus increases to +4 for that skill.");
    return feat;
}
Feat makeDiehard() {
    Feat feat;
    feat.setName("Diehard");
    feat.setType(Feat::FeatType::General);
    feat.setPrerequisites({ "Endurance" });
    feat.setBenefit("When your hit point total is below 0, but you are not dead, you automatically stabilize. You do not need to make a Constitution check each round to avoid losing additional hit points. You may choose to act as if you were disabled, rather than dying. You must make this decision as soon as you are reduced to negative hit points (even if it isn’t your turn). If you do not choose to act as if you were disabled, you immediately fall unconscious.");
    return feat;
}
Feat makeDisruptive() {
    Feat feat;
    feat.setName("Disruptive");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "6th-level fighter" });
    feat.setBenefit("The DC to cast spells defensively increases by +4 for all enemies that are within your threatened area. This increase to casting spells defensively only applies if you are aware of the enemy’s location and are capable of taking an attack of opportunity. If you can only take one attack of opportunity per round and have already used that attack, this increase does not apply.");
    return feat;
}
Feat makeDodge() {
    Feat feat;
    feat.setName("Dodge");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Dex 13" });
    feat.setBenefit("You gain a +1 dodge bonus to your AC. A condition that makes you lose your Dex bonus to AC also makes you lose the benefits of this feat.");
    return feat;
}
Feat makeDoubleSlice() {
    Feat feat;
    feat.setName("Double Slice");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Dex 15", "Two-Weapon Fighting" });
    feat.setBenefit("Add your Strength bonus to damage rolls made with your off-hand weapon.");
    return feat;
}
// E
Feat makeElementalChannel() {
    Feat feat;
    feat.setName("Elemental Channel");
    feat.setType(Feat::FeatType::General);
    feat.setPrerequisites({ "Channel energy class feature" });
    feat.setBenefit("Instead of its normal effect, you can choose to have your ability to channel energy heal or harm outsiders with an elemental subtype. You must make this choice each time you channel energy. If you choose to heal or harm creatures of the chosen subtype, your channel energy has no effect on other creatures. The amount of damage healed or dealt and the DC to halve the damage is otherwise unchanged.");
    return feat;
}
Feat makeEmpowerSpell() {
    Feat feat;
    feat.setName("Empower Spell");
    feat.setType(Feat::FeatType::Metamagic);
    feat.setBenefit("All variable, numeric effects of an empowered spell are increased by half including bonuses to those dice rolls. Saving throws and opposed rolls are not affected, nor are spells without random variables. An empowered spell uses up a spell slot two levels higher than the spell’s actual level.");
    return feat;
}
Feat makeEndurance() {
    Feat feat;
    feat.setName("Endurance");
    feat.setType(Feat::FeatType::General);
    feat.setBenefit("You gain a +4 bonus on the following checks and saves: Swim checks made to resist nonlethal damage from exhaustion; Constitution checks made to continue running; Constitution checks made to avoid nonlethal damage from a forced march; Constitution checks made to hold your breath; Constitution checks made to avoid nonlethal damage from starvation or thirst; Fortitude saves made to avoid nonlethal damage from hot or cold environments; and Fortitude saves made to resist damage from suffocation. You may sleep in light or medium armor without becoming fatigued.");
    return feat;
}
Feat makeEnlargeSpell() {
    Feat feat;
    feat.setName("Enlarge Spell");
    feat.setType(Feat::FeatType::Metamagic);
    feat.setBenefit("You can alter a spell with a range of close, medium, or long to increase its range by 100%. An enlarged spell with a range of close now has a range of 50 ft. + 5 ft./level, while medium-range spells have a range of 200 ft. + 20 ft./level and long-range spells have a range of 800 ft. + 80 ft./level. An enlarged spell uses up a spell slot one level higher than the spell’s actual level.");
    return feat;
}
Feat makeEschewMaterials() {
    Feat feat;
    feat.setName("Eschew Materials");
    feat.setType(Feat::FeatType::General);
    feat.setBenefit("You can cast any spell with a material component costing 1 gp or less without needing that component. The casting of the spell still provokes attacks of opportunity as normal. If the spell requires a material component that costs more than 1 gp, you must have the material component on hand to cast the spell, as normal.");
    return feat;
}
Feat makeExhaustingCritical() {
    Feat feat;
    feat.setName("Exhausting Critical");
    feat.setType(Feat::FeatType::Critical);
    feat.setPrerequisites({ "Critical Focus", "Tiring Critical", "base attack bonus +15" });
    feat.setBenefit("When you score a critical hit, your opponent becomes exhausted. A successful Fortitude save reduces this to fatigued. The DC of this Fortitude save is equal to 10 + your base attack bonus.");
    return feat;
}
Feat makeExtendSpell() {
    Feat feat;
    feat.setName("Extend Spell");
    feat.setType(Feat::FeatType::Metamagic);
    feat.setBenefit("An extended spell lasts twice as long as normal. A spell with a duration of concentration, instantaneous, or permanent is not affected by this feat. An extended spell uses up a spell slot one level higher than the spell’s actual level.");
    return feat;
}
Feat makeExtraChannel() {
    Feat feat;
    feat.setName("Extra Channel");
    feat.setType(Feat::FeatType::General);
    feat.setPrerequisites({ "Channel energy class feature" });
    feat.setBenefit("You can channel energy two additional times per day.");
    return feat;
}
Feat makeExtraKi() {
    Feat feat;
    feat.setName("Extra Ki");
    feat.setType(Feat::FeatType::General);
    feat.setPrerequisites({ "Ki pool class feature" });
    feat.setBenefit("Your ki pool increases by 2.");
    return feat;
}
Feat makeExtraLayOnHands() {
    Feat feat;
    feat.setName("Extra Lay On Hands");
    feat.setType(Feat::FeatType::General);
    feat.setPrerequisites({ "Lay on hands class feature" });
    feat.setBenefit("You can use your lay on hands ability two additional times per day.");
    return feat;
}
Feat makeExtraMercy() {
    Feat feat;
    feat.setName("Extra Mercy");
    feat.setType(Feat::FeatType::General);
    feat.setPrerequisites({ "Mercy class feature" });
    feat.setBenefit("Your lay on hands gains one additional mercy.");
    return feat;
}
Feat makeExtraPerformance() {
    Feat feat;
    feat.setName("Extra Performance");
    feat.setType(Feat::FeatType::General);
    feat.setPrerequisites({ "Bardic performance class feature" });
    feat.setBenefit("You can use bardic performance for 6 additional rounds per day.");
    return feat;
}
Feat makeExtraRage() {
    Feat feat;
    feat.setName("Extra Rage");
    feat.setType(Feat::FeatType::General);
    feat.setPrerequisites({ "Rage class feature" });
    feat.setBenefit("You can rage for 6 additional rounds per day.");
    return feat;
}
// F
Feat makeFarShot() {
    Feat feat;
    feat.setName("Far Shot");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Point-Blank Shot" });
    feat.setBenefit("You only suffer a –1 penalty per full range increment between you and your target when using a ranged weapon.");
    return feat;
}
Feat makeFleet() {
    Feat feat;
    feat.setName("Fleet");
    feat.setType(Feat::FeatType::General);
    feat.setBenefit("While you are wearing light or no armor, your base speed increases by 5 feet. You lose the benefits of this feat if you carry a medium or heavy load.");
    return feat;
}
Feat makeForgeRing() {
    Feat feat;
    feat.setName("Forge Ring");
    feat.setType(Feat::FeatType::ItemCreation);
    feat.setPrerequisites({ "Caster level 7th" });
    feat.setBenefit("You can create magic rings.");
    return feat;
}
// G
Feat makeGorgonsFist() {
    Feat feat;
    feat.setName("Gorgon's Fist");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Improved Unarmed Strike", "Scorpion Style", "base attack bonus +6" });
    feat.setBenefit("As a standard action, make a single unarmed melee attack. If you hit, you deal damage normally and the target is staggered until the end of your next turn unless it makes a Fortitude saving throw (DC 10 + 1/2 your character level + your Wis modifier). This feat only affects living creatures that are susceptible to critical hits.");
    return feat;
}
Feat makeGreatCleave() {
    Feat feat;
    feat.setName("Great Cleave");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Str 13", "Cleave", "Power Attack", "base attack bonus +4" });
    feat.setBenefit("As a standard action, you can make a single attack at your full base attack bonus against a foe within reach. If you hit, you deal damage normally and can make an additional attack (using your full base attack bonus) against a foe that is adjacent to the previous foe and also within reach. If you hit, you can continue to make attacks against foes adjacent to the previous foe, so long as they are within your reach. You cannot attack an individual foe more than once during this attack action.");
    return feat;
}
Feat makeGreatFortitude() {
    Feat feat;
    feat.setName("Great Fortitude");
    feat.setType(Feat::FeatType::General);
    feat.setBenefit("You get a +2 bonus on all Fortitude saving throws.");
    return feat;
}
Feat makeGreaterBullRush() {
    Feat feat;
    feat.setName("Greater Bull Rush");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Improved Bull Rush", "Power Attack", "base attack bonus +6", "Str 13" });
    feat.setBenefit("You receive a +2 bonus on checks made to bull rush a foe. This bonus stacks with the bonus granted by Improved Bull Rush. Whenever you bull rush an opponent, his movement provokes attacks of opportunity from all of your allies (but not from you).");
    return feat;
}
Feat makeGreaterDisarm() {
    Feat feat;
    feat.setName("Greater Disarm");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Combat Expertise", "Improved Disarm", "base attack bonus +6", "Int 13" });
    feat.setBenefit("You receive a +2 bonus on checks made to disarm a foe. This bonus stacks with the bonus granted by Improved Disarm. Whenever you successfully disarm an opponent, the weapon lands in a square of your choice adjacent to the opponent.");
    return feat;
}
Feat makeGreaterFeint() {
    Feat feat;
    feat.setName("Greater Feint");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Combat Expertise", "Improved Feint", "base attack bonus +6", "Int 13" });
    feat.setBenefit("Whenever you use feint to cause an opponent to lose his Dexterity bonus, he loses that bonus until the beginning of your next turn, in addition to losing his Dexterity bonus against your next attack.");
    return feat;
}
Feat makeGreaterGrapple() {
    Feat feat;
    feat.setName("Greater Grapple");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Improved Grapple", "Improved Unarmed Strike", "base attack bonus +6", "Dex 13" });
    feat.setBenefit("You receive a +2 bonus on checks made to grapple a foe. This bonus stacks with the bonus granted by Improved Grapple. Once you have grappled a creature, maintaining the grapple is a move action. This feat allows you to make two grapple checks each round (to move, harm, or pin your opponent), but you are not required to make two checks. You only need to succeed at one of these checks to maintain the grapple.");
    return feat;
}
Feat makeGreaterOverrun() {
    Feat feat;
    feat.setName("Greater Overrun");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Improved Overrun", "Power Attack", "base attack bonus +6", "Str 13" });
    feat.setBenefit("You receive a +2 bonus on checks made to overrun a foe. This bonus stacks with the bonus granted by Improved Overrun. Whenever you overrun opponents, they provoke attacks of opportunity if they do not choose to let you pass.");
    return feat;
}
Feat makeGreaterPenetratingStrike() {
    Feat feat;
    feat.setName("Greater Penetrating Strike");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Penetrating Strike", "Weapon Focus", "12th-level fighter" });
    feat.setBenefit("Your attacks made with weapons selected with Weapon Focus ignore up to 10 points of damage reduction. This amount is reduced to 5 points for damage reduction without a type (such as DR 10/—).");
    return feat;
}
Feat makeGreaterShieldFocus() {
    Feat feat;
    feat.setName("Greater Shield Focus");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Shield Focus", "Shield Proficiency", "base attack bonus +1", "8th-level fighter" });
    feat.setBenefit("Increase the AC bonus granted by any shield you are using by 1. This bonus stacks with the bonus granted by Shield Focus.");
    return feat;
}
Feat makeGreaterSpellFocus() {
    Feat feat;
    feat.setName("Greater Spell Focus");
    feat.setType(Feat::FeatType::General);
    feat.setPrerequisites({ "Spell Focus" });
    feat.setBenefit("Add +1 to the Difficulty Class for all saving throws against spells from the school of magic you select. This bonus stacks with the bonus from Spell Focus.");
    return feat;
}
Feat makeGreaterSpellPenetration() {
    Feat feat;
    feat.setName("Greater Spell Penetration");
    feat.setType(Feat::FeatType::General);
    feat.setPrerequisites({ "Spell Penetration" });
    feat.setBenefit("You get a +2 bonus on caster level checks (1d20 + caster level) made to overcome a creature’s spell resistance. This bonus stacks with the one from Spell Penetration.");
    return feat;
}
Feat makeGreaterSunder() {
    Feat feat;
    feat.setName("Greater Sunder");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Improved Sunder", "Power Attack", "base attack bonus +6", "Str 13" });
    feat.setBenefit("You receive a +2 bonus on checks made to sunder an item. This bonus stacks with the bonus granted by Improved Sunder. Whenever you sunder to destroy a weapon, shield, or suit of armor, any excess damage is applied to the item’s wielder. No damage is transferred if you decide to leave the item with 1 hit point.");
    return feat;
}
Feat makeGreaterTrip() {
    Feat feat;
    feat.setName("Greater Trip");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Combat Expertise", "Improved Trip", "base attack bonus +6", "Int 13" });
    feat.setBenefit("You receive a +2 bonus on checks made to trip a foe. This bonus stacks with the bonus granted by Improved Trip. Whenever you successfully trip an opponent, that opponent provokes attacks of opportunity.");
    return feat;
}
Feat makeGreaterTwoWeaponFighting() {
    Feat feat;
    feat.setName("Greater Two-Weapon Fighting");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Dex 19", "Improved Two-Weapon Fighting", "Two-Weapon Fighting", "base attack bonus +11" });
    feat.setBenefit("You get a third attack with your off-hand weapon, albeit at a –10 penalty.");
    return feat;
}
Feat makeGreaterVitalStrike() {
    Feat feat;
    feat.setName("Greater Vital Strike");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Improved Vital Strike", "Vital Strike", "base attack bonus +16" });
    feat.setBenefit("When you use the attack action, you can make one attack at your highest base attack bonus that deals additional damage. Roll the weapon’s damage dice for the attack four times and add the results together before adding bonuses from Strength, weapon abilities (such as flaming), precision-based damage, and other damage bonuses. These extra weapon damage dice are not multiplied on a critical hit, but are added to the total.");
    return feat;
}
Feat makeGreaterWeaponFocus() {
    Feat feat;
    feat.setName("Greater Weapon Focus");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Proficiency with selected weapon", "Weapon Focus with selected weapon", "8th-level fighter" });
    feat.setBenefit("You gain a +1 bonus on attack rolls you make using the selected weapon. This bonus stacks with other bonuses on attack rolls, including those from Weapon Focus.");
    return feat;
}
Feat makeGreaterWeaponSpecialization() {
    Feat feat;
    feat.setName("Greater Weapon Specialization");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Proficiency with selected weapon", "Greater Weapon Focus with selected weapon", "Weapon Focus with selected weapon", "Weapon Specialization with selected weapon", "12th-level fighter" });
    feat.setBenefit("You gain a +2 bonus on all damage rolls you make using the selected weapon. This bonus to damage stacks with other damage roll bonuses, including any you gain from Weapon Specialization.");
    return feat;
}
// H
Feat makeHeightenSpell() {
    Feat feat;
    feat.setName("Heighten Spell");
    feat.setType(Feat::FeatType::Metamagic);
    feat.setBenefit("A heightened spell has a higher spell level than normal (up to a maximum of 9th level). Unlike other metamagic feats, Heighten Spell actually increases the effective level of the spell that it modifies. All effects dependent on spell level (such as saving throw DCs and ability to penetrate a lesser globe of invulnerability) are calculated according to the heightened level. The heightened spell is as difficult to prepare and cast as a spell of its effective level.");
    return feat;
}
// I
Feat makeImprovedBullRush() {
    Feat feat;
    feat.setName("Improved Bull Rush");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Str 13", "Power Attack", "base attack bonus +1" });
    feat.setBenefit("You do not provoke an attack of opportunity when performing a bull rush combat maneuver. In addition, you receive a +2 bonus on checks made to bull rush a foe. You also receive a +2 bonus to your Combat Maneuver Defense whenever an opponent tries to bull rush you.");
    return feat;
}
Feat makeImprovedChannel() {
    Feat feat;
    feat.setName("Improved Channel");
    feat.setType(Feat::FeatType::General);
    feat.setPrerequisites({ "Channel energy class feature" });
    feat.setBenefit("Add 2 to the DC of saving throws made to resist the effects of your channel energy ability.");
    return feat;
}
Feat makeImprovedCounterspell() {
    Feat feat;
    feat.setName("Improved Counterspell");
    feat.setType(Feat::FeatType::General);
    feat.setBenefit("When counterspelling, you may use a spell of the same school that is one or more spell levels higher than the target spell.");
    return feat;
}
Feat makeImprovedCritical() {
    Feat feat;
    feat.setName("Improved Critical");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Proficiency with weapon", "base attack bonus +8" });
    feat.setBenefit("When using the weapon you selected, your threat range is doubled.");
    return feat;
}
Feat makeImprovedDisarm() {
    Feat feat;
    feat.setName("Improved Disarm");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Int 13", "Combat Expertise" });
    feat.setBenefit("You do not provoke an attack of opportunity when performing a disarm combat maneuver. In addition, you receive a +2 bonus on checks made to disarm a foe. You also receive a +2 bonus to your Combat Maneuver Defense whenever an opponent tries to disarm you.");
    return feat;
}
Feat makeImprovedFamiliar() {
    Feat feat;
    feat.setName("Improved Familiar");
    feat.setType(Feat::FeatType::General);
    feat.setPrerequisites({ "Ability to acquire a new familiar", "compatible alignment", "sufficiently high level (see below)" });
    feat.setBenefit("When choosing a familiar, the creatures listed below are also available to you. You may choose a familiar with an alignment up to one step away on each alignment axis (lawful through chaotic, good through evil).");
    return feat;
}
Feat makeImprvedFeint() {
    Feat feat;
    feat.setName("Improved Feint");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Int 13", "Combat Expertise" });
    feat.setBenefit("You can make a Bluff check to feint in combat as a move action.");
    return feat;
}
Feat makeImprovedGrapple() {
    Feat feat;
    feat.setName("Improved Grapple");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Dex 13", "Improved Unarmed Strike" });
    feat.setBenefit("You do not provoke an attack of opportunity when performing a grapple combat maneuver. In addition, you receive a +2 bonus on checks made to grapple a foe. You also receive a +2 bonus to your Combat Maneuver Defense whenever an opponent tries to grapple you.");
    return feat;
}
Feat makeImprovedGreatFortitude() {
    Feat feat;
    feat.setName("Improved Great Fortitude");
    feat.setType(Feat::FeatType::General);
    feat.setPrerequisites({ "Great Fortitude" });
    feat.setBenefit("Once per day, you may reroll a Fortitude save. You must decide to use this ability before the results are revealed. You must take the second roll, even if it is worse.");
    return feat;
}
Feat makeImprovedInitiative() {
    Feat feat;
    feat.setName("Improved Initiative");
    feat.setType(Feat::FeatType::Combat);
    feat.setBenefit("You get a +4 bonus on initiative checks.");
    return feat;
}
Feat makeImprovedIronWill() {
    Feat feat;
    feat.setName("Improved Iron Will");
    feat.setType(Feat::FeatType::General);
    feat.setPrerequisites({ "Iron Will" });
    feat.setBenefit("Once per day, you may reroll a Will save. You must decide to use this ability before the results are revealed. You must take the second roll, even if it is worse.");
    return feat;
}
Feat makeImproedLightningReflexes() {
    Feat feat;
    feat.setName("Improved Lightning Reflexes");
    feat.setType(Feat::FeatType::General);
    feat.setPrerequisites({ "Lightning Reflexes" });
    feat.setBenefit("Once per day, you may reroll a Reflex save. You must decide to use this ability before the results are revealed. You must take the second roll, even if it is worse.");
    return feat;
}
Feat makeImproedOverrun() {
    Feat feat;
    feat.setName("Improved Overrun");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Str 13", "Power Attack", "base attack bonus +1" });
    feat.setBenefit("You do not provoke an attack of opportunity when performing an overrun combat maneuver. In addition, you receive a +2 bonus on checks made to overrun a foe. You also receive a +2 bonus to your Combat Maneuver Defense whenever an opponent tries to overrun you. Targets of your overrun attempt may not choose to avoid you.");
    return feat;
}
Feat makeImprovedPreciseShot() {
    Feat feat;
    feat.setName("Improved Precise Shot");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Dex 19", "Point-Blank Shot", "Precise Shot", "base attack bonus +11" });
    feat.setBenefit("Your ranged attacks ignore the AC bonus granted to targets by anything less than total cover, and the miss chance granted to targets by anything less than total concealment. Total cover and total concealment provide their normal benefits against your ranged attacks.");
    return feat;
}
Feat makeImprovedShieldBash() {
    Feat feat;
    feat.setName("Improved Shield Bash");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Shield Proficiency" });
    feat.setBenefit("When you perform a shield bash, you may still apply the shield’s shield bonus to your AC.");
    return feat;
}
Feat makeImprovedSunder() {
    Feat feat;
    feat.setName("Improved Sunder");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Str 13", "Power Attack", "base attack bonus +1" });
    feat.setBenefit("You do not provoke an attack of opportunity when performing a sunder combat maneuver. In addition, you receive a +2 bonus on checks made to sunder an item. You also receive a +2 bonus to your Combat Maneuver Defense whenever an opponent tries to sunder your gear.");
    return feat;
}
Feat makeImprovedTrip() {
    Feat feat;
    feat.setName("Improved Trip");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Int 13", "Combat Expertise" });
    feat.setBenefit("You do not provoke an attack of opportunity when performing a trip combat maneuver. In addition, you receive a +2 bonus on checks made to trip a foe. You also receive a +2 bonus to your Combat Maneuver Defense whenever an opponent tries to trip you.");
    return feat;
}
Feat makeImprovedTwoWeaponFighting() {
    Feat feat;
    feat.setName("Improved Two-Weapon Fighting");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Dex 17", "Two-Weapon Fighting", "base attack bonus +6" });
    feat.setBenefit("In addition to the standard single extra attack you get with an off-hand weapon, you get a second attack with it, albeit at a –5 penalty.");
    return feat;
}
Feat makeImprovedUnarmedStrike() {
    Feat feat;
    feat.setName("Improved Unarmed Strike");
    feat.setType(Feat::FeatType::Combat);
    feat.setBenefit("You are considered to be armed even when unarmed—you do not provoke attacks of opportunity when you attack foes while unarmed. Your unarmed strikes can deal lethal or nonlethal damage, at your choice.");
    return feat;
}
Feat makeImproveditalStike() {
    Feat feat;
    feat.setName("Improved Vital Strike");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Vital Strike", "base attack bonus +11" });
    feat.setBenefit("When you use the attack action, you can make one attack at your highest base attack bonus that deals additional damage. Roll the weapon’s damage dice for the attack three times and add the results together before adding bonuses from Strength, weapon abilities (such as flaming), precision-based damage, and other damage bonuses. These extra weapon damage dice are not multiplied on a critical hit, but are added to the total.");
    return feat;
}
Feat makeImprovisedWeaponMastery() {
    Feat feat;
    feat.setName("Improvised Weapon Mastery");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Catch Off-Guard or Throw Anything", "base attack bonus +8" });
    feat.setBenefit("You do not suffer any penalties for using an improvised weapon. Increase the amount of damage dealt by the improvised weapon by one step (for example, 1d4 becomes 1d6) to a maximum of 1d8 (2d6 if the improvised weapon is two-handed). The improvised weapon has a critical threat range of 19–20, with a critical multiplier of ×2.");
    return feat;
}
Feat makeIntimidatingProwess() {
    Feat feat;
    feat.setName("Intimidating Prowess");
    feat.setType(Feat::FeatType::Combat);
    feat.setBenefit("Add your Strength modifier to Intimidate skill checks in addition to your Charisma modifier.");
    return feat;
}
Feat makeIronWill() {
    Feat feat;
    feat.setName("Iron Will");
    feat.setType(Feat::FeatType::General);
    feat.setBenefit("You get a +2 bonus on all Will saving throws.");
    return feat;
}
// L
Feat makeLeadership() {
    Feat feat;
    feat.setName("Leadership");
    feat.setType(Feat::FeatType::General);
    feat.setPrerequisites({ "Character level 7th" });
    feat.setBenefit("You can attract loyal companions and devoted followers, greatly increasing your power.");
    return feat;
}
Feat makeLightningReflexes() {
    Feat feat;
    feat.setName("Lightning Reflexes");
    feat.setType(Feat::FeatType::General);
    feat.setBenefit("You get a +2 bonus on all Reflex saving throws.");
    return feat;
}
Feat makeLightningStance() {
    Feat feat;
    feat.setName("Lightning Stance");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Dex 17", "Wind Stance", "base attack bonus +11" });
    feat.setBenefit("If you take two actions to move or a withdraw action in a turn, you gain 50% concealment for 1 round.");
    return feat;
}
Feat makeLunge() {
    Feat feat;
    feat.setName("Lunge");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Base attack bonus +6" });
    feat.setBenefit("You can increase the reach of your melee attacks by 5 feet until the end of your turn by taking a –2 penalty to your AC until your next turn. You must decide to use this ability before any attacks are made.");
    return feat;
}
// M
Feat makeMagicalAptitude() {
    Feat feat;
    feat.setName("Magical Aptitude");
    feat.setType(Feat::FeatType::General);
    feat.setBenefit("You get a +2 bonus on all Spellcraft checks and Use Magic Device checks. If you have 10 or more ranks in one of these skills, the bonus increases to +4 for that skill.");
    return feat;
}
Feat makeManyshot() {
    Feat feat;
    feat.setName("Manyshot");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Dex 17", "Point-Blank Shot", "Rapid Shot", "base attack bonus +6" });
    feat.setBenefit("When making a full-attack action with a bow, your first attack fires two arrows. If the attack hits, both arrows hit. Apply precision-based damage (such as sneak attack) and critical hit damage only once for this attack. Damage bonuses from using a composite bow with a high Strength bonus apply to each arrow, as do other damage bonuses, such as a ranger’s favored enemy bonus. Damage reduction and resistances apply separately to each arrow.");
    return feat;
}
Feat makeMartialWeaponProficiency() {
    Feat feat;
    feat.setName("Martial Weapon Proficiency");
    feat.setType(Feat::FeatType::Combat);
    feat.setBenefit("You make attack rolls with the selected weapon normally (without the non-proficient penalty).");
    return feat;
}
Feat makeMasterCraftsman() {
    Feat feat;
    feat.setName("Master Craftsman");
    feat.setType(Feat::FeatType::General);
    feat.setPrerequisites({ "5 ranks in any Craft or Profession skill" });
    feat.setBenefit("Choose one Craft or Profession skill in which you possess at least 5 ranks. You receive a +2 bonus on your chosen Craft or Profession skill. Ranks in your chosen skill count as your caster level for the purposes of qualifying for the Craft Magic Arms and Armor and Craft Wondrous Item feats. You can create magic items using these feats, substituting your ranks in the chosen skill for your total caster level. You must use the chosen skill for the check to create the item. The DC to create the item still increases for any necessary spell requirements (see the magic item creation rules). You cannot use this feat to create any spell-trigger or spell-completion magic items.");
    return feat;
}
Feat makeMaximizeSpell() {
    Feat feat;
    feat.setName("Maximize Spell");
    feat.setType(Feat::FeatType::Metamagic);
    feat.setBenefit("All variable, numeric effects of a spell modified by this feat are maximized. Saving throws and opposed rolls are not affected, nor are spells without random variables. A maximized spell uses up a spell slot three levels higher than the spell’s actual level.");
    return feat;
}
Feat makeMedusasWrath() {
    Feat feat;
    feat.setName("Medusa's Wrath");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Improved Unarmed Strike", "Gorgon's Fist", "Scorpion Style", "base attack bonus +11" });
    feat.setBenefit("Whenever you use the full-attack action and make at least one unarmed strike, you can make two additional unarmed strikes at your highest base attack bonus. These bonus attacks must be made against a dazed, flat-footed, paralyzed, staggered, stunned, or unconscious foe.");
    return feat;
}
Feat makeMobility() {
    Feat feat;
    feat.setName("Mobility");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Dex 13", "Dodge" });
    feat.setBenefit("You get a +4 dodge bonus to Armor Class against attacks of opportunity caused when you move out of or within a threatened area. A condition that makes you lose your Dexterity bonus to Armor Class (if any) also makes you lose dodge bonuses. Dodge bonuses stack with each other, unlike most types of bonuses.");
    return feat;
}
Feat makeMountedArchery() {
    Feat feat;
    feat.setName("Mounted Archery");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Ride 1 rank", "Mounted Combat" });
    feat.setBenefit("The penalty you take when using a ranged weapon while mounted is halved: –2 instead of –4 if your mount is taking a double move, and –4 instead of –8 if your mount is running.");
    return feat;
}
Feat makeMountedCombat() {
    Feat feat;
    feat.setName("Mounted Combat");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Ride 1 rank" });
    feat.setBenefit("Once per round when your mount is hit in combat, you may attempt a Ride check (as an immediate action) to negate the hit. The hit is negated if your Ride check result is greater than the opponent’s attack roll.");
    return feat;
}
// N
Feat makeNaturalSpell() {
    Feat feat;
    feat.setName("Natural Spell");
    feat.setType(Feat::FeatType::General);
    feat.setPrerequisites({ "Wis 13", "wild shape class feature" });
    feat.setBenefit("You can complete the verbal and somatic components of spells while in a wild shape. You substitute various noises and gestures for the normal verbal and somatic components of a spell. You can also use any material components or focuses you possess, even if such items are melded within your current form. This feat does not permit the use of magic items while you are in a form that could not ordinarily use them, and you do not gain the ability to speak while in a wild shape.");
    return feat;
}
Feat makeNimbleMoves() {
    Feat feat;
    feat.setName("Nimble Moves");
    feat.setType(Feat::FeatType::General);
    feat.setPrerequisites({ "Dex 13" });
    feat.setBenefit("Whenever you move, you may move through 5 feet of difficult terrain each round as if it were normal terrain. This feat allows you to take a 5-foot step into difficult terrain.");
    return feat;
}
// P
Feat makePenetratingStrike() {
    Feat feat;
    feat.setName("Penetrating Strike");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Weapon Focus", "base attack bonus +1", "12th-level fighter" });
    feat.setBenefit("Your attacks made with weapons selected with Weapon Focus ignore up to 5 points of damage reduction. This feat does not apply to damage reduction without a type (such as DR 10/—).");
    return feat;
}
Feat makePersuasive() {
    Feat feat;
    feat.setName("Persuasive");
    feat.setType(Feat::FeatType::General);
    feat.setBenefit("You get a +2 bonus on Diplomacy and Intimidate skill checks. If you have 10 or more ranks in one of these skills, the bonus increases to +4 for that skill.");
    return feat;
}
Feat makePinpointTargeting() {
    Feat feat;
    feat.setName("Pinpoint Targeting");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Improved Precise Shot", "base attack bonus +16" });
    feat.setBenefit("As a standard action, make a single ranged attack. The target does not gain any armor, natural armor, or shield bonuses to its Armor Class. You do not gain the benefit of this feat if you move this round.");
    return feat;
}
Feat makePointBlankShot() {
    Feat feat;
    feat.setName("Point-Blank Shot");
    feat.setType(Feat::FeatType::Combat);
    feat.setBenefit("You get a +1 bonus on attack and damage rolls with ranged weapons at ranges of up to 30 feet.");
    return feat;
}
Feat makePowerAttack() {
    Feat feat;
    feat.setName("Power Attack");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Str 13", "base attack bonus +1" });
    feat.setBenefit("You can choose to take a –1 penalty on all melee attack rolls and combat maneuver checks to gain a +2 bonus on all melee damage rolls. This bonus to damage is increased by half (+50%) if you are making an attack with a two-handed weapon, a one handed weapon using two hands, or a primary natural weapon that adds 1-1/2 times your Strength modifier on damage rolls. This bonus to damage is halved (–50%) if you are making an attack with an off-hand weapon or secondary natural weapon. When your base attack bonus reaches +4, and every 4 points thereafter, the penalty increases by –1 and the bonus to damage increases by +2. You must choose to use this feat before making an attack roll, and its effects last until your next turn. The bonus damage does not apply to touch attacks or effects that do not deal hit point damage.");
    return feat;
}
Feat makePreciseShot() {
    Feat feat;
    feat.setName("Precise Shot");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Point-Blank Shot" });
    feat.setBenefit("You can shoot or throw ranged weapons at an opponent engaged in melee without taking the standard –4 penalty on your attack roll.");
    return feat;
}
// Q
Feat makeQuickDraw() {
    Feat feat;
    feat.setName("Quick Draw");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Base attack bonus +1" });
    feat.setBenefit("You can draw a weapon as a free action instead of as a move action. You can draw a hidden weapon (see the Sleight of Hand skill) as a move action. A character who has selected this feat may throw weapons at his full normal rate of attacks (much like a character with a bow). Alchemical items, potions, scrolls, and wands cannot be drawn quickly using this feat.");
    return feat;
}
Feat makeQuickenSpell() {
    Feat feat;
    feat.setName("Quicken Spell");
    feat.setType(Feat::FeatType::Metamagic);
    feat.setBenefit("Casting a quickened spell is a swift action. You can perform another action, even casting another spell, in the same round as you cast a quickened spell. A spell whose casting time is more than 1 round or 1 full-round action cannot be quickened. A quickened spell uses up a spell slot four levels higher than the spell’s actual level. Casting a quickened spell doesn’t provoke an attack of opportunity.");
    return feat;
}
// R
Feat makeRapidReload() {
    Feat feat;
    feat.setName("Rapid Reload");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Weapon Proficiency (crossbow)" });
    feat.setBenefit("The time required for you to reload your chosen type of crossbow is reduced to a free action (for a hand or light crossbow) or a move action (for a heavy crossbow). Reloading a crossbow still provokes an attack of opportunity. If you have selected this feat for hand crossbow or light crossbow, you may fire that weapon as many times in a full-attack action as you could attack if you were using a bow.");
    return feat;
}
Feat makeRapidShot() {
    Feat feat;
    feat.setName("Rapid Shot");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Dex 13", "Point-Blank Shot" });
    feat.setBenefit("When making a full-attack action with a ranged weapon, you can fire one additional time this round. All of your attack rolls take a –2 penalty when using Rapid Shot.");
    return feat;
}
Feat makeRideByAttack() {
    Feat feat;
    feat.setName("Ride-By Attack");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Ride 1 rank", "Mounted Combat" });
    feat.setBenefit("When you are mounted and use the charge action, you may move and attack as if with a standard charge and then move again (continuing the straight line of the charge). Your total movement for the round can’t exceed double your mounted speed. You and your mount do not provoke an attack of opportunity from the opponent that you attack.");
    return feat;
}
Feat makeRun() {
    Feat feat;
    feat.setName("Run");
    feat.setType(Feat::FeatType::General);
    feat.setBenefit("When running, you move five times your normal speed (if wearing medium, light, or no armor and carrying no more than a medium load) or four times your speed (if wearing heavy armor or carrying a heavy load). If you make a jump after a running start (see the Acrobatics skill description), you gain a +4 bonus on your Acrobatics check. While running, you retain your Dexterity bonus to your Armor Class.");
    return feat;
}
// S
Feat makeScorpionStyle() {
    Feat feat;
    feat.setName("Scorpion Style");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Improved Unarmed Strike" });
    feat.setBenefit("To use this feat, you must make a single unarmed attack as a standard action. If this unarmed attack hits, you deal damage normally, and the target’s base land speed is reduced to 5 feet for a number of rounds equal to your Wisdom modifier unless it makes a Fortitude saving throw (DC 10 + 1/2 your character level + your Wis modifier).");
    return feat;
}
Feat makeScribeScroll() {
    Feat feat;
    feat.setName("Scribe Scroll");
    feat.setType(Feat::FeatType::ItemCreation);
    feat.setPrerequisites({ "Caster level 1st" });
    feat.setBenefit("You can create a scroll of any spell that you know.");
    return feat;
}
Feat makeSelectiveChanneling() {
    Feat feat;
    feat.setName("Selective Channeling");
    feat.setType(Feat::FeatType::General);
    feat.setPrerequisites({ "Cha 13", "channel energy class feature" });
    feat.setBenefit("When you channel energy, you can choose a number of targets in the area up to your Charisma modifier. These targets are not affected by your channeled energy.");
    return feat;
}
Feat makeSelfSufficient() {
    Feat feat;
    feat.setName("Self-Sufficient");
    feat.setType(Feat::FeatType::General);
    feat.setBenefit("You get a +2 bonus on all Heal checks and Survival checks. If you have 10 or more ranks in one of these skills, the bonus increases to +4 for that skill.");
    return feat;
}
Feat makeShatterDefenses() {
    Feat feat;
    feat.setName("Shatter Defenses");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Weapon Focus", "Dazzling Display", "base attack bonus +6" });
    feat.setBenefit("Any shaken, frightened, or panicked opponent hit by you this round is flat-footed to your attacks until the end of your next turn. This includes any additional attacks you make this round.");
    return feat;
}
Feat makeShieldFocus() {
    Feat feat;
    feat.setName("Shield Focus");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Shield Proficiency", "base attack bonus +1" });
    feat.setBenefit("Increase the AC bonus granted by any shield you are using by 1.");
    return feat;
}
Feat makeShieldMaster() {
    Feat feat;
    feat.setName("Shield Master");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Improved Shield Bash", "Shield Proficiency", "Shield Slam", "Two-Weapon Fighting", "base attack bonus +11" });
    feat.setBenefit("Your shield bash attacks do not suffer the penalty to attack rolls for using an off-hand weapon. Add your shield’s enhancement bonus to attack and damage rolls made with your shield.");
    return feat;
}
Feat makeShieldProficiency() {
    Feat feat;
    feat.setName("Shield Proficiency");
    feat.setType(Feat::FeatType::Combat);
    feat.setBenefit("When you use a shield (except a tower shield), the shield’s armor check penalty only applies to Strength- and Dexterity-based skills.");
    return feat;
}
Feat makeShieldSlam() {
    Feat feat;
    feat.setName("Shield Slam");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Improved Shield Bash", "Shield Proficiency", "Two-Weapon Fighting", "base attack bonus +6" });
    feat.setBenefit("Any opponents hit by your shield bash are also hit with a free bull rush attack, substituting your attack roll for the combat maneuver check. This bull rush does not provoke an attack of opportunity. Opponents who cannot move back due to a wall or other surface are knocked prone after moving the maximum possible distance. You may choose to move with your target if you are able to take a 5-foot step or to spend an action to move this turn.");
    return feat;
}
Feat makeShotOnTheRun() {
    Feat feat;
    feat.setName("Shot on the Run");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Dex 13", "Dodge", "Mobility", "Point-Blank Shot", "base attack bonus +4" });
    feat.setBenefit("As a full-round action, you can move up to your speed and make a single ranged attack at any point during your movement.");
    return feat;
}
Feat makeSickeningCritical() {
    Feat feat;
    feat.setName("Sickening Critical");
    feat.setType(Feat::FeatType::Critical);
    feat.setPrerequisites({ "Critical Focus", "base attack bonus +11" });
    feat.setBenefit("Whenever you score a critical hit, your opponent becomes sickened for 1 minute. The effects of this feat do not stack. Additional hits instead add to the effect’s duration.");
    return feat;
}
Feat makeSilentSpell() {
    Feat feat;
    feat.setName("Silent Spell");
    feat.setType(Feat::FeatType::Metamagic);
    feat.setBenefit("A silent spell can be cast with no verbal components. Spells without verbal components are not affected. A silent spell uses up a spell slot one level higher than the spell’s actual level.");
    return feat;
}
Feat makeSimpleWeaponProficiency() {
    Feat feat;
    feat.setName("Simple Weapon Proficiency");
    feat.setType(Feat::FeatType::Combat);
    feat.setBenefit("You make attack rolls with simple weapons normally (without the non-proficient penalty).");
    return feat;
}
Feat makeSkillFocus() {
    Feat feat;
    feat.setName("Skill Focus");
    feat.setType(Feat::FeatType::General);
    feat.setBenefit("You get a +3 bonus on all checks involving the chosen skill. If you have 10 or more ranks in that skill, this bonus increases to +6.");
    return feat;
}
Feat makeSnatchArrows() {
    Feat feat;
    feat.setName("Snatch Arrows");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Dex 15", "Deflect Arrows", "Improved Unarmed Strike" });
    feat.setBenefit("When using the Deflect Arrows feat you may choose to catch the weapon instead of just deflecting it. Thrown weapons can immediately be thrown back as an attack against the original attacker (even though it isn’t your turn) or kept for later use. You must have at least one hand free (holding nothing) to use this feat.");
    return feat;
}
Feat makeSpellFocus() {
    Feat feat;
    feat.setName("Spell Focus");
    feat.setType(Feat::FeatType::General);
    feat.setBenefit("Add +1 to the Difficulty Class for all saving throws against spells from the school of magic you select.");
    return feat;
}
Feat makeSpellMastery() {
    Feat feat;
    feat.setName("Spell Mastery");
    feat.setType(Feat::FeatType::General);
    feat.setPrerequisites({ "1st-level Wizard" });
    feat.setBenefit("Each time you take this feat, choose a number of spells that you already know equal to your Intelligence modifier. From that point on, you can prepare these spells without referring to a spellbook.");
    return feat;
}
Feat makeSpellPenetration() {
    Feat feat;
    feat.setName("Spell Penetration");
    feat.setType(Feat::FeatType::General);
    feat.setBenefit("You get a +2 bonus on caster level checks (1d20 + caster level) made to overcome a creature’s spell resistance.");
    return feat;
}
Feat makeSpellbreaker() {
    Feat feat;
    feat.setName("Spellbreaker");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Disruptive", "10th-level fighter" });
    feat.setBenefit("Enemies in your threatened area that fail their checks to cast spells defensively provoke attacks of opportunity from you.");
    return feat;
}
Feat makeSpiritedCharge() {
    Feat feat;
    feat.setName("Spirited Charge");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Ride 1 rank", "Mounted Combat", "Ride-By Attack" });
    feat.setBenefit("When mounted and using the charge action, you deal double damage with a melee weapon (or triple damage with a lance).");
    return feat;
}
Feat makeSpringAttack() {
    Feat feat;
    feat.setName("Spring Attack");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Dex 13", "Dodge", "Mobility", "base attack bonus +4" });
    feat.setBenefit("As a full-round action, you can move up to your speed and make a single melee attack without provoking any attacks of opportunity from the target of your attack. You can move both before and after the attack, but you must move at least 10 feet before the attack and the total distance that you move cannot be greater than your speed. You cannot use this ability to attack a foe that is adjacent to you at the start of your turn.");
    return feat;
}
Feat makeStaggeringCritical() {
    Feat feat;
    feat.setName("Staggering Critical");
    feat.setType(Feat::FeatType::Critical);
    feat.setPrerequisites({ "Critical Focus", "base attack bonus +13" });
    feat.setBenefit("Whenever you score a critical hit, your opponent becomes staggered for 1d4+1 rounds. A successful Fortitude save reduces the duration to 1 round. The DC of this Fortitude save is equal to 10 + your base attack bonus. The effects of this feat do not stack. Additional hits instead add to the duration.");
    return feat;
}
Feat makeStandStill() {
    Feat feat;
    feat.setName("Stand Still");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Combat Reflexes" });
    feat.setBenefit("When a foe provokes an attack of opportunity by moving through your adjacent squares, you can make a combat maneuver check as your attack of opportunity. If successful, the enemy cannot move for the rest of his turn. An enemy can still take the rest of his action, but cannot move. This feat also applies to any creature that attempts to move from a square that is adjacent to you if such movement provokes an attack of opportunity.");
    return feat;
}
Feat makeStealthy() {
    Feat feat;
    feat.setName("Stealthy");
    feat.setType(Feat::FeatType::General);
    feat.setBenefit("You get a +2 bonus on all Escape Artist and Stealth skill checks. If you have 10 or more ranks in one of these skills, the bonus increases to +4 for that skill.");
    return feat;
}
Feat makeStepUp() {
    Feat feat;
    feat.setName("Step Up");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Base attack bonus +1" });
    feat.setBenefit("Whenever an adjacent foe attempts to take a 5-foot step away from you, you may also make a 5-foot step as an immediate action so long as you end up adjacent to the foe that triggered this ability. If you take this step, you cannot take a 5-foot step during your next turn. If you take an action to move during your next turn, subtract 5 feet from your total movement.");
    return feat;
}
Feat makeStillSpell() {
    Feat feat;
    feat.setName("Still Spell");
    feat.setType(Feat::FeatType::Metamagic);
    feat.setBenefit("A stilled spell can be cast with no somatic components. Spells without somatic components are not affected. A stilled spell uses up a spell slot one level higher than the spell’s actual level.");
    return feat;
}
Feat makeStrikeBack() {
    Feat feat;
    feat.setName("Strike Back");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Base attack bonus +11" });
    feat.setBenefit("You can ready an action to make a melee attack against any foe that attacks you in melee, even if the foe is outside of your reach.");
    return feat;
}
Feat makeStunningCritical() {
    Feat feat;
    feat.setName("Stunning Critical");
    feat.setType(Feat::FeatType::Critical);
    feat.setPrerequisites({ "Critical Focus", "Staggering Critical", "base attack bonus +17" });
    feat.setBenefit("Whenever you score a critical hit, your opponent becomes stunned for 1d4 rounds. A successful Fortitude save reduces this to staggered for 1d4 rounds. The DC of this Fortitude save is equal to 10 + your base attack bonus. The effects of this feat do not stack. Additional hits instead add to the duration.");
    return feat;
}
Feat makeStunningFist() {
    Feat feat;
    feat.setName("Stunning Fist");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Dex 13", "Wis 13", "Improved Unarmed Strike", "base attack bonus +8" });
    feat.setBenefit("You must declare that you are using this feat before you make your attack roll (thus, a failed attack roll ruins the attempt). Stunning Fist forces a foe damaged by your unarmed attack to make a Fortitude saving throw (DC 10 + 1/2 your character level + your Wis modifier), in addition to dealing damage normally. A defender who fails this saving throw is stunned for 1 round (until just before your next turn). A stunned character can’t take actions, loses any Dexterity bonus to AC, and takes a –2 penalty to AC. You may attempt a stunning attack once per day for every four levels you have attained (but see Special), and no more than once per round. Constructs, oozes, plants, undead, incorporeal creatures, and creatures immune to critical hits cannot be stunned.");
    return feat;
}
// T
Feat makeThrowAnything() {
    Feat feat;
    feat.setName("Throw Anything");
    feat.setType(Feat::FeatType::Combat);
    feat.setBenefit("You do not suffer any penalties for using an improvised ranged weapon. You receive a +1 circumstance bonus on attack rolls made with thrown splash weapons.");
    return feat;
}
Feat makeTiringCritical() {
    Feat feat;
    feat.setName("Tiring Critical");
    feat.setType(Feat::FeatType::Critical);
    feat.setPrerequisites({ "Critical Focus", "base attack bonus +13" });
    feat.setBenefit("Whenever you score a critical hit, your opponent becomes fatigued. This feat has no additional effect on a fatigued or exhausted creature.");
    return feat;
}
Feat makeToughness() {
    Feat feat;
    feat.setName("Toughness");
    feat.setType(Feat::FeatType::General);
    feat.setBenefit("You gain +3 hit points. For every Hit Die you possess beyond 3, you gain an additional +1 hit point. If you have more than 3 Hit Dice, you gain +1 hit points whenever you gain a Hit Die (such as when you gain a level).");
    return feat;
}
Feat makeTowerShieldProficiency() {
    Feat feat;
    feat.setName("Tower Shield Proficiency");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Shield Proficiency" });
    feat.setBenefit("When you use a tower shield, the shield’s armor check penalty only applies to Strength and Dexterity-based skills.");
    return feat;
}
Feat makeTrample() {
    Feat feat;
    feat.setName("Trample");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Mounted Combat", "Ride 1 rank" });
    feat.setBenefit("When you attempt to overrun an opponent while mounted, your target may not choose to avoid you. Your mount may make one hoof attack against any target you knock down, gaining the standard +4 bonus on attack rolls against prone targets.");
    return feat;
}
Feat makeTurnUndead() {
    Feat feat;
    feat.setName("Turn Undead");
    feat.setType(Feat::FeatType::General);
    feat.setPrerequisites({ "Channel positive energy class feature" });
    feat.setBenefit("You can, as a standard action, use one of your uses of channel positive energy to cause all undead within 30 feet of you to flee, as if panicked. Undead receive a Will save to negate the effect. The DC for this Will save is equal to 10 + 1/2 your cleric level + your Charisma modifier. Undead that fail their save flee for 1 minute. Intelligent undead receive a new saving throw each round to end the effect. If you use channel energy in this way, it has no other effect (it does not heal or harm nearby creatures).");
    return feat;
}
Feat makeTwoWeaponDefense() {
    Feat feat;
    feat.setName("Two-Weapon Defense");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Dex 15", "Two-Weapon Fighting" });
    feat.setBenefit("When wielding a double weapon or two weapons (not including natural weapons or unarmed strikes), you gain a +1 shield bonus to your AC. When you are fighting defensively or using the total defense action, this shield bonus increases to +2.");
    return feat;
}
Feat makeTwoWeaponFighting() {
    Feat feat;
    feat.setName("Two-Weapon Fighting");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Dex 15" });
    feat.setBenefit("Your penalties on attack rolls for fighting with two weapons are reduced. The penalty for your primary hand lessens by 2 and the one for your off hand lessens by 6.");
    return feat;
}
Feat makeTwoWeaponRend() {
    Feat feat;
    feat.setName("Two-Weapon Rend");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Double Slice", "Improved Two-Weapon Fighting", "Two-Weapon Fighting", "base attack bonus +11" });
    feat.setBenefit("If you hit an opponent with both your primary hand and your off-hand weapon, you deal an additional 1d10 points of damage plus 1-1/2 times your Strength modifier. You can only deal this additional damage once each round.");
    return feat;
}
// U
Feat makeUnseat() {
    Feat feat;
    feat.setName("Unseat");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Mounted Combat", "Improved Bull Rush", "Power Attack", "Ride 1 rank", "Str 13", "base attack bonus +1" });
    feat.setBenefit("When charging on horseback and attacking with a lance, you can choose to make a bull rush attempt against the target of your charge as a free action. If the bull rush attempt succeeds, you can knock your opponent off his horse and move with the target, up to your remaining movement.");
    return feat;
}
// V
Feat makeVitalStrike() {
    Feat feat;
    feat.setName("Vital Strike");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Base attack bonus +6" });
    feat.setBenefit("When you use the attack action, you can make one attack at your highest base attack bonus that deals additional damage. Roll the weapon’s damage dice for the attack twice and add the results together before adding bonuses from Strength, weapon abilities (such as flaming), precision based damage, and other damage bonuses. These extra weapon damage dice are not multiplied on a critical hit, but are added to the total.");
    return feat;
}
// W
Feat makeWeaponFinesse() {
    Feat feat;
    feat.setName("Weapon Finesse");
    feat.setType(Feat::FeatType::Combat);
    feat.setBenefit("With a light weapon, rapier, whip, or spiked chain made for a creature of your size category, you may use your Dexterity modifier instead of your Strength modifier on attack rolls. If you carry a shield, its armor check penalty applies to your attack rolls.");
    return feat;
}
Feat makeWeaponFocus() {
    Feat feat;
    feat.setName("Weapon Focus");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Proficiency with selected weapon", "base attack bonus +1" });
    feat.setBenefit("You gain a +1 bonus on all attack rolls you make using the selected weapon.");
    return feat;
}
Feat makeWeaponSpecialization() {
    Feat feat;
    feat.setName("Weapon Specialization");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Proficiency with selected weapon", "Weapon Focus with selected weapon", "4th-level fighter" });
    feat.setBenefit("You gain a +2 bonus on all damage rolls you make using the selected weapon.");
    return feat;
}
Feat makeWhirlwindAttack() {
    Feat feat;
    feat.setName("Whirlwind Attack");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Dex 13", "Int 13", "Combat Expertise", "Dodge", "Mobility", "Spring Attack", "base attack bonus +4" });
    feat.setBenefit("When you use the full-attack action, you can give up your regular attacks and instead make one melee attack at your highest base attack bonus against each opponent within reach. You must make a separate attack roll against each opponent. When you use the Whirlwind Attack feat, you also forfeit any bonus or extra attacks granted by other feats, spells, or abilities.");
    return feat;
}
Feat makeWidenSpell() {
    Feat feat;
    feat.setName("Widen Spell");
    feat.setType(Feat::FeatType::Metamagic);
    feat.setBenefit("You can alter a burst, emanation, line, or spread-shaped spell to increase its area. Any numeric measurements of the spell’s area increase by 100%. A widened spell uses up a spell slot three levels higher than the spell’s actual level.");
    return feat;
}
Feat makeWindStance() {
    Feat feat;
    feat.setName("Wind Stance");
    feat.setType(Feat::FeatType::Combat);
    feat.setPrerequisites({ "Dex 15", "Dodge", "base attack bonus +6" });
    feat.setBenefit("If you move more than 5 feet this turn, you gain 20% concealment for 1 round against ranged attacks.");
    return feat;
}