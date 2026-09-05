#pragma once
#include "Status.h"
#include <string>
#include <vector>
/*
Unit : 전투에 등장하는 모든 유닛 관리
맴버 변수 : name(Unit 이름), Status(유닛의 능력치 관리), SkillList(유닛이 사용할 수 있는 스킬 관리/나중에 추가),//Buff/Debuff(버프,디버프 관리/나중에 추가), isDead(유닛의 생존 여부 관리), isDefense(방어 상태 관리), Inventory(인벤토리 관리/나중에 추가), Equipment(장비 관리/나중에 추가)
주요 함수 : abstact SelectAction(유닛의 행동을 결정, 자식 클래스에서 각각 구현) TakeDamage(데미지 받음 구현), TakeHealing(치료 받음 구현)
*/
class Unit;

//SelectAction이 넘겨주는 행동 유형 및 타겟
struct ActionInfo{
    int actionCode;
    std::vector<Unit*> targets;
};

class Unit
{
    private:
        std::string name;
        Status status;
        bool isDead;
        bool isDefense;
    
    public:
        Unit():name("unknown"),status(),isDead(false),isDefense(false){}
        Unit(std::string name, Status status,bool isDead, bool isDefense ):name(name), status(status), isDead(isDead), isDefense(isDefense){}
        void SetName(std::string name){this->name = name;}
        void SetStatus(Status status){this->status = status;}
        void SetStatus(int curHp,int maxHp, int curMp, int maxMp, int curAtk, int baseAtk, int curDef, int baseDef,int curSpeed,int baseSpeed)
        {this->status = Status(curHp,maxHp, curMp, maxMp, curAtk, baseAtk, curDef, baseDef,curSpeed,baseSpeed);}
        void SetIsDead(bool isDead){this->isDead=isDead;}
        std::string GetName()const{return this->name;}
        bool GetIsDead()const{return this->isDead;}
        bool GetIsDefense()const{return this->isDefense;}
        int GetAttack(){return this->status.GetCurAtk();}
        int TakeDamage(int damage);
        int TakeHealing(int healing);
        virtual ActionInfo SelectAction()=0;
};