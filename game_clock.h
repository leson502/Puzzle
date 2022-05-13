#ifndef H_GAME_CLOCK
#define H_GAME_CLOCK

#include "base.h"
#include "object_text.h"

const int SECOND_PER_MINUTE = 60;
const int MS_PER_SECOND = 100000;
const int CLOCK_POS_X = 1125;
const int CLOCK_POS_Y = 30;
const int CLOCK_WIDTH = 60;
const int CLOCK_HEIGHT = 15;
class Clock
{
private:
    Text_object *text;
    SDL_Renderer *renderer;
    int lastTick;
    int count;
public:
    Clock();
    void memoryAlocate();
    void ResetClock();
    int GetMinutes();
    int GetSecond();
    void UpdateTick();
    void setRender_target(SDL_Renderer *render_target);
    void setFont(TTF_Font *font);
    void blit();
    ~Clock();
};

#endif