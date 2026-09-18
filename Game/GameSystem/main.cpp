#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "Status.h"
#include "Unit.h"
#include "Player.h"
#include "Enemy.h"
#include "Battle.h"

int main() {
    // 1. 난수 시드 초기화 (적 AI 및 데미지 변동폭에 사용)
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::cout << "========================================" << std::endl;
    std::cout << "         Turn RPG Game Start!           " << std::endl;
    std::cout << "========================================\n" << std::endl;

    // 2. 능력치(Status) 생성
    // (curHp, maxHp, curMp, maxMp, curAtk, baseAtk, curDef, baseDef, curSpeed, baseSpeed)
    Status playerStatus(100, 100, 30, 30, 25, 25, 5, 5, 10, 10);
    Status goblinStatus(50, 50, 0, 0, 15, 15, 2, 2, 8, 8);
    Status orcStatus(80, 80, 0, 0, 20, 20, 4, 4, 12, 12);

    // 3. 유닛 객체 생성 (동적 할당)
    Player* player = new Player("용사", playerStatus);
    Enemy* goblin = new Enemy("고블린", goblinStatus);
    Enemy* orc = new Enemy("오크", orcStatus);

    // 4. 전투 매니저에 등록할 유닛 목록 구성
    std::vector<Unit*> battleUnits;
    battleUnits.push_back(player);
    battleUnits.push_back(goblin);
    battleUnits.push_back(orc);

    // 5. Battle 매니저 생성 및 전투 실행
    Battle battle(battleUnits);
    
    std::cout << "전투가 시작되었습니다!" << std::endl;
    std::cout << "참가 유닛: " << player->GetName() << ", " 
              << goblin->GetName() << ", " 
              << orc->GetName() << "\n" << std::endl;

    // 전투 턴 루프 실행
    battle.OpenBattle();

    // 6. 메모리 해제 (동적 할당된 유닛들 정리)
    delete player;
    delete goblin;
    delete orc;

    std::cout << "\n========================================" << std::endl;
    std::cout << "         Game Finished.                 " << std::endl;
    std::cout << "========================================" << std::endl;

    return 0;
}