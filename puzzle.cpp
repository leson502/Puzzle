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

    texture = nullptr;

    for (int i=0; i<TILES_NUM; i++)
    {
        SDL_Rect *rect1 = new SDL_Rect;
        t_pos.push_back(rect1);
        SDL_Rect *rect2 = new SDL_Rect;
        t_struct.push_back(rect2);
    }

    border = new SDL_Rect;
    p_struct = new SDL_Rect;
}
void Puzzle::defaultPuzzle()
{
    
    for (int i=0; i<PUZZLE_SIZE; i++)
        for (int j=0; j<PUZZLE_SIZE; j++) 
            matrix[i][j]= (i*PUZZLE_SIZE+j+1)%TILES_NUM;

    x = PUZZLE_SIZE-1;
    y = PUZZLE_SIZE-1;


    setRect(border,PUZZLE_ORIGIN_X, PUZZLE_ORIGIN_Y, PUZZLEZONE, PUZZLEZONE);
    setRect(p_struct, 0, 0, PUZZLEZONE, PUZZLEZONE);
    
}

void Puzzle::move(int i,int j)
{
    for (int l=0; l<4; l++) 
        if (i+col[l] == x && j+row[l] == y)
        {
            swap(&matrix[x][y],&matrix[i][j]);
            x=i;
            y=j;
            //updateTilesPos();
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
    // render image background
    SDL_SetTextureColorMod(texture, 48,48,48); // darker color
    SDL_RenderCopy(render_target, texture, p_struct, border);

    // render tiles
    SDL_SetTextureColorMod(texture, 255,255,255); // full color
    SDL_SetRenderDrawColor(render_target, 0, 0 ,0 ,255);
    for (int i=blitFlags; i<TILES_NUM; i++)
    {
        SDL_RenderCopy(render_target, texture, t_struct[i], t_pos[i]);
        SDL_RenderDrawRect(render_target, t_pos[i]);
    }

    // border
    SDL_RenderDrawRect(render_target, border);
}

void Puzzle::updateTilesPos()
{
    for (int i=0; i<PUZZLE_SIZE; i++)
        for (int j=0; j<PUZZLE_SIZE; j++)
            {
                int vecX = (j*(PUZZLEZONE/PUZZLE_SIZE) + PUZZLE_ORIGIN_X)-t_pos[matrix[i][j]]->x;
                int vecY = (i*(PUZZLEZONE/PUZZLE_SIZE) + PUZZLE_ORIGIN_Y)-t_pos[matrix[i][j]]->y;
                
                for (int div=4; div>1; div/=2)
                        if (abs(vecX)>=div) 
                        {
                            vecX/=div;
                            break;
                        }
                for (int div=4; div>1; div/=2)
                        if (abs(vecY)>=div) 
                        {
                            vecY/=div;
                            break;
                        }
                        
                //SDL_Log("%d %d",vecX,vecY);
                t_pos[matrix[i][j]]->x += vecX;
                t_pos[matrix[i][j]]->y += vecY;
            }
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
            int index = (i*PUZZLE_SIZE+j+1)%TILES_NUM;
            setRect(t_struct[index],j * t_width,
                    i * t_height, t_width, t_height);
            setRect(t_pos[index], PUZZLE_ORIGIN_X
                    , PUZZLE_ORIGIN_Y, PUZZLEZONE/PUZZLE_SIZE,
                    PUZZLEZONE/PUZZLE_SIZE );
        }      
}

Puzzle::~Puzzle()
{
    destroyPuzzle();
}

void Puzzle::destroyPuzzle()
{
    for (SDL_Rect* i:t_pos) delete i;
    t_pos.clear();
    for (SDL_Rect* i:t_struct) delete i;
    t_struct.clear();
    texture = NULL;
    for (int i=0; i<PUZZLE_SIZE; i++) 
        delete []matrix[i];
    delete []matrix;
}

bool Puzzle::MouseProcess(const int x,const int y,const bool clicked)
{
    if (x>=PUZZLE_ORIGIN_X && x<=PUZZLE_ORIGIN_X+PUZZLEZONE &&
        y>=PUZZLE_ORIGIN_Y && y<=PUZZLE_ORIGIN_Y+PUZZLEZONE )
            {
                int j = (x-PUZZLE_ORIGIN_X)*PUZZLE_SIZE/PUZZLEZONE;
                int i = (y-PUZZLE_ORIGIN_Y)*PUZZLE_SIZE/PUZZLEZONE;
                if (clicked)
                {
                    move(i,j);
                    return 1;
                }
            }
    return 0;
}

int Puzzle::Getinversion()
{
    int count=0;
    for (int i=0; i<TILES_NUM-1; i++)
        for (int j= i+1; j<TILES_NUM; j++)
            {
                int &w = matrix[i/PUZZLE_SIZE][i%PUZZLE_SIZE];
                int &r = matrix[j/PUZZLE_SIZE][j%PUZZLE_SIZE];
                if (w && r && w > r) count++;
            }
    return count;
}

void Puzzle::Suffer()
{
    // suffer by using random swaping
     for (int i=0; i<PUZZLE_SIZE; i++)
        for (int j=0; j<PUZZLE_SIZE; j++)
            {
                int k = rand() % PUZZLE_SIZE;
                int l = rand() % PUZZLE_SIZE;
                swap(&matrix[i][j], &matrix[k][l]);
            } 

    // update empty tiles
    for (int i=0; i<PUZZLE_SIZE; i++)
        for (int j=0; j<PUZZLE_SIZE; j++)
            if (matrix[i][j] == 0) x=i,y=j;

    // make puzzle can be solve
    if (Getinversion() %2 !=0)
    {
        if (x <=1 && y == 0)
            swap(&matrix[PUZZLE_SIZE-1][PUZZLE_SIZE-1], &matrix[PUZZLE_SIZE-2][PUZZLE_SIZE-1]);
        else 
            swap(&matrix[0][0],&matrix[0][1]);
    } 
    
    updateTilesPos();
}