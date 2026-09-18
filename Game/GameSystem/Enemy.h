#pragma once
#include "Unit.h"

class Enemy : public Unit
{
public:
    // 기본 생성자
    Enemy() : Unit() {}

    // 💡 이름과 Status를 받아서 부모(Unit) 생성자로 전달하는 생성자 추가
    Enemy(const std::string& name, const Status& status)
        : Unit(name, status, false, false) {}

    ActionInfo SelectAction(const std::vector<Unit*>& units);
};