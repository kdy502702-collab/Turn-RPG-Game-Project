#include "Unit.h"

int Unit::TakeDamage(int damage) {
    // 1. 방어력을 차감한 실제 피해량 계산
    int actualDamage = damage - this->status.GetCurDef();

    // 2. 유닛이 방어 자세(Defense) 상태라면 피해량 반감
    if (this->GetIsDefense()) {
        actualDamage /= 2;
    }

    // 3. 방어력이 너무 높아 피해량이 0 이하가 되는 것 방지 (최소 1 데미지)
    if (actualDamage < 1) {
        actualDamage = 1;
    }

    // 4. 현재 체력에서 실제 피해량만큼 차감
    int nextHp = this->status.GetCurHp() - actualDamage;
    if (nextHp < 0) nextHp = 0; // 체력이 음수로 내려가지 않도록 방지
    
    this->status.SetCurHp(nextHp);

    // 5. 입힌 피해량을 반환 (DamageResult 등에 출력용으로 사용)
    return actualDamage;
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