#include "bar_tile.h"

Bar_tile::Bar_tile()
{
    Init();
}
Bar_tile::Bar_tile(SDL_Renderer *render_target) 
: Bar_tile()
{
    setRender_target(render_target);
}
Bar_tile::Bar_tile(SDL_Renderer *render_target, std::string filename)
: Bar_tile(render_target)
{
    loadTexture(filename);
}
Bar_tile::Bar_tile(SDL_Renderer *render_target, std::string filename,int x,int y,int w,int h)
: Bar_tile(render_target, filename)
{
    setDestination_Structure_Position(x,y);
    setDestination_Structure_Size(w,h);
}

Bar_tile::Bar_tile(int x,int y,int w, int h)
: Bar_tile()
{
    setDestination_Structure_Position(x,y);
    setDestination_Structure_Size(w,h);
}

Bar_tile::~Bar_tile()
{
    destroy();
}
void Bar_tile::Init()
{
    renderer = NULL;
    texture = NULL;
    dstrect = new SDL_Rect;
    BlitFlags = BAR_TILES_BLIT_NORMAL;
    clicked = 0;
}
void Bar_tile::blit()
{
    switch (BlitFlags)
    {
    case BAR_TILES_BLIT_NORMAL:
        SDL_RenderCopy(renderer, texture, NULL, dstrect);
        break;
    case BAR_TILES_BLIT_LARGE:
        setDestination_Structure_Position(dstrect->x-10, dstrect->y-10);
        setDestination_Structure_Size(dstrect->w+20, dstrect->h+20);
        
        SDL_RenderCopy(renderer, texture, NULL, dstrect);

        setDestination_Structure_Position(dstrect->x+10, dstrect->y+10);
        setDestination_Structure_Size(dstrect->w-20, dstrect->h-20);
    default:
        break;
    }
}
bool Bar_tile::checkHitBox(int x, int y)
{
    return hitBoxCheck(x, y, dstrect->x, dstrect->y, dstrect->w, dstrect->h);
}
SDL_Texture* Bar_tile::getTexture()
{
    return texture;
}

void Bar_tile::setBlitFlags(int Flags)
{
    
    if (Flags != BAR_TILES_BLIT_NORMAL && 
        Flags != BAR_TILES_BLIT_LARGE) return;
    BlitFlags = Flags;
}
void Bar_tile::loadTexture(std::string filename)
{
    texture = IMG_LoadTexture(renderer, filename.c_str());
}

void Bar_tile::destroy()
{
    renderer = NULL;
    SDL_DestroyTexture(texture);
    delete dstrect;
}

void Bar_tile::MouseProcess(const int x, const int y, const bool m_click)
{
    if (checkHitBox(x, y)) 
        {
            setBlitFlags(BAR_TILES_BLIT_LARGE);
            clicked = m_click;
        }
    else
        setBlitFlags(BAR_TILES_BLIT_NORMAL);
}

bool Bar_tile::isClicked()
{
    return clicked;
}