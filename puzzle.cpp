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
    if (i<-1 || i>1 || j<-1 || j>1) return;
    if ((x+i)<0 || (x+i)>2 || (y+j)<0 || (y+j)>2) return;
    swap(matrix[x][y],matrix[x+i][y+j]);
    x+=i;
    y+=j;
}