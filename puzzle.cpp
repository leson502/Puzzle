#include "puzzle.h"

Puzzle::Puzzle()
{
    memoryAllocate();
    defaultPuzzle();
}

void Puzzle::memoryAllocate()
{
    matrix = new int*[PUZZLE_SIZE];
    for (int i=0; i<PUZZLE_SIZE; i++)
        matrix[i] = new int[PUZZLE_SIZE];

    x = new int;
    y = new int;

    tiles = new Object[TILES_NUM];
}
void Puzzle::defaultPuzzle()
{
    
    for (int i=0; i<PUZZLE_SIZE; i++)
        for (int j=0; j<PUZZLE_SIZE; j++) 
            matrix[i][j]= (i*PUZZLE_SIZE+j+1)%TILES_NUM;

    *x = PUZZLE_SIZE-1;
    *y = PUZZLE_SIZE-1;

    updateTilesPos();
    setTilesSize();
}

int Puzzle::getIndex(int i,int j)
{
    return matrix[i][j];
}

void Puzzle::move(int i,int j)
{
    for (int l=0; l<4; l++) 
        if (i+col[l] == *x && j+row[l] == *y)
        {
            swap(&matrix[*x][*y],&matrix[i][j]);
            *x=i;
            *y=j;
            updateTilesPos();
            break;
        }
}

void Puzzle::setTexture(std::vector<SDL_Texture*> &_texture)
{
    for (int i=0; i<9; i++) tiles[i].setTexture(_texture[i]);
}

void Puzzle::blitPuzzle(SDL_Renderer *render_target, bool blitFlags)
{
    for (int i=blitFlags; i<TILES_NUM; i++) tiles[i].blit(render_target);
}

void Puzzle::updateTilesPos()
{
    for (int i=0; i<PUZZLE_SIZE; i++)
        for (int j=0; j<PUZZLE_SIZE; j++)
            tiles[matrix[i][j]].setPos(j*BLOCKSIZE + PUZZLE_ORIGIN_X, i*BLOCKSIZE + PUZZLE_ORIGIN_Y);
}

void Puzzle::setTilesSize()
{
    for (int i=0; i<TILES_NUM; i++) 
        tiles[i].setSize(BLOCKSIZE, BLOCKSIZE);
}
