#ifndef H_PUZZLE_BOARD
#define H_PUZZLE_BOARD

#include "base.h"

enum{
    BOARD_KEY_UP, BOARD_KEY_RIGHT, BOARD_KEY_DOWN, BOARD_KEY_LEFT
};

const int row[] = { 1, 0, -1, 0 };
const int col[] = { 0, -1, 0, 1 };

class Puzzle_board
{
private:
    int grid_width,empty_x,empty_y;
    std::vector< std::vector<int>> matrix;
public:
    Puzzle_board();
    Puzzle_board(int width);
    void Init(int width);
    void resize(int width);
    bool move(int i, int j);
    bool move(int movement_key);
    int tiles_num();
    int getInversion();
    int getIndex(int i, int j);
    int getGrid_width();
    bool isGoal();
    bool isSolvable();
    void suffer();
    bool checkTilesIvalid(int i,int j);
};
#endif