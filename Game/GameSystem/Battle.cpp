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
            if(inputActionCode==1){
                while(true){
                for(Unit* unit:units){
                    if(typeid(unit)==typeid(Player)){
                        continue;
                    }
                    std::cout<<"타겟 : "<<unit->GetName()<<" HP : "<<unit->GetCurHp()<<"\n <y/n> : ";
                    char inputTarget;
                    while(true){
                        if(std::cin>>inputTarget){
                            if(inputTarget=='n'){
                                continue;
                            }
                            targets.push_back(unit);
                            actionInfo.targets.push_back(unit);
                            break;
                        }
                    }
                    if(actionInfo.targets.size()>=2){
                        break;
                    }
                    }
                }
                ActionResult actionResult=Action::ExcuteAction(actionInfo);
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
bool Battle::CheckEnd(){
    for(Unit* unit : this->units){
        if(typeid(unit)==typeid(Player)){
            if(unit->GetIsDead()==true){
            return true;
            }
        }else{
            if(unit->GetIsDead()==false){
            return false;
            }
        }
        return true;
    }
} //게임 승패 조건이 참인지 검사
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
} //게임 종료
Battle::Battle()=default;
void Battle::OpenBattle(){
    while(this->CheckEnd()){
        this->FlowCount(this->units);
    }
    this->CloseBattle();
}; //게임 시작 이후 실행되는 로직 관리 <Battle의 몸체>