#include "base.h"


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
    int tiles_num();
    int getInversion();
    int getIndex(int i, int j);
    int getGrid_width();
    void suffer();
};

