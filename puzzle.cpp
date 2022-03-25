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

    texture = nullptr;

    for (int i=0; i<TILES_NUM; i++)
    {
        SDL_Rect *rect1 = new SDL_Rect;
        t_pos.push_back(rect1);
        SDL_Rect *rect2 = new SDL_Rect;
        t_struct.push_back(rect2);
    }
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

void Puzzle::setTexture(SDL_Texture* _texture)
{
    texture = _texture;
    splitPicture();
}

void Puzzle::blitPuzzle(SDL_Renderer *render_target, bool blitFlags)
{
    for (int i=blitFlags; i<TILES_NUM; i++) 
    {
        SDL_RenderCopy(render_target, texture, t_struct[i], t_pos[i]);   
        SDL_SetRenderDrawColor(render_target, 0, 0 ,0 ,255);
        SDL_RenderDrawRect(render_target, t_pos[i]);
    }
        
}

void Puzzle::updateTilesPos()
{
    for (int i=0; i<PUZZLE_SIZE; i++)
        for (int j=0; j<PUZZLE_SIZE; j++)
            {
                t_pos[matrix[i][j]]->x = j*BLOCKSIZE + PUZZLE_ORIGIN_X;
                t_pos[matrix[i][j]]->y = i*BLOCKSIZE + PUZZLE_ORIGIN_Y;
            }
            
}

void Puzzle::setTilesSize()
{
    for (int i=0; i<TILES_NUM; i++) 
        t_pos[i]->h = t_pos[i]->w = BLOCKSIZE;
}

void Puzzle::splitPicture()
{
    int t_height,t_width;
    SDL_QueryTexture(texture, NULL, NULL, &t_width,&t_height);
    t_height/=PUZZLE_SIZE;
    t_width/=PUZZLE_SIZE;
    for (int i=0; i<PUZZLE_SIZE; i++)
        for (int j=0; j<PUZZLE_SIZE; j++)   
        {
            t_struct[matrix[i][j]]->x = j * t_width;
            t_struct[matrix[i][j]]->y = i * t_height;
            t_struct[matrix[i][j]]->w = t_width;
            t_struct[matrix[i][j]]->h = t_height;
        }      
}

Puzzle::~Puzzle()
{
    destroyPuzzle();
}

void Puzzle::destroyPuzzle()
{
    t_pos.clear();
    t_struct.clear();
    SDL_DestroyTexture(texture);
    delete matrix;
    delete x;
    delete y;
}