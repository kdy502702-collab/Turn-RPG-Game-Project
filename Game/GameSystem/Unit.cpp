#include "Unit.h"

int Unit::TakeDamage(int damage)
{
    int takenDamage = this->status.GetCurHp()- (this->status.GetCurDef()-damage);
    if(this->GetIsDefense()==true){
        takenDamage = takenDamage/2;
    }
    this->status.SetCurHp(takenDamage);
    return takenDamage;
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