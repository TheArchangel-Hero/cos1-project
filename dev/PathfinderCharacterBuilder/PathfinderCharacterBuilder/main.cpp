#include <iostream>
#include "AbilityScores.h"
#include "Skill.h"

int main()
{
    // Test for AbilityScores:
    AbilityScores scores;
    scores.dexterity = 16;
    scores.print();

    // Test for Skill:
    Skill acrobatics;
    acrobatics.name = "Acrobatics";
    acrobatics.keyAbility = Skill::KeyAbility::Dexterity;
    acrobatics.ranks = 0;
    acrobatics.isClassSkill = true;
    acrobatics.trainedOnly = true;
    acrobatics.print(scores);
    return 0;
}
