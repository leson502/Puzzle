#include "game_clock.h"


Clock::Clock()
{
    memoryAlocate();
    ResetClock();
}

void Clock::memoryAlocate()
{
    text = new Text_object;
    renderer = NULL;
}
void Clock::ResetClock()
{
    count = 0;
    lastTick = SDL_GetTicks64();
}

int Clock::GetSecond()
{
    return (count/MS_PER_SECOND);
}

int Clock::GetMinutes()
{
    return (count);
}

void Clock::UpdateTick()
{
    int currentTick = SDL_GetTicks64();
    count += (currentTick-lastTick);
}

void Clock::setRender_target(SDL_Renderer *render_target)
{
    renderer = render_target;
    text->setRender_target(renderer);
}

void Clock::blit()
{
    text->setPos(CLOCK_POS_X, CLOCK_POS_Y);
    text->setSize(CLOCK_WIDTH,CLOCK_HEIGHT);
    std::string str = std::to_string(GetSecond());
    SDL_Log("%s", str.c_str());
    text->createTexture(str);

    text->blit();
}

void Clock::setFont(TTF_Font* font)
{
    text->setFont(font);
}