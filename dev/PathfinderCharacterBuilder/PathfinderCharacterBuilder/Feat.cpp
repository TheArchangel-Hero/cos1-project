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
Feat makeBleedingCritical();
Feat makeBlindFight();
Feat makeBlindingCritical();
Feat makeBrewPotion();
// C
Feat makeCatchOffGuard();
Feat makeChannelSmite();
Feat makeCleave();
Feat makeCombatCasting();
Feat makeCombatExpertise();
Feat makeCombatReflexes();
Feat makeCommandUndead();
Feat makeCraftMagicArmsAndArmor();
Feat makeCraftRod();
Feat makeCraftStaff();
Feat makeCraftWand();
Feat makeCraftWonderousItem();
Feat makeCriticalFocus();
Feat makeCriticalMastery();
// D
Feat makeDazzlingDisplay();
Feat makeDeadlyAim();
Feat makeDeadlyStroke();
Feat makeDeafeningCritical();
Feat makeDeceitful();
Feat makeDefensiveCombatTraining();
Feat makeDeflectArrows();
Feat makeDeftHands();
Feat makeDiehard();
Feat makeDisruptive();
Feat makeDodge();
Feat makeDoubleSlice();
// E
Feat makeElementalChannel();
Feat makeEmpowerSpell();
Feat makeEndurance();
Feat makeEnlargeSpell();
Feat makeEschewMaterials();
Feat makeExhaustingCritical();
Feat makeExtendSpell();
Feat makeExtraChannel();
Feat makeExtraKi();
Feat makeExtraLayOnHands();
Feat makeExtraMercy();
Feat makeExtraPerformance();
Feat makeExtraRage();
// F
Feat makeFarShot();
Feat makeFleet();
Feat makeForgeRing();
// G
Feat makeGorgonsFist();
Feat makeGreatCleave();
Feat makeGreatFortitude();
Feat makeGreaterBullRush();
Feat makeGreaterDisarm();
Feat makeGreaterFeint();
Feat makeGreaterGrapple();
Feat makeGreaterOverrun();
Feat makeGreaterPenetratingStrike();
Feat makeGreaterShieldFocus();
Feat makeGreaterSpellFocus();
Feat makeGreaterSpellPenetration();
Feat makeGreaterSunder();
Feat makeGreaterTrip();
Feat makeGreaterTwoWeaponFighting();
Feat makeGreaterVitalStrike();
Feat makeGreaterWeaponFocus();
Feat makeGreaterWeaponSpecialization();
// H
Feat makeHeightenSpell();
// I
Feat makeImprovedBullRush();
Feat makeImprovedChannel();
Feat makeImprovedCounterspell();
Feat makeImprovedCritical();
Feat makeImprovedDisarm();
Feat makeImprovedFamiliar();
Feat makeImprvedFeint();
Feat makeImprovedGrapple();
Feat makeImprovedGreatFortitude();
Feat makeImprovedInitiative();
Feat makeImprovedIronWill();
Feat makeImproedLightningReflexes();
Feat makeImproedOverrun();
Feat makeImprovedPreciseShot();
Feat makeImprovedShieldBash();
Feat makeImprovedSunder();
Feat makeImprovedTrip();
Feat makeImprovedTwoWeaponFighting();
Feat makeImprovedUnarmedStrike();
Feat makeImproveditalStike();
Feat makeImprovisedWeaponMastery();
Feat makeIntimidatingProwess();
Feat makeIronWill();
// L
Feat makeLeadership();
Feat makeLightningReflexes();
Feat makeLightningStance();
Feat makeLunge();
// M
Feat makeMagicalAptitude();
Feat makeManyshot();
Feat makeMartialWeaponProficiency();
Feat makeMasterCraftsman();
Feat makeMaximizeSpell();
Feat makeMedusasWrath();
Feat makeMobility();
Feat makeMountedArchery();
Feat makeMountedCombat();
// N
Feat makeNaturalSpell();
Feat makeNimbleMoves();
// P
Feat makePenetratingStrike();
Feat makePersuasive();
Feat makePinpointTargeting();
Feat makePointBlankShot();
Feat makePowerAttack();
Feat makePreciseShot();
// Q
Feat makeQuickDraw();
Feat makeQuickenSpell();
// R
Feat makeRapidReload();
Feat makeRapidShot();
Feat makeRideByAttack();
Feat makeRun();
// S
Feat makeScorpionStyle();
Feat makeScribeScroll();
Feat makeSelectiveChanneling();
Feat makeSelfSufficient();
Feat makeShatterDefenses();
Feat makeShieldFocus();
Feat makeShieldMaster();
Feat makeShieldProficiency();
Feat makeShieldSlam();
Feat makeShotOnTheRun();
Feat makeSickeningCritical();
Feat makeSilentSpell();
Feat makeSimpleWeaponProficiency();
Feat makeSkillFocus();
Feat makeSnatchArrows();
Feat makeSpellFocus();
Feat makeSpellMastery();
Feat makeSpellPenetration();
Feat makeSpellbreaker();
Feat makeSpiritedCharge();
Feat makeSpringAttack();
Feat makeStaggeringCritical();
Feat makeStandStill();
Feat makeStealthy();
Feat makeStepUp();
Feat makeStillSpell();
Feat makeStrikeBack();
Feat makeStunningCritical();
Feat makeStunningFist();
// T
Feat makeThrowAnything();
Feat makeTiringCritical();
Feat makeToughness();
Feat makeTowerShieldProficiency();
Feat makeTrample();
Feat makeTurnUndead();
Feat makeTwoWeaponDefense();
Feat makeTwoWeaponFighting();
Feat makeTwoWeaponRend();
// U
Feat makeUnseat();
// V
Feat makeVitalStrike();
// W
Feat makeWeaponFinesse();
Feat makeWeaponFocus();
Feat makeWeaponSpecialization();
Feat makeWhirlwindAttack();
Feat makeWidenSpell();
Feat makeWindStance();