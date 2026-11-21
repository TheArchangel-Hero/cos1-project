#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include "AbilityScores.h"
#include "Skill.h"
#include "Spell.h"
#include "Feat.h"
#include "Race.h"
#include "CharacterClass.h"
#include "Character.h"

// Clear Input Function
void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Prompt User to Continue Function (Pause for ease of use)
void pause() {
    std::cout << "\nPress Enter to continue...";
    clearInput();
    std::cin.get();
}

// Select Race Function
Race chooseRace() {
    while (true) {
        std::cout << "\n--- Choose Race ---\n";
        std::cout << "1. Dwarf\n";
        std::cout << "2. Elf\n";
        std::cout << "3. Gnome\n";
        std::cout << "4. Half-Elf\n";
        std::cout << "5. Half-Orc\n";
        std::cout << "6. Halfling\n";
        std::cout << "7. Human\n";
        std::cout << "Enter the number corresponding to your choice: ";

        int choice;
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cout << "Please enter a number corresponding to an available option.\n";
            clearInput();
            continue;
        }
        clearInput();

        switch (choice) {
        case 1: return makeDwarf();
        case 2: return makeElf();
        case 3: return makeGnome();
        case 4: return makeHalfElf();
        case 5: return makeHalfOrc();
        case 6: return makeHalfling();
        case 7: return makeHuman();
        default:
            std::cout << "Invalid choice. Enter a number corresponding to an available option.\n";
            break;
        }
    }
}

// Human, Half-Elf, Half-Orc Ability Score Bonus Function
// Humans, Half-Elves, and Half-Orcs get to choose which Ability Score their bonus applies to.
void applyChoiceBonus(AbilityScores& scores) {
    while (true) {
        std::cout << "\nThis race gets +2 to one Ability Score of your choice.\n";
        std::cout << "1. Strength\n";
        std::cout << "2. Dexterity\n";
        std::cout << "3. Constitution\n";
        std::cout << "4. Intelligence\n";
        std::cout << "5. Wisdom\n";
        std::cout << "6. Charisma\n";
        std::cout << "Enter the number corresponding to your choice: ";

        int choice;
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cout << "Enter a number corresponding to an available option.\n";
            clearInput();
            continue;
        }
        clearInput();

        switch (choice) {
        case 1: scores.setStrength(scores.getStrength() + 2);
            return;
        case 2: scores.setDexterity(scores.getDexterity() + 2);
            return;
        case 3: scores.setConstitution(scores.getConstitution() + 2);
            return;
        case 4: scores.setIntelligence(scores.getIntelligence() + 2);
            return;
        case 5: scores.setWisdom(scores.getWisdom() + 2);
            return;
        case 6: scores.setCharisma(scores.getCharisma() + 2);
            return;
        default:
            std::cout << "Invalid choice. Enter a number corresponding to an available option.\n";
            break;
        }
    }
}

// Select Class Function
CharacterClass chooseClass() {
    while (true) {
        std::cout << "\n--- Choose Class ---\n";
        std::cout << "1. Barbarian\n";
        std::cout << "2. Bard\n";
        std::cout << "3. Cleric\n";
        std::cout << "4. Druid\n";
        std::cout << "5. Fighter\n";
        std::cout << "6. Monk\n";
        std::cout << "7. Paladin\n";
        std::cout << "8. Ranger\n";
        std::cout << "9. Rogue\n";
        std::cout << "10. Sorcerer\n";
        std::cout << "11. Wizard\n";
        std::cout << "Enter the number corresponding to your choice: ";

        int choice;
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Enter a number corresponding to an available option.\n";
            clearInput();
            continue;
        }
        clearInput();

        switch (choice) {
        case 1:  return makeBarbarian();
        case 2:  return makeBard();
        case 3:  return makeCleric();
        case 4:  return makeDruid();
        case 5:  return makeFighter();
        case 6:  return makeMonk();
        case 7:  return makePaladin();
        case 8:  return makeRanger();
        case 9:  return makeRogue();
        case 10: return makeSorcerer();
        case 11: return makeWizard();
        default:
            std::cout << "Invalid choice. Enter a number corresponding to an available option.\n";
            break;
        }
    }
}

