#ifndef H_TIMER
#define H_TIMER

#include "base.h"
const int MILISECOND_PER_SECOND = 1000;
const int SECOND_PER_MINUTE = 60;
class Timer
{
private:
    unsigned int startTicks, pauseTicks;
    bool paused, started;
public:
    void start();
    void stop();
    void pause();
    void unpause();
    unsigned int getTicks();
    float getSecond_fomat_second();
    unsigned int getSecondMinute_fomant_jiffy();
    unsigned int getSecondMinute_fomant_second();
    unsigned int getSecondMinute_fomant_minute();
    
};

#endif
