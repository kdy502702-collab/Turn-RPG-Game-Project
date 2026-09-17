#구상
[RPG 게임]

>>전투
1. 시스템
- 턴제
    - 턴 회전 => 행동
- 행동 
    - 공격 - 타겟팅
    - 스킬 - 타겟팅
    - 방어  (받는 데미지 감소)
    - 아이템
// Player의 경우 => 유저의 선택
// Enemy의 경우 => Enemy에서 선택 알고리즘에 따른 값 반환 => 반환받은 값의 의한 행동 실행
- 승/패 관리
    - 한 그룹의 전체 사망 -> 종료 조건 (적과 아군 수 카운팅, 등장 또는 퇴장 및 사망시 카운트 관리)



2. 유닛
- 기본 정보
(Name)
(Stat)<hp,mp,atk,def,speed>
(SkillList)<>
(StatusEffect)<buff,debuff>

- Player
(Item)<weapon,armor>
SelectAction()
- Enemy
(Pattern)<>
SelectAction()
