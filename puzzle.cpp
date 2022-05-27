#include "puzzle.h"

Puzzle::Puzzle()
{
    InitGlobal();
    InitObject(DEFAULT_GRID_WIDTH);
}

Puzzle::Puzzle(int grid_width)
{
    InitGlobal();
    InitObject(grid_width);
}

Puzzle::Puzzle(int grid_width, SDL_Renderer *render_target)
: Puzzle(grid_width)
{
    setRender_target(render_target);
}

Puzzle::Puzzle(int grid_width, SDL_Renderer *render_target, SDL_Texture *t_texture)
: Puzzle(grid_width, render_target)
{
    setTexture(t_texture);
}

Puzzle::Puzzle(SDL_Renderer *render_target)
: Puzzle()
{
    setRender_target(render_target);
}

Puzzle::Puzzle(SDL_Renderer *render_target, SDL_Texture *t_texture)
: Puzzle (render_target)
{
    setTexture(t_texture);
}

void Puzzle::InitGlobal()
{
    renderer = NULL;
    texture = NULL;
    status = PREPARE;
}

void Puzzle::InitObject(int grid_width)
{
    board = new Puzzle_board(grid_width);
    tiles = std::vector <Puzzle_tile*> (grid_width*grid_width, NULL);

    for (int i=0; i<grid_width*grid_width; i++) 
        tiles[i] = new Puzzle_tile(i);

    fullpuzzle = new Display_fullsize_object(PUZZLE_ORIGIN_X,PUZZLE_ORIGIN_Y
                                                , PUZZLEZONE, PUZZLEZONE);
    timer = new Timer;

    text_renderer = new Text_rendering;
    showIndex = false;
}


void Puzzle::setTexture(SDL_Texture* t_texture)
{
    texture = t_texture;
    fullpuzzle->loadTexture(texture);
    for (int i=0; i<board->tiles_num(); i++) tiles[i]->loadTexture(texture);
    splitPicture();
}

void Puzzle::setRender_target(SDL_Renderer *render_target)
{
    renderer = render_target;
    fullpuzzle->setRender_target(renderer);
    for (int i=0; i<board->tiles_num(); i++) tiles[i]->setRender_target(renderer);
    text_renderer->setRender_target(renderer);
}

void Puzzle::setFont(TTF_Font *t_timer_font, TTF_Font *t_tile_font)
{
    puzzle_general_font = t_timer_font;
    text_renderer->setFont(puzzle_general_font);

    tileFont = t_tile_font;
    for (auto u: tiles) u->setFont(tileFont);
}

void Puzzle::blitPuzzle()
{
    if (status != GOAL)
    {
        fullpuzzle->blit(48,48,48);
    
        SDL_SetRenderDrawColor(renderer, 0, 0 ,0 ,255);
        for (int i=1; i<board->tiles_num(); i++)
        {
            tiles[i]->blit();
            if (showIndex) tiles[i]->blitNumber();
            tiles[i]->drawBorder();
        }
    }
    else fullpuzzle->blit(); 
}

void Puzzle::blitTimer()
{
    text_renderer->renderText("TIME", 1025, 30);
    int second, minute, jiffy;
    std::string text;
    jiffy = timer->getSecondMinute_fomant_jiffy();
    second = timer->getSecondMinute_fomant_second();
    minute = timer->getSecondMinute_fomant_minute();

    text += (minute >= 10) ? (std::to_string(minute)) : ('0'+std::to_string(minute));
    text += (second >= 10) ? (':' + std::to_string(second)) : (":0" + std::to_string(second));
    text += (jiffy >= 10) ? (':' + std::to_string(jiffy)) : ( ":0" + std::to_string(jiffy));

    text_renderer->renderText(text, 1025, 70);
}

void Puzzle::blit()
{
    blitPuzzle();
    fullpuzzle->drawBorder();
    blitTimer();    
}

