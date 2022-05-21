#ifndef H_PUZZLE_BAR
#define H_PUZZLE_BAR

#include "base.h"
#include "bar_tile.h"
#include "button.h"
#include "display_fullsize_object.h"

const unsigned int BAR_ORIGIN_X = 55;
const unsigned int BAR_ORIGIN_Y = 60;
const unsigned int BAR_HEIGHT = 600;
const unsigned int BAR_WIDTH = 200;
const unsigned int OBJECT_NUM = 5;
const unsigned int DISPLAY_OBJECT_NUM = 3;
const unsigned int UPBUTTON_X = 115;
const unsigned int UPBUTTON_Y = 0;
const unsigned int DOWNBUTTON_X = 115;
const unsigned int DOWNBUTTON_Y = 660;
const unsigned int BUTTON_W = 80;
const unsigned int BUTTON_H = 60;

class PuzzleBar
{
private:
    int top,current;
    std::vector<Bar_tile*> tiles;
    Button *UpButton, *DownButton;
    Display_fullsize_object *background;
    SDL_Renderer *renderer;
public:
    PuzzleBar();
    PuzzleBar(SDL_Renderer *render_target);
    void Init();
    void loadTexture();
    void setObjectPos();
    void blit();
    void move(int x);
    bool MouseProcess(const int x, const int y, const bool clicked);
    SDL_Texture *GetNewTexture();
    void setRender_target(SDL_Renderer *render_target);
    ~PuzzleBar();
};

#endif