// Select Skills Function
void chooseSkills(Character& character, const CharacterClass& selectedClass, const AbilityScores& scores) {
    int skillPoints = selectedClass.getSkillRanksPerLevel() + scores.getIntMod();
    // Skill ranks per level minimum is 1
    if (skillPoints < 1) skillPoints = 1;
    // Humans get 1 extra rank per level
    if (character.getRace().getName() == "Human") skillPoints += 1;

    std::vector<Skill::SkillOption> allSkills = {
    { "Acrobatics", Skill::KeyAbility::Dexterity, false },
    { "Appraise", Skill::KeyAbility::Intelligence, false },
    { "Bluff", Skill::KeyAbility::Charisma, false },
    { "Climb", Skill::KeyAbility::Strength, false },
    { "Craft", Skill::KeyAbility::Intelligence, false },
    { "Diplomacy", Skill::KeyAbility::Charisma, false },
    { "Disable Device", Skill::KeyAbility::Dexterity, true },
    { "Disguise", Skill::KeyAbility::Charisma, false },
    { "Escape Artist", Skill::KeyAbility::Dexterity, false },
    { "Fly", Skill::KeyAbility::Dexterity, false },
    { "Handle Animal", Skill::KeyAbility::Charisma, true },
    { "Heal", Skill::KeyAbility::Wisdom, false },
    { "Intimidate", Skill::KeyAbility::Charisma, false },
    { "Knowledge (arcana)", Skill::KeyAbility::Intelligence, true },
    { "Knowledge (dungeoneering)", Skill::KeyAbility::Intelligence, true },
    { "Knowledge (engineering)", Skill::KeyAbility::Intelligence, true },
    { "Knowledge (geography)", Skill::KeyAbility::Intelligence, true },
    { "Knowledge (history)", Skill::KeyAbility::Intelligence, true },
    { "Knowledge (local)", Skill::KeyAbility::Intelligence, true },
    { "Knowledge (nature)", Skill::KeyAbility::Intelligence, true },
    { "Knowledge (nobility)", Skill::KeyAbility::Intelligence, true },
    { "Knowledge (planes)", Skill::KeyAbility::Intelligence, true },
    { "Knowledge (religion)", Skill::KeyAbility::Intelligence, true },
    { "Linguistics", Skill::KeyAbility::Intelligence, true },
    { "Perception", Skill::KeyAbility::Wisdom, false },
    { "Perform", Skill::KeyAbility::Charisma, false },
    { "Profession", Skill::KeyAbility::Wisdom, true },
    { "Ride", Skill::KeyAbility::Dexterity, false },
    { "Sense Motive", Skill::KeyAbility::Wisdom, false },
    { "Sleight of Hand", Skill::KeyAbility::Dexterity, true },
    { "Spellcraft", Skill::KeyAbility::Intelligence, true },
    { "Stealth", Skill::KeyAbility::Dexterity, false },
    { "Survival", Skill::KeyAbility::Wisdom, false },
    { "Swim", Skill::KeyAbility::Strength, false },
    { "Use Magic Device", Skill::KeyAbility::Charisma, true }
    };

    std::cout << "\n--- Assign Skill Ranks ---\n";
    std::cout << "You have " << skillPoints << " skill ranks to spend (max 1 rank per skill per level).\n";

    while (skillPoints > 0) {
        std::cout << "\nSkill points remaining: " << skillPoints << "\n";
        for (size_t i = 0; i < allSkills.size(); ++i) {
            std::cout << (i + 1) << ". " << allSkills[i].name << "\n";
        }
        std::cout << "0. Finished\n";
        std::cout << "Choice: ";

        int choice;
        std::cin >> choice;
        clearInput();

        if (choice == 0) break;
        if (choice < 1 || choice > static_cast<int>(allSkills.size())) {
            std::cout << "Invalid choice.\n";
            continue;
        }

        const auto& option = allSkills[choice - 1];

        bool alreadySelected = false;
        for (const auto& existing : character.getSkills()) {
            if (existing.getName() == option.name) {
                alreadySelected = true;
                break;
            }
        }
        if (alreadySelected) {
            std::cout << "You have the maximum ranks in " << option.name << ". Choose a different skill.\n";
            continue;
        }

        Skill skill;
        skill.setName(option.name);
        skill.setKeyAbility(option.ability);
        skill.setTrainedOnly(option.trainedOnly);

        // Check to see if the Skill is a Class Skill
        const auto& classSkills = selectedClass.getClassSkills();
        for (const auto& cs : classSkills) {
            if (cs == option.name || (cs == "Knowledge (all)" && option.name.find("Knowledge") == 0)) {
                skill.setClassSkill(true);
                break;
            }
        }

        skill.setRanks(1, 1);
        character.addSkill(skill);
        skillPoints--;
        std::cout << option.name << " rank added.\n";
    }
}

