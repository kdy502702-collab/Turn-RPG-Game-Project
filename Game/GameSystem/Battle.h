#pragma once
#include "Action.h"
#include "Player.h"
#include "Enemy.h"

class Battle{
    private:
        std::vector<Unit*> units; //전투에 등장하는 모든 유닛 관리
        void AddUnit(Unit* unit); //유닛 추가
        void DelUnit(Unit* unit); //유닛 삭제
        void FlowCount(const std::vector<Unit*> units); //각 유닛의 moveCount관리
        bool CheckEnd(); //게임 승패 조건이 참인지 검사
        bool CloseBattle(); //게임 종료
    public:
        Battle();
        Battle(const std::vector<Unit*> units):units(units){};
        void OpenBattle(); //게임 시작 이후 실행되는 로직 관리 <Battle의 몸체>
};