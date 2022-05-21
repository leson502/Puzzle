#include "puzzlebar.h"

PuzzleBar::PuzzleBar()
{
    Init();
}

PuzzleBar::PuzzleBar(SDL_Renderer *render_target)
: PuzzleBar()
{
    setRender_target(render_target);
}

void PuzzleBar::Init()
{
    renderer = NULL;
    UpButton = new Button(UPBUTTON_X, UPBUTTON_Y, BUTTON_W, BUTTON_H);
    DownButton = new Button(DOWNBUTTON_X, DOWNBUTTON_Y, BUTTON_W, BUTTON_H);
    background = new Display_fullsize_object(BAR_ORIGIN_X, BAR_ORIGIN_Y, BAR_WIDTH, BAR_HEIGHT);

    tiles = std::vector<Bar_tile*>(OBJECT_NUM, NULL);
    for (int i = 0; i<OBJECT_NUM; i++) 
        tiles[i] = new Bar_tile;
    top = 0;
    current = 0;
}


void PuzzleBar::loadTexture()
{
    std::string filename;
    for (int i = 1; i<=OBJECT_NUM; i++)
        tiles[i-1]->loadTexture("gfx/puzzle" + std::to_string(i) +".png");
        

    UpButton->loadTexture("gfx/uparrow.png");
    DownButton->loadTexture("gfx/downarrow.png");
    background->loadTexture("gfx/background.png");
}

void PuzzleBar::setRender_target(SDL_Renderer *render_target)
{
    renderer = render_target;
    UpButton->setRender_target(renderer);
    DownButton->setRender_target(renderer);
    background->setRender_target(renderer);

    for (int i = 0; i<OBJECT_NUM; i++) 
        tiles[i]->setRender_target(renderer);
}

void PuzzleBar::blit()
{
    background->blit();
    for(int i=0; i<DISPLAY_OBJECT_NUM; i++)
        {
            tiles[i+top]->setDestination_Structure_Position(BAR_ORIGIN_X+10,BAR_ORIGIN_Y+i*BAR_WIDTH+10);
            tiles[i+top]->setDestination_Structure_Size(BAR_WIDTH-20, BAR_WIDTH-20);
            tiles[i+top]->blit();
        }
    
    UpButton->blit();
    DownButton->blit();

    SDL_SetRenderDrawColor(renderer,166,42,42,255);
    background->drawBorder();

}

void PuzzleBar::move(int x)
{
    top=std::max(std::min(int(top+x),int(OBJECT_NUM-DISPLAY_OBJECT_NUM)),0);
}

bool PuzzleBar::MouseProcess(const int x, const int y, const bool clicked)
{
    if (UpButton->checkHitBox(x, y))
    {
        UpButton->SetAlphaMod(64);
        if (clicked) move(-1);
    }
    else UpButton->SetAlphaMod(255);

    if (DownButton->checkHitBox(x, y))
    {
        DownButton->SetAlphaMod(64);
        if (clicked) move(1);
    }
    else DownButton->SetAlphaMod(255);
    if (hitBoxCheck(x,y, BAR_ORIGIN_X, BAR_ORIGIN_Y, BAR_WIDTH, BAR_WIDTH*3))
        {
            int i = (y-BAR_ORIGIN_Y)/BAR_WIDTH;
            if (clicked)
            {
                current = i + top;
                return 1;
            }
        }
    return 0;
}

SDL_Texture *PuzzleBar::GetNewTexture()
{
    return tiles[current]->getTexture();
}

PuzzleBar::~PuzzleBar()
{
    
}

