#include "timer.h"

void Timer::start()
{
    startTicks = SDL_GetTicks();
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

        pauseTicks = SDL_GetTicks()- startTicks;
        startTicks = 0;
    }
}

void Timer::unpause()
{
    if (started && paused)
    {
        paused = false;

        startTicks = SDL_GetTicks() - pauseTicks;
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
                time = SDL_GetTicks()-startTicks;
        }
    return time;
}