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
    UpButton->setHoverEffect(1);

    DownButton = new Button(DOWNBUTTON_X, DOWNBUTTON_Y, BUTTON_W, BUTTON_H);
    UpButton->setHoverEffect(1);
    
    background = new Display_fullsize_object(BAR_ORIGIN_X, BAR_ORIGIN_Y, BAR_WIDTH, BAR_HEIGHT);

    tiles = std::vector<Bar_tile*>(OBJECT_NUM, NULL);
    for (int i = 0; i<OBJECT_NUM; i++) 
        tiles[i] = new Bar_tile;
    top = 0;
    current = NULL;
    currentChanged = 0;
}


void PuzzleBar::loadTexture()
{
    std::string filename;
    for (int i = 1; i<=OBJECT_NUM; i++)
        tiles[i-1]->loadTexture("gfx/puzzle" + std::to_string(i) +".png");
    
    current = tiles[0]->getTexture();

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

void PuzzleBar::updateTilesPos()
{
    for (int i=0; i<OBJECT_NUM; i++)
        {
            if (top<=i) 
            {
                tiles[i]->setDestination_Structure_Position(BAR_ORIGIN_X+10, BAR_ORIGIN_Y+(i-top)*BAR_WIDTH+10);
                tiles[i+top]->setDestination_Structure_Size(BAR_WIDTH-20, BAR_WIDTH-20);
            }
            else 
            {
                tiles[i]->setDestination_Structure_Position(-1,-1);
                tiles[i]->setDestination_Structure_Size(0,0);
            }
        }
}

void PuzzleBar::move(int x)
{
    top=std::max(std::min(int(top+x),int(OBJECT_NUM-DISPLAY_OBJECT_NUM)),0);
}

bool PuzzleBar::MouseProcess(const int x, const int y, const bool clicked)
{
    UpButton->MouseProcess(x, y, clicked);
    if (UpButton->isClicked()) move(-1);

    DownButton->MouseProcess(x, y, clicked);
    if (DownButton->isClicked()) move(1);
    
    for (int i=0 ;i<OBJECT_NUM; i++)
        tiles[i]->MouseProcess(x, y, clicked);

   /* if (hitBoxCheck(x,y, BAR_ORIGIN_X, BAR_ORIGIN_Y, BAR_WIDTH, BAR_WIDTH*3))
        {
            int i = (y-BAR_ORIGIN_Y)/BAR_WIDTH;
            if (clicked)
            {
                current = tiles[i + top]->getTexture();
                return 1;
            }
        }*/
    currentChanged = 0;

    for (int i=0; i<OBJECT_NUM; i++)
        if (tiles[i]->isClicked()) 
            {
                current = tiles[i]->getTexture();
                currentChanged = 1;
            }
    return 0;
}

bool PuzzleBar::isCurrentChanged()
{
    return currentChanged;
}
SDL_Texture *PuzzleBar::GetNewTexture()
{
    return current;
}

void PuzzleBar::destroy()
{
    renderer = NULL;
    delete UpButton;
    delete DownButton;
    delete background;

    for (int i=0; i<OBJECT_NUM; i++)
        delete tiles[i];
    tiles.clear();
}

PuzzleBar::~PuzzleBar()
{
    destroy();
}

