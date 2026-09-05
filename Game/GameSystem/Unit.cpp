#include "Unit.h"

int Unit::TakeDamage(int damage)
{
    int takenDamege = this->status.GetCurHp()- (this->status.GetCurDef()-damage);
    this->status.SetCurHp(takenDamege);
    return takenDamege;
}


int Unit::TakeHealing(int healing)
{
    int takenHealing;
    if(this->status.GetMaxHp()<(this->status.GetCurHp()+healing))
    {
        takenHealing = this->status.GetMaxHp()-this->status.GetCurHp();
    }else{
        takenHealing = healing;
    }
    this->status.SetCurHp(this->status.GetCurHp()+takenHealing);
    return takenHealing;
}