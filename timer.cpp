#include "timer.h"

void Timer::start()
{
    startTicks = clock();
    started = true;
    pauseTicks = 0;
    paused = false;
}


void Timer::stop()
{
    startTicks = 0;
    started = false;
    pauseTicks = 0;
    paused = false;
}

void Timer::pause()
{
    if (started && !paused)
    {
        paused = true;

        pauseTicks = clock()- startTicks;
        startTicks = 0;
    }
}

void Timer::unpause()
{
    if (started && paused)
    {
        paused = false;

        startTicks = clock() - pauseTicks;
        pauseTicks = 0;
    }
}

unsigned int Timer::getTicks()
{
    unsigned int time = 0;
    
    if (started)
        {
            if (paused)
                time = pauseTicks;
            else 
                time = clock()-startTicks;
        }
    return time;
}

float Timer::getSecond_fomat_second()
{
    float ticks = getTicks();
    return ticks/MILISECOND_PER_SECOND;
}

unsigned int Timer::getSecondMinute_fomant_second()
{
    int second = getSecond_fomat_second();
    return second % SECOND_PER_MINUTE;
}

unsigned int Timer::getSecondMinute_fomant_jiffy()
{
    int jiffy = getTicks()*SECOND_PER_MINUTE/MILISECOND_PER_SECOND;
    return jiffy%SECOND_PER_MINUTE;
}

unsigned int Timer::getSecondMinute_fomant_minute()
{
    int second = getSecond_fomat_second();
    return second / SECOND_PER_MINUTE;
}