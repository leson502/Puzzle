#ifndef H_PUZZE
#define H_PUZZE


#include "base.h"
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
   std::vector<SDL_Rect*> t_pos,t_struct;
   SDL_Texture *texture;
public:
    Puzzle();
    ~Puzzle();
    void memoryAllocate();
    void defaultPuzzle();
    void setTexture(SDL_Texture *texture);
    void blitPuzzle(SDL_Renderer *render_target,  bool blitFlags);
    void updateTilesPos();
    void setTilesSize();
    void splitPicture();
    void destroyPuzzle();
    void move(int i,int j);
    int getIndex(int i,int j);
};

#endif

