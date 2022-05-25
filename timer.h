#ifndef H_TIMER
#define H_TIMER

#include "base.h"

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
};

#endif