// Select Feats Function
// Note: Only Feats beginning with "A" are implemented so far
void chooseFeats(Character& character) {
    // Characters gain a new Feat every odd level
    int featChoiceCount = 1;
    // Humans get a bonus Feat at 1st level
    if (character.getRace().getName() == "Human") featChoiceCount++;
    // Fighters get a bonus combat Feat at 1st level and every even level
    if (character.getClass().getName() == "Fighter") featChoiceCount++;

    std::cout << "\n--- Choose Feats ---\n";
    std::cout << "You may select " << featChoiceCount << " feat(s).\n";

    for (int i = 0; i < featChoiceCount; ++i) {
        while (true) {
            std::cout << "\nFeat " << (i + 1) << " of " << featChoiceCount << ":\n";
            std::cout << "1. Acrobatic\n";
            std::cout << "2. Acrobatic Steps\n";
            std::cout << "3. Agile Maneuvers\n";
            std::cout << "4. Alertness\n";
            std::cout << "5. Alignment Channel\n";
            std::cout << "6. Animal Affinity\n";
            std::cout << "7. Arcane Armor Mastery\n";
            std::cout << "8. Arcane Armor Training\n";
            std::cout << "9. Arcane Strike\n";
            std::cout << "10. Armor Proficiency (Heavy)\n";
            std::cout << "11. Armor Proficiency (Light)\n";
            std::cout << "12. Armor Proficiency (Medium)\n";
            std::cout << "13. Athletic\n";
            std::cout << "14. Augment Summoning\n";
            std::cout << "0. Skip\n";
            std::cout << "Choice: ";

            int choice;
            std::cin >> choice;
            clearInput();

            if (choice == 0) break;

            Feat newFeat;
            bool validChoice = true;
            switch (choice) {
            case 1:
                newFeat = makeAcrobatic();
                break;
            case 2:
                newFeat = makeAcrobaticSteps();
                break;
            case 3:
                newFeat = makeAgileManeuvers();
                break;
            case 4:
                newFeat = makeAlertness();
                break;
            case 5:
                newFeat = makeAlignmentChannel();
                break;
            case 6:
                newFeat = makeAnimalAffinity();
                break;
            case 7:
                newFeat = makeArcaneArmorMastery();
                break;
            case 8:
                newFeat = makeArcaneArmorTraining();
                break;
            case 9:
                newFeat = makeArcaneStrike();
                break;
            case 10:
                newFeat = makeArmorProficiencyHeavy();
                break;
            case 11:
                newFeat = makeArmorProficiencyLight();
                break;
            case 12:
                newFeat = makeArmorProficiencyMedium();
               break;
            case 13:
                newFeat = makeAthletic();
                break;
            case 14:
                newFeat = makeAugmentSummoning();
                break;
            default:
                std::cout << "Invalid choice.\n";
                validChoice = false;
                break;
            }
            if (!validChoice) continue;

            bool alreadySelected = false;
            for (const auto& existing : character.getFeats()) {
                if (existing.getName() == newFeat.getName()) {
                    alreadySelected = true;
                    break;
                }
            }
            if (alreadySelected) {
                std::cout << "You have the " << newFeat.getName() << " feat. Choose a different feat.\n";
                continue;
            }

            character.addFeat(newFeat);
            std::cout << newFeat.getName() << " added.\n";
            break;
        }
    }
}

