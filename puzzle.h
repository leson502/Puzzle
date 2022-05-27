#ifndef H_PUZZE
#define H_PUZZE


#include "base.h"
#include "puzzle_board.h"
#include "puzzle_tile.h"
#include "display_fullsize_object.h"
#include "timer.h"
#include "text_rendering.h"
const int DEFAULT_GRID_WIDTH = 3;
const unsigned int PUZZLEZONE = 660;
const unsigned int PUZZLE_ORIGIN_X = 310;
const unsigned int PUZZLE_ORIGIN_Y = 30;
const std::string font_filename = "font/Roboto-Light.ttf";

enum{
    PLAYING, PREPARE, GOAL
};
class Puzzle
{
private:
    Puzzle_board *board;
    std::vector<Puzzle_tile*>  tiles;
    Display_fullsize_object *fullpuzzle;
    SDL_Texture *texture;
    SDL_Renderer *renderer;
    Timer *timer;
    Text_rendering *text_renderer;
    TTF_Font *puzzle_general_font, *tileFont;
    unsigned int status;
    bool showIndex;
public:
    Puzzle();
    Puzzle(int grid_width);
    Puzzle(int grid_width, SDL_Renderer *render_target);
    Puzzle(int grid_width, SDL_Renderer *render_target, SDL_Texture *texture);
    Puzzle(SDL_Renderer *render_target);
    Puzzle(SDL_Renderer *render_target, SDL_Texture *texture);
    ~Puzzle();
    void InitGlobal();
    void InitObject(int grid_width);
    void setTexture(SDL_Texture *_texture);
    void blitPuzzle();
    void blitTimer();
    bool show_hide_number();
    void blit();
    void setRender_target(SDL_Renderer *render_target);
    void setFont(TTF_Font *t_timer_font, TTF_Font *t_tile_font);
    void updateTilesPos(bool SlideEffect);
    void updatePuzzle();
    void splitPicture();
    void destroy();
    void suffer();
    void resize(int grid);
    bool isGoal();
    void play();
    bool MouseProcess(const int x,const int y,const bool clicked);
    bool MovementProcess(const bool up, const bool down, const bool left, const bool right);
};

#endif