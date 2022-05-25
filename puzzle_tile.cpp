#include "puzzle_tile.h"

Puzzle_tile::Puzzle_tile()
{
    Init();
}

Puzzle_tile::Puzzle_tile(int t_index)
{
    Init();
    setIndex(t_index);
}

Puzzle_tile::~Puzzle_tile()
{
    Destroy();
}

Puzzle_tile::Puzzle_tile(SDL_Renderer *render_target)
{
    Init();
    setRender_target(render_target);
}

Puzzle_tile::Puzzle_tile(SDL_Renderer *render_target, SDL_Texture *t_texture)
: Puzzle_tile(render_target)
{
    loadTexture(t_texture);
}

Puzzle_tile::Puzzle_tile(SDL_Renderer *render_target, int t_index)
:Puzzle_tile(render_target)
{
    setIndex(t_index);
}

Puzzle_tile::Puzzle_tile(SDL_Renderer *render_target, SDL_Texture *t_texture, int t_index)
: Puzzle_tile(render_target, texture)
{
    setIndex(t_index);
}
void Puzzle_tile::Init()
{
    renderer = NULL;
    texture = NULL;
    dstrect = new SDL_Rect;
    srcrect = new SDL_Rect;
    index = 0;
}

void Puzzle_tile::loadTexture(SDL_Texture *t_texture)
{
    texture = t_texture;
}

void Puzzle_tile::setIndex(int i)
{
    index = i;
}

void Puzzle_tile::blit()
{
    SDL_RenderCopy(renderer, texture, srcrect, dstrect);
}

void Puzzle_tile::drawBorder()
{
    SDL_RenderDrawRect(renderer, dstrect);
}

void Puzzle_tile::Destroy()
{
    renderer = NULL;
    texture = NULL;
    delete dstrect;
    delete srcrect;
}

SDL_Rect Puzzle_tile::getSourceS()
{
    return *srcrect;
}

void Puzzle_tile::moveTo(int x,int y)
{
    int vecX = x-dstrect->x;
    int vecY = y-dstrect->y;

    MakeVectorSpeed(vecX);
    MakeVectorSpeed(vecY);

    setDestination_Structure_Position(dstrect->x + vecX, dstrect->y + vecY);
}

bool Puzzle_tile::isMatchPosition(int x,int y)
{
    return (dstrect->x == x && dstrect->y == y);
}

void Puzzle_tile::MakeVectorSpeed(int &vec)
{
     for (int div=5; div>1; div/=2)
        if (abs(vec)>=div) 
            {
                vec/=div;
                return;
            }
}