// Select Spells Function
// Note: Only Spells beginning with "A" are implemented so far
void chooseSpells(Character& character, const CharacterClass& selectedClass) {
    std::string className = selectedClass.getName();
    bool isCaster = (className == "Bard" || className == "Cleric" || className == "Druid" || className == "Paladin" || className == "Ranger" || className == "Sorcerer" || className == "Wizard");
    if (!isCaster) return;

    std::cout << "\n--- Choose Spells ---\n";
    std::cout << "Add all spells you wish to have known. Select option 0 when finished.\n";

    while (true) {
        std::cout << "\n0 level Spells:\n";
        std::cout << " 1. Acid Splash          2. Arcane Mark           3. Bleed\n";
        std::cout << " 4. Create Water         5. Dancing Lights        6. Daze\n";
        std::cout << " 7. Detect Magic         8. Detect Poison         9. Disrupt Undead\n";
        std::cout << "10. Flare               11. Ghost Sound          12. Guidance\n";
        std::cout << "13. Know Direction      14. Light                15. Lullaby\n";
        std::cout << "16. Mage Hand           17. Mending              18. Message\n";
        std::cout << "19. Open/Close          20. Prestidigitation     21. Purify Food and Drink\n";
        std::cout << "22. Ray of Frost        23. Read Magic           24. Resistance\n";
        std::cout << "25. Stabilize           26. Summon Instrument    27. Touch of Fatigue\n";
        std::cout << "28. Virtue\n";

        std::cout << "\n1st-level Spells:\n";
        std::cout << "29. Alarm               30. Animate Rope         31. Bane\n";
        std::cout << "32. Bless               33. Bless Water          34. Bless Weapon\n";
        std::cout << "35. Burning Hands       36. Calm Animals         37. Cause Fear\n";
        std::cout << "38. Charm Animal        39. Charm Person         40. Chill Touch\n";
        std::cout << "41. Color Spray         42. Command              43. Comprehend Languages\n";
        std::cout << "44. Cure Light Wounds   45. Curse Water          46. Deathwatch\n";
        std::cout << "47. Delay Poison        48. Detect Animals or Plants  49. Detect Secret Doors\n";
        std::cout << "50. Detect Snares and Pits  51. Detect Undead    52. Disguise Self\n";
        std::cout << "53. Divine Favor        54. Doom                 55. Endure Elements\n";
        std::cout << "56. Enlarge Person      57. Entangle             58. Entropic Shield\n";
        std::cout << "59. Expeditious Retreat 60. Faerie Fire          61. Feather Fall\n";
        std::cout << "62. Floating Disk       63. Goodberry            64. Grease\n";
        std::cout << "65. Hide from Animals   66. Hide from Undead     67. Hideous Laughter\n";
        std::cout << "68. Hold Portal         69. Hypnotism            70. Identify\n";
        std::cout << "71. Inflict Light Wounds 72. Jump                73. Longstrider\n";
        std::cout << "74. Mage Armor          75. Magic Aura           76. Magic Fang\n";
        std::cout << "77. Magic Missile       78. Magic Mouth          79. Magic Stone\n";
        std::cout << "80. Magic Weapon        81. Mount                82. Obscure Object\n";
        std::cout << "83. Obscuring Mist      84. Pass without Trace   85. Produce Flame\n";
        std::cout << "86. Protection from Chaos  87. Protection from Evil  88. Protection from Good\n";
        std::cout << "89. Protection from Law 90. Ray of Enfeeblement  91. Reduce Person\n";
        std::cout << "92. Remove Fear         93. Sanctuary            94. Shield\n";
        std::cout << "95. Shield of Faith     96. Shillelagh           97. Shocking Grasp\n";
        std::cout << "98. Silent Image        99. Sleep               100. Speak with Animals\n";
        std::cout << "101. Summon Monster I   102. Summon Nature's Ally I  103. True Strike\n";
        std::cout << "104. Undetectable Alignment  105. Unseen Servant  106. Ventriloquism\n";
        std::cout << "0. Done\n";
        std::cout << "Choice: ";

        int choice;
        std::cin >> choice;
        clearInput();

        if (choice == 0) break;

        Spell newSpell;
        bool validChoice = true;
        switch (choice) {
        case 1:  newSpell = makeAcidSplash(); break;
        case 2:  newSpell = makeArcaneMark(); break;
        case 3:  newSpell = makeBleed(); break;
        case 4:  newSpell = makeCreateWater(); break;
        case 5:  newSpell = makeDancingLights(); break;
        case 6:  newSpell = makeDaze(); break;
        case 7:  newSpell = makeDetectMagic(); break;
        case 8:  newSpell = makeDetectPoison(); break;
        case 9:  newSpell = makeDisruptUndead(); break;
        case 10: newSpell = makeFlare(); break;
        case 11: newSpell = makeGhostSound(); break;
        case 12: newSpell = makeGuidance(); break;
        case 13: newSpell = makeKnowDirection(); break;
        case 14: newSpell = makeLight(); break;
        case 15: newSpell = makeLullaby(); break;
        case 16: newSpell = makeMageHand(); break;
        case 17: newSpell = makeMending(); break;
        case 18: newSpell = makeMessage(); break;
        case 19: newSpell = makeOpenClose(); break;
        case 20: newSpell = makePrestidigitation(); break;
        case 21: newSpell = makePurifyFoodAndDrink(); break;
        case 22: newSpell = makeRayOfFrost(); break;
        case 23: newSpell = makeReadMagic(); break;
        case 24: newSpell = makeResistance(); break;
        case 25: newSpell = makeStabilize(); break;
        case 26: newSpell = makeSummonInstrument(); break;
        case 27: newSpell = makeTouchOfFatigue(); break;
        case 28: newSpell = makeVirtue(); break;
        case 29: newSpell = makeAlarm(); break;
        case 30: newSpell = makeAnimateRope(); break;
        case 31: newSpell = makeBane(); break;
        case 32: newSpell = makeBless(); break;
        case 33: newSpell = makeBlessWater(); break;
        case 34: newSpell = makeBlessWeapon(); break;
        case 35: newSpell = makeBurningHands(); break;
        case 36: newSpell = makeCalmAnimals(); break;
        case 37: newSpell = makeCauseFear(); break;
        case 38: newSpell = makeCharmAnimal(); break;
        case 39: newSpell = makeCharmPerson(); break;
        case 40: newSpell = makeChillTouch(); break;
        case 41: newSpell = makeColorSpray(); break;
        case 42: newSpell = makeCommand(); break;
        case 43: newSpell = makeComprehendLanguages(); break;
        case 44: newSpell = makeCureLightWounds(); break;
        case 45: newSpell = makeCurseWater(); break;
        case 46: newSpell = makeDeathwatch(); break;
        case 47: newSpell = makeDelayPoison(); break;
        case 48: newSpell = makeDetectAnimalsOrPlants(); break;
        case 49: newSpell = makeDetectSecretDoors(); break;
        case 50: newSpell = makeDetectSnaresAndPits(); break;
        case 51: newSpell = makeDetectUndead(); break;
        case 52: newSpell = makeDisguiseSelf(); break;
        case 53: newSpell = makeDivineFavor(); break;
        case 54: newSpell = makeDoom(); break;
        case 55: newSpell = makeEndureElements(); break;
        case 56: newSpell = makeEnlargePerson(); break;
        case 57: newSpell = makeEntangle(); break;
        case 58: newSpell = makeEntropicShield(); break;
        case 59: newSpell = makeExpeditiousRetreat(); break;
        case 60: newSpell = makeFaerieFire(); break;
        case 61: newSpell = makeFeatherFall(); break;
        case 62: newSpell = makeFloatingDisk(); break;
        case 63: newSpell = makeGoodberry(); break;
        case 64: newSpell = makeGrease(); break;
        case 65: newSpell = makeHideFromAnimals(); break;
        case 66: newSpell = makeHideFromUndead(); break;
        case 67: newSpell = makeHideousLaughter(); break;
        case 68: newSpell = makeHoldPortal(); break;
        case 69: newSpell = makeHypnotism(); break;
        case 70: newSpell = makeIdentify(); break;
        case 71: newSpell = makeInflictLightWounds(); break;
        case 72: newSpell = makeJump(); break;
        case 73: newSpell = makeLongstrider(); break;
        case 74: newSpell = makeMageArmor(); break;
        case 75: newSpell = makeMagicAura(); break;
        case 76: newSpell = makeMagicFang(); break;
        case 77: newSpell = makeMagicMissile(); break;
        case 78: newSpell = makeMagicMouth(); break;
        case 79: newSpell = makeMagicStone(); break;
        case 80: newSpell = makeMagicWeapon(); break;
        case 81: newSpell = makeMount(); break;
        case 82: newSpell = makeObscureObject(); break;
        case 83: newSpell = makeObscuringMist(); break;
        case 84: newSpell = makePassWithoutTrace(); break;
        case 85: newSpell = makeProduceFlame(); break;
        case 86: newSpell = makeProtectionFromChaos(); break;
        case 87: newSpell = makeProtectionFromEvil(); break;
        case 88: newSpell = makeProtectionFromGood(); break;
        case 89: newSpell = makeProtectionFromLaw(); break;
        case 90: newSpell = makeRayOfEnfeeblement(); break;
        case 91: newSpell = makeReducePerson(); break;
        case 92: newSpell = makeRemoveFear(); break;
        case 93: newSpell = makeSanctuary(); break;
        case 94: newSpell = makeShield(); break;
        case 95: newSpell = makeShieldOfFaith(); break;
        case 96: newSpell = makeShillelagh(); break;
        case 97: newSpell = makeShockingGrasp(); break;
        case 98: newSpell = makeSilentImage(); break;
        case 99: newSpell = makeSleep(); break;
        case 100: newSpell = makeSpeakWithAnimals(); break;
        case 101: newSpell = makeSummonMonsterI(); break;
        case 102: newSpell = makeSummonNaturesAllyI(); break;
        case 103: newSpell = makeTrueStrike(); break;
        case 104: newSpell = makeUndetectableAlignment(); break;
        case 105: newSpell = makeUnseenServant(); break;
        case 106: newSpell = makeVentriloquism(); break;
        default:
            std::cout << "Invalid choice.\n";
            validChoice = false;
            break;
        }
        if (!validChoice) continue;

        bool alreadySelected = false;
        for (const auto& existing : character.getSpells()) {
            if (existing.getName() == newSpell.getName()) {
                alreadySelected = true;
                break;
            }
        }
        if (alreadySelected) {
            std::cout << "You already know " << newSpell.getName() << ". Choose a different spell.\n";
            continue;
        }

        character.addSpell(newSpell);
        std::cout << newSpell.getName() << " added.\n";
    }
}

