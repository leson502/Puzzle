#include "puzzle_tile.h"

Puzzle_tile::Puzzle_tile()
{
    Init();
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
{
    Init();
    setRender_target(render_target);
    loadTexture(t_texture);
}

void Puzzle_tile::Init()
{
    renderer = NULL;
    texture = NULL;
    dstrect = new SDL_Rect;
    srcrect = new SDL_Rect;
}

void Puzzle_tile::loadTexture(SDL_Texture *t_texture)
{
    texture = t_texture;
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