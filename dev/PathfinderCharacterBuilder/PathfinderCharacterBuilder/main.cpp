#include <iostream>
#include "AbilityScores.h"
#include "Skill.h"
#include "Race.h"

int main()
{
    // Test for AbilityScores:
    //AbilityScores scores;
    //scores.dexterity = 16;
    //scores.print();
    //return 0;

    // Test for Skill:
    //Skill acrobatics;
    //acrobatics.name = "Acrobatics";
    //acrobatics.keyAbility = Skill::KeyAbility::Dexterity;
    //acrobatics.ranks = 0;
    //acrobatics.isClassSkill = true;
    //acrobatics.trainedOnly = true;
    //acrobatics.print(scores);
    //return 0;

    // Test for Race:
    AbilityScores scores;
    scores.strength = 14;
    scores.dexterity = 12;
    scores.constitution = 10;
    scores.intelligence = 18;
    scores.wisdom = 8;
    scores.charisma = 16;
    Race elf = makeElf();
    elf.applyAbilityBonuses(scores);
    elf.print();
    scores.print();
    return 0;
}
