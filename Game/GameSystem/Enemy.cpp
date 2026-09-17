#include "Enemy.h"
#include "Player.h"

ActionInfo Enemy::SelectAction(const std::vector<Unit*>& units)
{
    std::vector<Unit*> targets;
    targets.push_back(this);
    for(Unit* target:units){
        if(Player* player = dynamic_cast<Player*>(target)){
            targets.push_back(target);
        }
    }
    ActionInfo actionInfo = {1,targets};
    return actionInfo;
}