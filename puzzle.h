#include "common.h"
#define PUZZLE_SIZE 3
#define TILES_NUM 9
class Puzzle
{
private:
   int matrix[PUZZLE_SIZE][PUZZLE_SIZE];
   int x,y;
public:
    Puzzle();
    void defaultPuzzle();
    void move(int i,int j);
    int getIndex(int i,int j);
};


