#include "Action.h"



ActionResult Action::ExcuteAction(ActionInfo actionInfo)
{
    ActionResult actionResult;
    actionResult.actionCode = actionInfo.actionCode;
    actionResult.executor = actionInfo.targets.at(0);

    if(actionInfo.actionCode==1){
        actionResult.resultDamaged=Action::ExecuteAttack(actionInfo.targets); 
        return actionResult;
    }else if(actionInfo.actionCode==2){
        Action::ExecuteDefense(actionInfo.targets.at(0));
        return actionResult;
    }else{
        return actionResult;
    }
}

std::vector<DamageResult> Action::ExecuteAttack(const std::vector<Unit*> units)
{
    units.at(0)->SetIsDefense(false);
    std::vector<DamageResult> damageResult = Attack::ExcuteAttack(units);
    return damageResult;
}

void Action::ExecuteDefense(Unit* unit)
{
    unit->SetIsDefense(true);
}