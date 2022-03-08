#include "puzzle.h"

Puzzle::Puzzle()
{
    defaultPuzzle();
}

void Puzzle::defaultPuzzle()
{
    for (int i=0; i<PUZZLE_SIZE; i++)
        for (int j=0; j<PUZZLE_SIZE; j++) 
            matrix[i][j]= (i*PUZZLE_SIZE+j+1)%TILES_NUM;
    x = 2;
    y = 2;
    
}

int Puzzle::getIndex(int i,int j)
{
    return matrix[i][j];
}

void Puzzle::move(int i,int j)
{
    if (i<0 || i>2 || j<0 || i>2) return;
    if (abs(x-i)>1 || abs(y-j)>1 ) return;
    if (abs(x-i)>0 && abs(y-j)>0) return;
    swap(matrix[x][y],matrix[i][j]);
    x=i;
    y=j;
}