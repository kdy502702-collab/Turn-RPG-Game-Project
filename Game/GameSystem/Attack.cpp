#include "Attack.h"
#include <random>

std::vector<DamageResult> Attack::ExcuteAttack(const std::vector<Unit*> units)
{
    Unit* executor = units.at(0);
    int damage;
    std::vector<DamageResult> damageResults;
    std::vector<int> takenDamages;
    DamageResult damageResult;
    for(int i = 1;i<units.size();i++){
        Unit* target = units.at(i);
        damage = (executor->GetAttack()*(rand()%21+80)/100);
        damageResult.target = target;
        damageResult.damage = target->TakeDamage(damage);
        damageResults.push_back(damageResult);
    }
    return damageResults;
}

