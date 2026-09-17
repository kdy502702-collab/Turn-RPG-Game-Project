#pragma once
#include "Attack.h"



class Action
{
    public:
        static ActionResult ExcuteAction(ActionInfo actionInfo);
        static std::vector<DamageResult> ExecuteAttack(const std::vector<Unit*> units);
        static void ExecuteDefense(Unit* unit);
};