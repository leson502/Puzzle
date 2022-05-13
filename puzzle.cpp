#include "puzzle.h"

Puzzle::Puzzle()
{
    memoryAllocate();
    Init();
}

void Puzzle::memoryAllocate()
{
    matrix = new int*[GRID_WIDTH];
    for (int i=0; i<GRID_WIDTH; i++)
        matrix[i] = new int[GRID_WIDTH];

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

void Puzzle::Init()
{
    for (int i=0; i<GRID_WIDTH; i++)
        for (int j=0; j<GRID_WIDTH; j++) 
            matrix[i][j]= (i*GRID_WIDTH+j+1)%TILES_NUM;

    x = GRID_WIDTH-1;
    y = GRID_WIDTH-1;


    setRect(border,PUZZLE_ORIGIN_X, PUZZLE_ORIGIN_Y, PUZZLEZONE, PUZZLEZONE);
}

bool Puzzle::move(int i,int j)
{
    for (int l=0; l<4; l++) 
        if (i+col[l] == x && j+row[l] == y)
        {
            std::swap(matrix[x][y],matrix[i][j]);
            x=i;
            y=j;
            return 1;
        }
    return 0;
}

void Puzzle::setTexture(SDL_Texture* _texture)
{
    texture = _texture;
    splitPicture();
}

void Puzzle::blitPuzzle(bool blitFlags)
{
    // render image background
    SDL_SetTextureColorMod(texture, 48,48,48); // darker color
    SDL_RenderCopy(renderer, texture, p_struct, border);
    
    // render tiles
    SDL_SetTextureColorMod(texture, 255,255,255); // full color
    SDL_SetRenderDrawColor(renderer, 0, 0 ,0 ,255);
    for (int i=blitFlags; i<TILES_NUM; i++)
    {
        SDL_RenderCopy(renderer, texture, t_struct[i], t_pos[i]);
        SDL_RenderDrawRect(renderer, t_pos[i]);
    }

    // border
    SDL_RenderDrawRect(renderer, border);
}

void Puzzle::updateTilesPos()
{
    for (int i=0; i<GRID_WIDTH; i++)
        for (int j=0; j<GRID_WIDTH; j++)
            {
                int vecX = (j*(PUZZLEZONE/GRID_WIDTH) + PUZZLE_ORIGIN_X)-t_pos[matrix[i][j]]->x;
                int vecY = (i*(PUZZLEZONE/GRID_WIDTH) + PUZZLE_ORIGIN_Y)-t_pos[matrix[i][j]]->y;
                
                for (int div=3; div>1; div/=2)
                        if (abs(vecX)>=div) 
                        {
                            vecX/=div;
                            break;
                        }
                for (int div=3; div>1; div/=2)
                        if (abs(vecY)>=div) 
                        {
                            vecY/=div;
                            break;
                        }
                
                t_pos[matrix[i][j]]->x += vecX;
                t_pos[matrix[i][j]]->y += vecY;
            }
}

void Puzzle::splitPicture() 
{
    int t_height,t_width;
    SDL_QueryTexture(texture, NULL, NULL, &t_width,&t_height);
    setRect(p_struct, 0, 0, t_width, t_height);
    
    t_height/=GRID_WIDTH;
    t_width/=GRID_WIDTH;
    
    for (int i=0; i<GRID_WIDTH; i++)
        for (int j=0; j<GRID_WIDTH; j++)   
        {
            int index = (i*GRID_WIDTH+j+1)%TILES_NUM;
            setRect(t_struct[index],j * t_width,
                    i * t_height, t_width, t_height);
            setRect(t_pos[index], PUZZLE_ORIGIN_X
                    , PUZZLE_ORIGIN_Y, PUZZLEZONE/GRID_WIDTH,
                    PUZZLEZONE/GRID_WIDTH );
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
    for (int i=0; i<GRID_WIDTH; i++) 
        delete []matrix[i];
    delete []matrix;
}

bool Puzzle::MouseProcess(const int x,const int y,const bool clicked)
{
    if (hitBoxCheck(x, y, PUZZLE_ORIGIN_X, PUZZLE_ORIGIN_Y
                    , PUZZLEZONE, PUZZLEZONE))
            {
                int j = (x-PUZZLE_ORIGIN_X)*GRID_WIDTH/PUZZLEZONE;
                int i = (y-PUZZLE_ORIGIN_Y)*GRID_WIDTH/PUZZLEZONE;
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
                int &w = matrix[i/GRID_WIDTH][i%GRID_WIDTH];
                int &r = matrix[j/GRID_WIDTH][j%GRID_WIDTH];
                if (w && r && w > r) count++;
            }
    return count;
}

void Puzzle::Suffer()
{
    // suffer by using random swaping
     for (int i=0; i<GRID_WIDTH; i++)
        for (int j=0; j<GRID_WIDTH; j++)
            {
                int k = rand() % GRID_WIDTH;
                int l = rand() % GRID_WIDTH;
                std::swap(matrix[i][j], matrix[k][l]);
            } 

    // update empty tiles
    for (int i=0; i<GRID_WIDTH; i++)
        for (int j=0; j<GRID_WIDTH; j++)
            if (matrix[i][j] == 0) x=i,y=j;

    // make puzzle can be solve
    if (Getinversion() %2 !=0)
    {
        if (x <=1 && y == 0)
            std::swap(matrix[GRID_WIDTH-1][GRID_WIDTH-1], matrix[GRID_WIDTH-2][GRID_WIDTH-1]);
        else 
            std::swap(matrix[0][0],matrix[1][0]);
    } 
    
    updateTilesPos();
}

void Puzzle::setRender_target(SDL_Renderer *render_target)
{
    renderer = render_target;
}