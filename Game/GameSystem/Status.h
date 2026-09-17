#pragma once
class Status
{
    private:
        int curHp,maxHp, curMp, maxMp, curAtk, baseAtk, curDef, baseDef,curSpeed,baseSpeed,moveCount;
    public:
        Status():curHp(1),maxHp(1), curMp(1), maxMp(1), curAtk(1), baseAtk(1), curDef(1), baseDef(1),curSpeed(1),baseSpeed(999),moveCount(999){}
        Status(int curHp,int maxHp, int curMp, int maxMp, int curAtk, int baseAtk, int curDef, int baseDef,int curSpeed,int baseSpeed)
        :curHp(curHp),maxHp(maxHp), curMp(curMp), maxMp(maxMp), curAtk(curAtk), baseAtk(baseAtk), curDef(curDef), baseDef(baseDef),curSpeed(curSpeed),baseSpeed(baseSpeed),moveCount(baseSpeed){}
        void SetCurHp(int curHp){this->curHp = curHp;}
        void SetMaxHp(int maxHp){this->maxHp = maxHp;}
        void SetCurMp(int curMp){this->curMp = curMp;}
        void SetMaxMp(int maxMp){this->maxMp = maxMp;}
        void SetCurAtk(int curAtk){this->curAtk = curAtk;}
        void SetBaseAtk(int baseAtk){this->baseAtk = baseAtk;}
        void SetCurDef(int curDef){this->curDef = curDef;}
        void SetBaseDef(int baseDef){this->baseDef = baseDef;}
        void SetCurSpeed(int curSpeed){this->curSpeed = curSpeed;}
        void SetBaseSpeed(int baseSpeed){this->baseSpeed = baseSpeed;}
        void SetMoveCount(int moveCount){this->moveCount = moveCount;}
        int GetCurHp()const{return this->curHp;}
        int GetMaxHp()const{return this->maxHp;}
        int GetCurMp()const{return this->curMp;}
        int GetMaxMp()const{return this->maxMp;}
        int GetCurAtk()const{return this->curAtk;}
        int GetBaseAtk()const{return this->baseAtk;}
        int GetCurDef()const{return this->curDef;}
        int GetBaseDef()const{return this->baseDef;}
        int GetCurSpeed()const{return this->curSpeed;}
        int GetBaseSpeed()const{return this->baseSpeed;}
        int GetMoveCount()const{return this->moveCount;}
        void ClearStatus(){curHp=maxHp; curMp=maxMp; curAtk=baseAtk; curDef = baseDef; curSpeed=baseSpeed;moveCount=baseSpeed;};

};