// Declaration for currentCharacter, in order to save information in memory
Character currentCharacter;

// Assign Ability Scores
// For now, Ability Scores are assigned as the user chooses
// TO DO: Add a dice roller for Standard Ability Score assignment ruleset
AbilityScores chooseAbilityScores() {
    AbilityScores scores;
    std::cout << "\n--- Assign Ability Scores ---\n";
    std::cout << "Ability Scores are typically between 7 and 18 for a starting character.\n";
    std::cout << "Assign a value of your choice for each Ability Score.\n";

    int value;
    std::cout << "Strength: ";
    std::cin >> value;
    scores.setStrength(value);
    std::cout << "Dexterity: ";
    std::cin >> value;
    scores.setDexterity(value);
    std::cout << "Constitution: ";
    std::cin >> value;
    scores.setConstitution(value);
    std::cout << "Intelligence: ";
    std::cin >> value;
    scores.setIntelligence(value);
    std::cout << "Wisdom: ";
    std::cin >> value;
    scores.setWisdom(value);
    std::cout << "Charisma: ";
    std::cin >> value;
    scores.setCharisma(value);
    clearInput();

    return scores;
}

// Main Menu Function
void showMainMenu() {
    std::cout << "\n==============================\n";
    std::cout << "  Pathfinder 1e Character Builder\n";
    std::cout << "==============================\n";
    std::cout << "1. Create New Character\n";
    std::cout << "2. View Current Character\n";
    std::cout << "3. Load Character (placeholder)\n";
    std::cout << "4. Exit\n";
    std::cout << "Choice: ";
}

