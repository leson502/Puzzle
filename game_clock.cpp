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
    return (count/MS_PER_SECOND)/SECOND_PER_MINUTE;
}

int Clock::GetMinutes()
{
    return (count/MS_PER_SECOND)%SECOND_PER_MINUTE;
}

void Clock::UpdateTick()
{
    int currentTick = SDL_GetTicks();
    count += (currentTick-lastTick);
}