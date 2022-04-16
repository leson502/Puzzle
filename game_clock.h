#ifndef H_GAME_CLOCK
#define H_GAME_CLOCK

#include "base.h"

const int TIME = 60;
class Clock
{
private:
    int lastTick;
    int count;
public:
    Clock();
    void ResetClock();
    int GetMinutes();
    int GetSecond();
    void UpdateTick();
    ~Clock();
};

#endif