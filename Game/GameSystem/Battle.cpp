#include "Battle.h"
#include <algorithm>
#include <typeinfo>
#include <iostream>

void Battle::AddUnit(Unit* unit){
    this->units.push_back(unit);
} //유닛 추가
void Battle::DelUnit(Unit* unit){
    units.erase(std::remove(this->units.begin(), this->units.end(), unit),units.end());
} //유닛 삭제
void Battle::FlowCount(const std::vector<Unit*> units){
    for(Unit* unit:units){
        if(!unit->DownMoveCount(1)){
            continue;
        }
        if(Enemy* enemy = dynamic_cast<Enemy*>(unit)){
            ActionResult actionResult=Action::ExcuteAction(enemy->SelectAction(units));
            if(actionResult.actionCode==2){
                std::cout<<actionResult.executor->GetName()<<"은(는) 방어에 들어갔다!"<<std::endl;
            }else if(actionResult.actionCode==1){
                std::cout<<actionResult.executor->GetName()<<"의 공격!!"<<std::endl;
                for(DamageResult damaged:actionResult.resultDamaged){
                    std::cout<<damaged.target->GetName()<<"은(는) "<<damaged.damage<<"의 데미지를 입었다!\nCur Hp : "<<damaged.target->GetCurHp()<<std::endl;
                    if(damaged.target->GetCurHp()<=0){
                        damaged.target->SetIsDead(true);
                        std::cout<<damaged.target->GetName()<<"은(는) 쓰러졌다!!"<<std::endl;
                    }
                }
            }
            continue;
        }
        if(Player* player = dynamic_cast<Player*>(unit)){
            std::cout<<"1. Attack\n2. Defense\n>>";
            int inputActionCode;
            ActionInfo actionInfo;
            std::vector<Unit*> targets;
            targets.push_back(unit);
            actionInfo.targets = targets;
            while(true){
                if(std::cin>>inputActionCode){
                    if(inputActionCode==1||inputActionCode==2){
                        actionInfo.actionCode = inputActionCode;
                        break;
                    }
                }
            }
            if (inputActionCode == 1) {
                bool targetSelected = false;

                // 플레이어가 아닌 적 유닛 순회
                for (Unit* targetCandidate : units) {
                    if (dynamic_cast<Player*>(targetCandidate) != nullptr) continue; // 플레이어 자신 제외
                    if (targetCandidate->GetIsDead()) continue; // 이미 죽은 적 제외
                
                    std::cout << "타겟 : " << targetCandidate->GetName() 
                              << " (HP: " << targetCandidate->GetCurHp() << ")\n공격하시겠습니까? <y/n> : ";

                    char inputTarget;
                    std::cin >> inputTarget;
                
                    if (inputTarget == 'y' || inputTarget == 'Y') {
                        actionInfo.targets.push_back(targetCandidate);
                        targetSelected = true;
                        break; // 타깃을 선택했으므로 for문 탈출
                    }
                }
            
                // 타깃을 선택하지 못했거나 모두 n을 눌렀다면 기본적으로 첫 번째 적 선택
                if (!targetSelected) {
                    for (Unit* targetCandidate : units) {
                        if (dynamic_cast<Player*>(targetCandidate) == nullptr && !targetCandidate->GetIsDead()) {
                            actionInfo.targets.push_back(targetCandidate);
                            break;
                        }
                    }
                }
            
                // 공격 실행
                ActionResult actionResult = Action::ExcuteAction(actionInfo);
                std::cout<<actionResult.executor->GetName()<<"의 공격!!"<<std::endl;
                for(DamageResult damaged:actionResult.resultDamaged){
                    std::cout<<damaged.target->GetName()<<"은(는) "<<damaged.damage<<"의 데미지를 입었다!\nCur Hp : "<<damaged.target->GetCurHp()<<std::endl;
                    if(damaged.target->GetCurHp()<=0){
                        damaged.target->SetIsDead(true);
                        std::cout<<damaged.target->GetName()<<"은(는) 쓰러졌다!!"<<std::endl;
                    }
                }
                continue;
            }
            if(inputActionCode==2){
                ActionResult actionResult=Action::ExcuteAction(actionInfo);
                std::cout<<actionResult.executor->GetName()<<"은(는) 방어에 들어갔다!"<<std::endl;
            }
        }
    }
} //각 유닛의 moveCount관리
bool Battle::CheckEnd() {
    bool isPlayerAlive = false;
    bool isEnemyAlive = false;

    for (Unit* unit : this->units) {
        if (!unit->GetIsDead()) { // 살아있는 유닛 확인
            if (dynamic_cast<Player*>(unit) != nullptr) {
                isPlayerAlive = true;
            } else if (dynamic_cast<Enemy*>(unit) != nullptr) {
                isEnemyAlive = true;
            }
        }
    }

    // 플레이어가 죽었거나, 적이 전멸했으면 전투 종료(true)
    if (!isPlayerAlive || !isEnemyAlive) {
        return true; 
    }

    return false; // 전투 계속 진행
}
void Battle::OpenBattle() {
    // 전투가 종료되지 않은 동안(!CheckEnd) 계속 턴을 돌린다.
    while (!this->CheckEnd()) {
        this->FlowCount(this->units);
    }
    this->CloseBattle();
}
Battle::Battle()=default;
bool Battle::CloseBattle(){
    for(Unit* unit:this->units){
        if(typeid(unit)==typeid(Player)){
            if(unit->GetIsDead()==true){
                std::cout<<unit->GetName()<<"은(는) 패배했다..."<<std::endl;
                return false;
            }else{
                std::cout<<unit->GetName()<<"은(는) 승리했다!!!"<<std::endl;
                return true;
            }
        }
    }
    return true;
} //게임 종료