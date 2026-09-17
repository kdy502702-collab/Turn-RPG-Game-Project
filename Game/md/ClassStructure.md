Unit // 전투에 참가하는 유닛 자체
- Player
- NonPlayer
    - Enemy
    - NPC

Battle // 전투를 총 관리하는 객체
- 참가자 관리
- 행동 반영
- 턴 분배
- 승패 관리

Inventory // 아이템을 관리하는 객체

SkillList // 스킬 목록을 관리하는 객체

Status // 유닛의 능력치를 관리하는 객체



Unit
(Status, SkillList)
    - Player
    (PlayerAction, Experience, Inventory)
    - NonPlayer
        - Enemy
        - NPC
        (NonPlayerAction)

Status : 유닛의 능력치 관리
맴버 함수 : [curHp,maxHp, curMp, maxMp, curAtk, baseAtk, curDef, baseDef](현재/최대 Hp,Mp,공격력,수비력), curSpeed,baseSpeed(행동까지 걸리는 턴 수), moveCount(행동순서가 오기까지의 턴수)
주요 함수 : getter,setter(능력치 변화 관리), clearStatus(현재 스탯을 max치로 초기화)

SkillList : 유닛이 사용할 수 있는 스킬 관리/나중에 추가

Inventory : 인벤토리 관리/나중에 추가

Equipment : 장비 관리/나중에 추가

Unit : 전투에 등장하는 모든 유닛 관리
맴버 변수 : name(Unit 이름), Status(유닛의 능력치 관리), SkillList(유닛이 사용할 수 있는 스킬 관리/나중에 추가),//Buff/Debuff(버프,디버프 관리/나중에 추가), isDead(유닛의 생존 여부 관리), isDefense(방어 상태 관리), Inventory(인벤토리 관리/나중에 추가), Equipment(장비 관리/나중에 추가)
주요 함수 : abstact SelectAction(유닛의 행동을 결정, 자식 클래스에서 각각 구현) TakeDamage(데미지 받음 구현), TakeHeling(치료 받음 구현)

Player : 플레이어가 조작하는 유닛 관리 : Unit 상속
맴버 변수 : lv(레벨), curExp(경험치), needExp(레벨업까지 필요한 경험치),
주요 함수 : SelectAction(행동 선택 기능), LvUp(경험치가 넘었을때 레벨업 관리 및 스탯업 관리) , TakeExp(경험치 올리기)

Enemy : 적으로 나오는 Unit 관리 : Unit 상속
맴버 변수 : DropExp,DropItem
주요 함수 : SelectAction(행동 선택 기능),Exp or Item의 getter, setter(드롭 경험치/아이템 관리)

Action : 유닛의 행동을 관리?
종류
- Attack/공격자,타겟의 정보>>유닛의 영향 반영
- Defense/유닛의 방어 상태를 활성화
- Skill/나중에 구현
- Item/나중에 구현
- Run


Battle : 전투 전체를 관리
맴버 변수 : vector<Unit*> units(전투에 참가하는 모든 유닛 관리), ally or enemyCount(아군과 적 카운트/승패를 위한 조건), countSize(턴 카운트가 흘러가는 단위#만약 Unit의 speed가 9, moveCount가 6, countSize가 3이라면 한 틱당 moveCount가 3씩 줄어들고, moveCount가 0이 되면 행동 기회)
주요 함수 : TakeAction(받은 선택에 따른 행동 반영), AddUnit(유닛을 추가),DelUnit(유닛을 제거), TakeCount(유닛의 카운트를 감소 or 증가), FinishBattle(전투 종료), CheckFinish(전투가 종료되는지 확인하는 함수)

