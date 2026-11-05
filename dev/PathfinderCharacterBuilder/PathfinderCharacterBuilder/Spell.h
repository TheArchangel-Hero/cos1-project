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
// Note: Only Spells beginning with A-H are declared
// TO DO: Declare remaining Spells
// A
Spell makeAcidArrow();
Spell makeAcidFog();
Spell makeAcidSplash();
Spell makeAid();
Spell makeAirWalk();
Spell makeAlarm();
Spell makeAlignWeapon();
Spell makeAlterSelf();
Spell makeAnalyzeDweomer();
Spell makeAnimalGrowth();
Spell makeAnimalMessenger();
Spell makeAnimalShapes();
Spell makeAnimalTrance();
Spell makeAnimateDead();
Spell makeAnimateObjects();
Spell makeAnimatePlants();
Spell makeAnimateRope();
Spell makeAntilifeShell();
Spell makeAntimagicField();
Spell makeAntipathy();
Spell makeAntiplantShell();
Spell makeArcaneEye();
Spell makeArcaneLock();
Spell makeArcaneMark();
Spell makeArcaneSight();
Spell makeArcaneSightGreater();
Spell makeAstralProjection();
Spell makeAtonement();
Spell makeAugury();
Spell makeAwaken();
// B
Spell makeBalefulPolymorph();
Spell makeBane();
Spell makeBanishment();
Spell makeBarkskin();
Spell makeBearsEndurance();
Spell makeBearsEnduranceMass();
Spell makeBeastShape1();
Spell makeBeastShape2();
Spell makeBeastShape3();
Spell makeBeastShape4();
Spell makeBestowCurse();
Spell makeBinding();
Spell makeBlackTentacles();
Spell makeBladeBarrier();
Spell makeBlasphemy();
Spell makeBleed();
Spell makeBless();
Spell makeBlessWater();
Spell makeBlessWeapon();
Spell makeBlindnessDeafness();
Spell makeBlink();
Spell makeBlight();
Spell makeBlur();
Spell makeBreakEnchantment();
Spell makeBreathOfLife();
Spell makeBullsStrength();
Spell makeBullsStrengthMass();
Spell makeBurningHands();
// C
Spell makeCallLightning();
Spell makeCallLightningStorm();
Spell makeCalmAnimals();
Spell makeCalmEmotions();
Spell makeCatsGrace();
Spell makeCatsGraceMass();
Spell makeCauseFear();
Spell makeChainLightning();
Spell makeChangestaff();
Spell makeChaosHammer();
Spell makeCharmAnimal();
Spell makeCharmMonster();
Spell makeCharmMonsterMass();
Spell makeCharmPerson();
Spell makeChillMetal();
Spell makeChillTouch();
Spell makeCircleOfDeath();
Spell makeClairaudienceClairvoyance();
Spell makeClenchedFist();
Spell makeCloakOfChaos();
Spell makeClone();
Spell makeCloudkill();
Spell makeColorSpray();
Spell makeCommand();
Spell makeCommandGreater();
Spell makeCommandPlants();
Spell makeCommandUndead();
Spell makeCommune();
Spell makeCommuneWithNature();
Spell makeComprehendLanguages();
Spell makeConeOfCold();
Spell makeConfusion();
Spell makeConfusionLesser();
Spell makeConsecrate();
Spell makeContactOtherPlane();
Spell makeContagion();
Spell makeContingency();
Spell makeContinualFlame();
Spell makeControlPlants();
Spell makeControlUndead();
Spell makeControlWater();
Spell makeControlWeather();
Spell makeControlWinds();
Spell makeCreateFoodAndWater();
Spell makeCreateGreaterUndead();
Spell makeCreateUndead();
Spell makeCreateWater();
Spell makeCreepingDoom();
Spell makeCrushingDespair();
Spell makeCrushingHand();
Spell makeCureCriticalWounds();
Spell makeCureCriticalWoundsMass();
Spell makeCureLightWounds();
Spell makeCureLightWoundsMass();
Spell makeCureModerateWounds();
Spell makeCureModerateWoundsMass();
Spell makeCureSeriousWounds();
Spell makeCureSeriousWoundsMass();
Spell makeCurseWater();
// D
Spell makeDancingLights();
Spell makeDarkness();
Spell makeDarkvision();
Spell makeDaylight();
Spell makeDaze();
Spell makeDazeMonster();
Spell makeDeathKnell();
Spell makeDeathWard();
Spell makeDeathwatch();
Spell makeDeepSlumber();
Spell makeDeeperDarkness();
Spell makeDelayPoison();
Spell makeDelayedBlastFireball();
Spell makeDemand();
Spell makeDesecrate();
Spell makeDestruction();
Spell makeDetectAnimalsOrPlants();
Spell makeDetectChaos();
Spell makeDetectEvil();
Spell makeDetectGood();
Spell makeDetectLaw();
Spell makeDetectMagic();
Spell makeDetectPoison();
Spell makeDetectScrying();
Spell makeDetectSecretDoors();
Spell makeDetectSnaresAndPits();
Spell makeDetectThoughts();
Spell makeDetectUndead();
Spell makeDictum();
Spell makeDimensionDoor();
Spell makeDimensionalAnchor();
Spell makeDimensionalLock();
Spell makeDiminishPlants();
Spell makeDiscernLies();
Spell makeDiscernLocation();
Spell makeDisguiseSelf();
Spell makeDisintegrate();
Spell makeDismissal();
Spell makeDispelChaos();
Spell makeDispelEvil();
Spell makeDispelGood();
Spell makeDispelLaw();
Spell makeDispelMagic();
Spell makeDispelMagicGreater();
Spell makeDisplacement();
Spell makeDisruptUndead();
Spell makeDisruptingWeapon();
Spell makeDivination();
Spell makeDivineFavor();
Spell makeDivinePower();
Spell makeDominateAnimal();
Spell makeDominateMonster();
Spell makeDominatePerson();
Spell makeDoom();
Spell makeDream();
// E
Spell makeEaglesSplendor();
Spell makeEasglesSplendorMass();
Spell makeEarthquake();
Spell makeElementalBody1();
Spell makeElementalBody2();
Spell makeElementalBody3();
Spell makeElementalBody4();
Spell makeElementalSwarm();
Spell makeEndureElements();
Spell makeEnergyDrain();
Spell makeEnervation();
Spell makeEnlargePerson();
Spell makeEnlargePersonMass();
Spell makeEntangle();
Spell makeEnthrall();
Spell makeEntropicShield();
Spell makeErase();
Spell makeEtherealJaunt();
Spell makeEtherealness();
Spell makeExpeditiousRetreat();
Spell makeExplosiveRunes();
Spell makeEyebite();
// F
Spell makeFabricate();
Spell makeFaerieFire();
Spell makeFalseLife();
Spell makeFalseVision();
Spell makeFear();
Spell makeFeatherFall();
Spell makeFeeblemind();
Spell makeFindThePath();
Spell makeFindTraps();
Spell makeFingerOfDeath();
Spell makeFireSeeds();
Spell makeFireShield();
Spell makeFireStorm();
Spell makeFireTrap();
Spell makeFireball();
Spell makeFlameArrow();
Spell makeFlameBlade();
Spell makeFlameStrike();
Spell makeFlamingSphere();
Spell makeFlare();
Spell makeFleshToStone();
Spell makeFloatingDisk();
Spell makeFly();
Spell makeFogCloud();
Spell makeForbiddance();
Spell makeForcecage();
Spell makeForcefulHand();
Spell makeForesight();
Spell makeFormOfTheDragon1();
Spell makeFormOfTheDragon2();
Spell makeFormOfTheDragon3();
Spell makeFoxsCunning();
Spell makeFoxsCunningMass();
Spell makeFreedom();
Spell makeFreedomOfMovement();
Spell makeFreezingSphere();
// G
Spell makeGaseousForm();
Spell makeGate();
Spell makeGeasQuest();
Spell makeGeasLesser();
Spell makeGentleRepose();
Spell makeGhostSound();
Spell makeGhoulTouch();
Spell makeGiantForm1();
Spell makeGiantForm2();
Spell makeGiantVermin();
Spell makeGlibness();
Spell makeGlitterdust();
Spell makeGlobeOfInvulnerability();
Spell makeGlobeOfInvulnerabilityLesser();
Spell makeGlyphOfWarding();
Spell makeGlyohOfWardingGreater();
Spell makeGoodberry();
Spell makeGoodHope();
Spell makeGraspingHand();
Spell makeGrease();
Spell makeGuardsAndWards();
Spell makeGuidance();
Spell makeGustOfWind();
// H
Spell makeHallow();
Spell makeHallucinatoryTerrain();
Spell makeHaltUndead();
Spell makeHarm();
Spell makeHaste();
Spell makeHeal();
Spell makeHealMass();
Spell makeHealMount();
Spell makeHeatMetal();
Spell makeHelpingHand();
Spell makeHeroesFeast();
Spell makeHeroism();
Spell makeHeroismGreater();
Spell makeHideFromAnimals();
Spell makeHideFromUndead();
Spell makeHideousLaughter();
Spell makeHoldAnimal();
Spell makeHoldMonster();
Spell makeHoldMonsterMass();
Spell makeHoldPerson();
Spell makeHoldPersonMass();
Spell makeHoldPortal();
Spell makeHolyAura();
Spell makeHolySmite();
Spell makeHolySword();
Spell makeHolyWord();
Spell makeHorridWilting();
Spell makeHypnoticPattern();
Spell makeHypnotism();