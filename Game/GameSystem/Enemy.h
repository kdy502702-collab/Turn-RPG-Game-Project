#pragma once
#include "Unit.h"

class Enemy : Unit{
    public:
        ActionInfo SelectAction(const std::vector<Unit*>& units);
};