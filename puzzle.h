#ifndef H_PUZZE
#define H_PUZZE


#include "base.h"
#include "puzzle_board.h"
#include "puzzle_tile.h"
#include "display_fullsize_object.h"

const int DEFAULT_GRID_WIDTH = 3;
const unsigned int PUZZLEZONE = 660;
const unsigned int PUZZLE_ORIGIN_X = 310;
const unsigned int PUZZLE_ORIGIN_Y = 30;

class Puzzle
{
private:
    Puzzle_board *board;
    std::vector<Puzzle_tile*>  tiles;
    Display_fullsize_object *fullpuzzle;
    SDL_Texture *texture;
    SDL_Renderer *renderer;
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
    void blit(bool blitFlags);
    void setRender_target(SDL_Renderer *render_target);
    void updateTilesPos(bool SlideEffect);
    void splitPicture();
    void destroy();
    void suffer();
    void resize(int grid);
    bool isGoal();
    bool MouseProcess(const int x,const int y,const bool clicked);
};

#endif