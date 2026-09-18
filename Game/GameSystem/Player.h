#pragma once
#include "Unit.h"

class Player : public Unit
{
public:
    // 기본 생성자
    Player() : Unit() {}

    // 💡 이름과 Status를 받아서 부모(Unit) 생성자로 전달하는 생성자 추가
    Player(const std::string& name, const Status& status)
        : Unit(name, status, false, false) {}
};