void Puzzle::updateTilesPos(bool SlideEffect)
{
    for (int i=0; i<board->getGrid_width(); i++)
        for (int j=0; j<board->getGrid_width(); j++)
            {
                int posX = (j*(PUZZLEZONE/board->getGrid_width()) + PUZZLE_ORIGIN_X);
                int posY = (i*(PUZZLEZONE/board->getGrid_width()) + PUZZLE_ORIGIN_Y);

                if (SlideEffect)
                    tiles[board->getIndex(i,j)]->moveTo(posX,posY);
                else
                    tiles[board->getIndex(i,j)]->setDestination_Structure_Position(posX,posY);
            }
    
}

void Puzzle::updatePuzzle()
{
    updateTilesPos(true);
    if (isGoal()) 
    {
        timer->pause();
        status = GOAL;
    }
}

void Puzzle::splitPicture() 
{
    int t_height,t_width;
    SDL_QueryTexture(texture, NULL, NULL, &t_width,&t_height);
    
    t_height/=board->getGrid_width();
    t_width/=board->getGrid_width();
    for (int i=0; i<board->getGrid_width(); i++)
        for (int j=0; j<board->getGrid_width(); j++)   
        {
            int index = (i*board->getGrid_width()+j+1)%board->tiles_num();

            tiles[index]->setSource_Structure_Position(j * t_width,i * t_height);
            tiles[index]->setSource_Structure_Size(t_width,t_height);

            updateTilesPos(0);
            
            tiles[index]->setDestination_Structure_Size(PUZZLEZONE/board->getGrid_width(), PUZZLEZONE/board->getGrid_width());
        }      
}

Puzzle::~Puzzle()
{
    destroy();
}

void Puzzle::destroy()
{
    delete board;
    delete fullpuzzle;
    delete text_renderer;
    renderer = NULL;
    texture = NULL;
    puzzle_general_font = NULL;
    tileFont = NULL;

    for (auto x:tiles) delete x;
    tiles.clear();
}

bool Puzzle::MouseProcess(const int x,const int y,const bool clicked)
{
    if (hitBoxCheck(x, y, PUZZLE_ORIGIN_X, PUZZLE_ORIGIN_Y
                    , PUZZLEZONE, PUZZLEZONE))
            {
                int j = (x-PUZZLE_ORIGIN_X)*board->getGrid_width()/PUZZLEZONE;
                int i = (y-PUZZLE_ORIGIN_Y)*board->getGrid_width()/PUZZLEZONE;
                if (clicked && !board->isGoal())
                {
                    if (board->move(i,j))
                    {   
                        play();
                        return 1;
                    }
                }
            }
    return 0;
}

void Puzzle::play()
{
    if (status == PREPARE)
        {
            timer->start();
            status = PLAYING;
        } 
}
void Puzzle::suffer()
{
    board->suffer();
    timer->stop();
    updateTilesPos(true);
    status = PREPARE;
}

void Puzzle::resize(int grid)
{
    board->resize(grid);
    for (auto x:tiles) delete x;
    
    tiles = std::vector <Puzzle_tile*> (grid*grid, NULL);

    for (int i=0; i<grid*grid; i++) 
        tiles[i] = new Puzzle_tile(renderer, texture, i, tileFont);

    splitPicture();
    suffer();
}

bool Puzzle::isGoal()
{
    if (!board->isGoal()) 
        return false;
    
    for (int i=0; i<board->getGrid_width(); i++)
        for (int j=0; j<board->getGrid_width(); j++)
            {
                int posX = (j*(PUZZLEZONE/board->getGrid_width()) + PUZZLE_ORIGIN_X);
                int posY = (i*(PUZZLEZONE/board->getGrid_width()) + PUZZLE_ORIGIN_Y);

                if (!tiles[board->getIndex(i,j)]->isMatchPosition(posX, posY)) 
                    return false;
            }
    
    return true;
}

bool Puzzle::show_hide_number()
{
    showIndex = !showIndex;
    return showIndex;
}

bool Puzzle::MovementProcess(const bool up, const bool down, const bool left, const bool right)
{
    bool moved = 0;
    if (up) moved = moved || board->move(BOARD_KEY_UP);
    if (down) moved = moved || board->move(BOARD_KEY_DOWN);
    if (left) moved = moved ||  board->move(BOARD_KEY_LEFT);
    if (right) moved = moved ||  board->move(BOARD_KEY_RIGHT);

    if (moved) play();

    return moved;
}