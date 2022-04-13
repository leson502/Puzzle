#ifndef H_PUZZLE_BAR
#define H_PUZZLE_BAR

#include "base.h"
#include "base_object.h"

const unsigned int BAR_ORIGIN_X = 55;
const unsigned int BAR_ORIGIN_Y = 60;
const unsigned int BAR_HEIGHT = 600;
const unsigned int BAR_WIDTH = 200;
const unsigned int OBJECT_NUM = 5;
const unsigned int DISPLAY_OBJECT_NUM = 3;

class PuzzleBar
{
private:
    std::vector<Object*> puzzlelist;
    SDL_Rect *border;
    int top,current;
public:
    PuzzleBar();
    void defaultBar();
    void memAllocate();
    void loadObject(SDL_Renderer *render_target);
    void setObjectPos();
    void Blit(SDL_Renderer *render_target);
    void move(int x);
    bool MouseProcess(const int x, const int y, const bool clicked);
    SDL_Texture *GetNewTexture();
    ~PuzzleBar();
};

#endif