// Create Character Menu Option Function
void createCharacter() {
    std::cout << "\n--- Create New Character ---\n";

    // Name
    std::string name;
    std::cout << "Enter a name for the character: ";
    std::getline(std::cin, name);
    if (name.empty()) {
        clearInput();
        std::getline(std::cin, name);
    }

    // Race
    Race race = chooseRace();
    std::cout << "\nSelected Race:\n";
    race.print();

    // Base Ability Scores
    AbilityScores scores = chooseAbilityScores();
    std::cout << "\nBase Ability Scores:\n";
    scores.print();

    // Racial Ability Score Adjustment
    std::string raceName = race.getName();
    if (raceName == "Human" || raceName == "Half-Elf" || raceName == "Half-Orc") {
        applyChoiceBonus(scores);
    }
    else {
        race.applyAbilityBonuses(scores);
    }
    std::cout << "\nAbility Scores after Racial Adjustment:\n";
    scores.print();

    // Class
    CharacterClass characterClass = chooseClass();
    std::cout << "\nSelected Class:\n";
    characterClass.print();

    // Save to currentCharacter
    currentCharacter.setName(name);
    currentCharacter.setRace(race);
    currentCharacter.setScores(scores);
    currentCharacter.setClass(characterClass);

    // Skill, Feat, and Spell Selection
    chooseSkills(currentCharacter, characterClass, scores);
    chooseFeats(currentCharacter);
    chooseSpells(currentCharacter, characterClass);

    // Mark created
    currentCharacter.markCreated();

    // Creation Summary
    std::cout << "\n========== Character Summary ==========\n";
    currentCharacter.print();

    pause();
}

// View Character Menu Option Function
void viewCharacter() {
    std::cout << "\n--- View Current Character ---\n";
    currentCharacter.print();
    pause();
}

// Load Character Menu Option Function
void loadCharacter() {
    std::cout << "\n--- Load Character ---\n";
    std::cout << "(Placeholder - not implemented yet)\n";
    std::cout << "\nPress Enter to return to main menu...";
    clearInput();
    std::cin.get();
}

int main()
{
    bool running = true;

    while (running) {
        showMainMenu();

        int choice;
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number corresponding to options 1-4.\n";
            clearInput();
            continue;
        }
        clearInput();

        switch (choice) {
        case 1:
            createCharacter();
            break;
        case 2:
            viewCharacter();
            break;
        case 3:
            loadCharacter();
            break;
        case 4:
            std::cout << "\nExiting\n";
            running = false;
            break;
        default:
            std::cout << "Invalid input. Please enter a number corresponding to options 1-4.\n";
            break;
        }
    }

    return 0;
}
