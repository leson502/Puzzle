#ifndef PUZZE__H
#define PUZZE__H


#include "common.h"
#include "base_object.h"

#define PUZZLE_SIZE 3
#define TILES_NUM 9

// down, left, right, up
const int row[] = { 1, 0, -1, 0 };
const int col[] = { 0, -1, 0, 1 };

class Puzzle
{
private:
   int **matrix;
   int *x,*y;
   Object *tiles;
public:
    Puzzle();
    void memoryAllocate();
    void defaultPuzzle();
    void setTexture(std::vector<SDL_Texture*> &_texture);
    void blitPuzzle(SDL_Renderer *render_target,  bool blitFlags);
    void updateTilesPos();
    void setTilesSize();
    void move(int i,int j);
    int getIndex(int i,int j);
};

#endif

