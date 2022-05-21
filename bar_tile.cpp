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
}
void Bar_tile::blit()
{
    SDL_RenderCopy(renderer, texture, NULL, dstrect);
}
bool Bar_tile::checkHitBox(int x, int y)
{
    return hitBoxCheck(x, y, dstrect->x, dstrect->y, dstrect->w, dstrect->h);
}
SDL_Texture* Bar_tile::getTexture()
{
    return texture;
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