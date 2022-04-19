#ifndef H_GAME_CLOCK
#define H_GAME_CLOCK

#include "base.h"
#include "object_text.h"

const int SECOND_PER_MINUTE = 60;
const int MS_PER_SECOND = 1000;
class Clock
{
private:
    Text_object *text;
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