#ifndef H_PUZZE
#define H_PUZZE


#include "base.h"
#include "base_object.h"

const int PUZZLE_SIZE = 3;
const int TILES_NUM = PUZZLE_SIZE*PUZZLE_SIZE;

// down, left, right, up
const int row[] = { 1, 0, -1, 0 };
const int col[] = { 0, -1, 0, 1 };

class Puzzle
{
private:
   int **matrix;
   int x,y;
   std::vector<SDL_Rect*> t_pos,t_struct;
   SDL_Texture *texture;
   SDL_Rect *border, *p_struct;
   SDL_Renderer *renderer;
public:
    Puzzle();
    ~Puzzle();
    void memoryAllocate();
    void defaultPuzzle();
    void setTexture(SDL_Texture *_texture);
    void blitPuzzle(bool blitFlags);
    void setRender_target(SDL_Renderer *render_target);
    void updateTilesPos();
    void splitPicture();
    void destroyPuzzle();
    int Getinversion();
    void Suffer();
    bool MouseProcess(const int x,const int y,const bool clicked);
    void move(int i,int j);
};

#endif