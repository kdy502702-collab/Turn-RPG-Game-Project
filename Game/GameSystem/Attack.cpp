#include "Attack.h"
#include <random>

void Attack::ExcuteAttack(std::vector<Unit*> units)
{
    Unit* executor = units.at(0);
    int damage;
    for(int i = 1;i<units.size();i++){
        Unit* target = units.at(i);
        damage = (executor->GetAttack()*((rand()%21+80)/100));
        target->TakeDamage(damage);
    }
}

