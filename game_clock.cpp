#include "game_clock.h"


Clock::Clock()
{
    ResetClock();
}

void Clock::ResetClock()
{
    count = 0;
    lastTick = SDL_GetTicks();
}

int Clock::GetSecond()
{
    return count/TIME;
}

int Clock::GetMinutes()
{
    return count%TIME;
}

void Clock::UpdateTick()
{
    int currentTick = SDL_GetTicks();
    count += (currentTick-lastTick)/1000;
}