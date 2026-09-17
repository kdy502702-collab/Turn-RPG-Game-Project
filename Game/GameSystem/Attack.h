#pragma once
#include "Unit.h"
#include <vector>

class Attack
{
    public:
        static std::vector<DamageResult> ExcuteAttack(std::vector<Unit*> units);
};