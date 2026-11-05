#pragma once
#include <string>
#include <vector>

class Feat {
public:
	enum class FeatType {
		General, Combat, Critical, ItemCreation, Metamagic
	};

private:
	// Name of the Feat
	std::string name;

	// Category of Feat
	// Default is General
	FeatType type = FeatType::General;

	// List of prerequisites
	std::vector<std::string> prerequisites;

	// Feat Benefits
	std::string benefit;

public:
	// Getters
	std::string getName() const {
		return name;
	}
	FeatType getType() const {
		return type;
	}
	const std::vector<std::string>& getPrerequisites() const {
		return prerequisites;
	}
	std::string getBenefit() const {
		return benefit;
	}

	// Setters
	void setName(const std::string& n) {
		name = n;
	}
	void setType(FeatType t) {
		type = t;
	}
	void setPrerequisites(const std::vector<std::string>& prereqs) {
		prerequisites = prereqs;
	}
	void addPrerequisite(const std::string& prereq) {
		prerequisites.push_back(prereq);
	}
	void setBenefit(const std::string& b) {
		benefit = b;
	}

	// Print
	void print() const;
};

// Declaration of functions to apply Feat templates
// A
Feat makeAcrobatic();
Feat makeAcrobaticSteps();
Feat makeAgileManeuvers();
Feat makeAlertness();
Feat makeAlignmentChannel();
Feat makeAnimalAffinity();
Feat makeArcaneArmorMastery();
Feat makeArcaneArmorTraining();
Feat makeArcaneStrike();
Feat makeArmorProficiencyHeavy();
Feat makeArmorProficiencyLight();
Feat makeArmorProficiencyMedium();
Feat makeAthletic();
Feat makeAugmentSummoning();
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