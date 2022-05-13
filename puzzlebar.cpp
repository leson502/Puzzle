#include "puzzlebar.h"

PuzzleBar::PuzzleBar()
{
    memAllocate();
    Init();
}
void PuzzleBar::memAllocate()
{
    border = new SDL_Rect;
    UpButton = new Object;
    DownButton = new Object;
    background = new Object;
}
void PuzzleBar::loadObject()
{
    std::string filename;
    for (int c = 1; c<=5; c++)
    {
        filename = "gfx/puzzle" + std::to_string(c) +".png";
        Object *object = new Object;
        object->setRender_target(renderer);
        object->loadTexture(filename);
        puzzlelist.push_back(object);
    }

    filename = "gfx/uparrow.png";
    UpButton->loadTexture(filename);

    filename = "gfx/downarrow.png";
    DownButton->loadTexture(filename);

    filename = "gfx/background.png";
    background->loadTexture(filename);

    top = 0;
    current = 0;
}
void PuzzleBar::Init()
{
    setRect(border,BAR_ORIGIN_X, BAR_ORIGIN_Y, BAR_WIDTH, BAR_HEIGHT);
    UpButton->setPos(UPBUTTON_X, UPBUTTON_Y);
    UpButton->setSize(BUTTON_W, BUTTON_H);

    DownButton->setPos(DOWNBUTTON_X, DOWNBUTTON_Y);
    DownButton->setSize(BUTTON_W, BUTTON_H);

    background->setPos(border->x, border->y);
    background->setSize(border->w, border->h);
    background->SetColorMod(128,128,128);
}

void PuzzleBar::Blit()
{
    background->blit();
    for(int i=0; i<DISPLAY_OBJECT_NUM; i++)
        {
            puzzlelist[i+top]->setPos(BAR_ORIGIN_X+10,BAR_ORIGIN_Y+i*BAR_WIDTH+10);
            puzzlelist[i+top]->setSize(BAR_WIDTH-20, BAR_WIDTH-20);
            puzzlelist[i+top]->blit();
        }
    
    UpButton->blit();
    DownButton->blit();
    SDL_SetRenderDrawColor(renderer,166,42,42,255);
    SDL_RenderDrawRect(renderer, border);

   /* SDL_RenderDrawLine(renderer, BAR_ORIGIN_X,BAR_ORIGIN_Y+BAR_WIDTH,
                        BAR_ORIGIN_X+BAR_WIDTH, BAR_ORIGIN_Y+BAR_WIDTH);
    SDL_RenderDrawLine(renderer, BAR_ORIGIN_X,BAR_ORIGIN_Y+BAR_WIDTH*2,
                        BAR_ORIGIN_X+BAR_WIDTH, BAR_ORIGIN_Y+BAR_WIDTH*2);*/
}

void PuzzleBar::move(int x)
{
    top=std::max(std::min(int(top+x),int(OBJECT_NUM-DISPLAY_OBJECT_NUM)),0);
}

bool PuzzleBar::MouseProcess(const int x, const int y, const bool clicked)
{
    if (hitBoxCheck(x, y, UPBUTTON_X, UPBUTTON_Y, BUTTON_W, BUTTON_H))
    {
        UpButton->SetAlphaMod(64);
        if (clicked) move(-1);
    }
    else UpButton->SetAlphaMod(255);
    if (hitBoxCheck(x, y, DOWNBUTTON_X, DOWNBUTTON_Y, BUTTON_W, BUTTON_H))
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
    return puzzlelist[current]->getTexture();
}

PuzzleBar::~PuzzleBar()
{
    delete border;
    for (Object* v:puzzlelist) delete v;
    puzzlelist.clear();
}

void PuzzleBar::setRender_target(SDL_Renderer *render_target)
{
    renderer = render_target;
    UpButton->setRender_target(renderer);
    DownButton->setRender_target(renderer);
    background->setRender_target(renderer);
}