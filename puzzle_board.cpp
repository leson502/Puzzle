#include "puzzle_board.h"

Puzzle_board::Puzzle_board()
{
    Init(3);
}

Puzzle_board::Puzzle_board(int width)
{
    Init(width);
}

void Puzzle_board::Init(int width)
{
    grid_width = width;
    matrix = std::vector< std::vector<int> > (width, std::vector<int> (width));
    for (int i=0; i<width; i++)
    {
        for (int j=0; j<width; j++)
            {
                // index of maxtrix start from 0 to (grid_width*grid_width-1)
                matrix[i][j] = ((i*grid_width+j+1) % (tiles_num()));
            }
    }
    empty_x = grid_width - 1;
    empty_y = grid_width - 1;        
}

bool Puzzle_board::move(int i,int j)
{
    for (int l=0; l<4; l++) 
        if (i == empty_x+row[l] && j == empty_y + col[l])
            return move(l);
    return 0;
}

bool Puzzle_board::move(int movement_key)
{
    int i =empty_x + row[movement_key];
    int j =empty_y + col[movement_key];
    if (checkTilesIvalid(i,j))
    {
        std::swap(matrix[empty_x][empty_y],matrix[i][j]);
        empty_x=i;
        empty_y=j;
        return 1;
    }
    return 0;
}   

bool Puzzle_board::checkTilesIvalid(int i,int j)
{
    return (0<= i && i<grid_width && 0<=j && j<grid_width);
}
int Puzzle_board::getInversion()
{
    int count=0;
    for (int i=0; i<tiles_num()-1; i++)
        for (int j= i+1; j<tiles_num(); j++)
            {
                int &w = matrix[i/grid_width][i%grid_width];
                int &r = matrix[j/grid_width][j%grid_width];
                if (w && r && w > r) count++;
            }
    return count;
}

void Puzzle_board::suffer()
{
    // suffer by using random swaping
     for (int i=0; i<grid_width; i++)
        for (int j=0; j<grid_width; j++)
            {
                int k = rand() % grid_width;
                int l = rand() % grid_width;
                std::swap(matrix[i][j], matrix[k][l]);
            } 

    // update empty tiles
    for (int i=0; i<grid_width; i++)
        for (int j=0; j<grid_width; j++)
            if (matrix[i][j] == 0) empty_x=i,empty_y=j;

    // make puzzle can be solve
    if (!isSolvable())
    {
        if (empty_x == 0 && empty_y <= 1)
            std::swap(matrix[grid_width-1][grid_width-1], matrix[grid_width-1][grid_width-2]);
        else 
            std::swap(matrix[0][0],matrix[0][1]);
    } 
    if (!isSolvable()) SDL_Log("unSolvable");
}

void Puzzle_board::resize(int width)
{
    Init(width);
}

int Puzzle_board::tiles_num()
{
    return grid_width*grid_width;
}

int Puzzle_board::getGrid_width()
{
    return grid_width;
}

int Puzzle_board::getIndex(int i,int j)
{
    return matrix[i][j];
}

bool Puzzle_board::isGoal()
{
    for (int i=0; i<grid_width; i++)
        for (int j=0; j<grid_width; j++)
           if (matrix[i][j] != ((i*grid_width+j+1) % (tiles_num()))) return false;
    return true;
}

bool Puzzle_board::isSolvable()
{
    int inversion = getInversion();
    if (grid_width % 2 == 1)
        return (inversion % 2 == 0);
    else 
        return ((inversion + grid_width- empty_x -1) %2 == 0);
    /*
    1. If grid_width is odd, then puzzle instance is solvable if number of inversions is even.
    2. If grid_witdh is even, puzzle instance is solvable if 
        a. the blank is on an even row counting from the bottom (second-last, fourth-last, etc.) and number of inversions is odd.
        b. the blank is on an odd row counting from the bottom (last, third-last, fifth-last, etc.) and number of inversions is even.
    3. For all other cases, the puzzle instance is not solvable.
    */
}

