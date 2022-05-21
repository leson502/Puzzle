#include "puzzle_board.h"

Puzzle_board::Puzzle_board()
{}

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
        if (i+col[l] == empty_x && j+row[l] == empty_y)
        {
            std::swap(matrix[empty_x][empty_y],matrix[i][j]);
            empty_x=i;
            empty_y=j;
            return 1;
        }
    return 0;
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
    if (getInversion() %2 !=0)
    {
        if (empty_x <=1 && empty_y == 0)
            std::swap(matrix[grid_width-1][grid_width-1], matrix[grid_width-2][grid_width-1]);
        else 
            std::swap(matrix[0][0],matrix[1][0]);
    } 
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