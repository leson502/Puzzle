#include "puzzlebar.h"

PuzzleBar::PuzzleBar()
{
    memAllocate();
    defaultBar();
}
void PuzzleBar::memAllocate()
{
    border = new SDL_Rect;
    UpButton = new Object;
    DownButton = new Object;
}
void PuzzleBar::loadObject(SDL_Renderer *render_target)
{
    std::string filename = "gfx/puzzle_.png";
    for (char c = '1'; c<='5'; c++)
    {
        filename[10] = c;
        Object *object = new Object;
        object->loadTexture(render_target, filename);
        puzzlelist.push_back(object);
    }
    top = 0;
    current = 0;
}
void PuzzleBar::defaultBar()
{
    setRect(border,BAR_ORIGIN_X, BAR_ORIGIN_Y, BAR_WIDTH, BAR_HEIGHT);
}

void PuzzleBar::Blit(SDL_Renderer *render_target)
{
    
    for(int i=0; i<DISPLAY_OBJECT_NUM; i++)
        {
            puzzlelist[i+top]->setPos(BAR_ORIGIN_X,BAR_ORIGIN_Y+i*BAR_WIDTH);
            puzzlelist[i+top]->setSize(BAR_WIDTH, BAR_WIDTH);
            puzzlelist[i+top]->blit(render_target);
        }
    SDL_RenderDrawRect(render_target, border);
    SDL_RenderDrawLine(render_target, BAR_ORIGIN_X,BAR_ORIGIN_Y+BAR_WIDTH,
                        BAR_ORIGIN_X+BAR_WIDTH, BAR_ORIGIN_Y+BAR_WIDTH);
    SDL_RenderDrawLine(render_target, BAR_ORIGIN_X,BAR_ORIGIN_Y+BAR_WIDTH*2,
                        BAR_ORIGIN_X+BAR_WIDTH, BAR_ORIGIN_Y+BAR_WIDTH*2);
}

void PuzzleBar::move(int x)
{
    top=max(min(top+x,5),0);
}

bool PuzzleBar::MouseProcess(const int x, const int y, const bool clicked)
{
    if (x>= BAR_ORIGIN_X && y>= BAR_ORIGIN_Y &&
        x<= BAR_ORIGIN_X+BAR_WIDTH && y<= BAR_ORIGIN_Y+BAR_HEIGHT)
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