#include "tiles.h"

Tiles::Tiles()
{
    setPos(-1,-1);
    setTexture(nullptr);
}

Tiles::Tiles(int posx,int posy)
{
    setPos(posx,posy);
}

Tiles::Tiles(int posx, int posy, SDL_Texture *p_texture)
{
    setPos(posx,posy);
    setTexture(p_texture);
}

void Tiles::setPos(int posx,int posy)
{
    x=posx;
    y=posy;
}

void Tiles::setTexture(SDL_Texture *p_texture)
{
    texture=p_texture;
}

int Tiles::getPosx()
{
    return x;
}

int Tiles::getPosy()
{
    return y;
}

SDL_Texture *Tiles::getTexture()
{
    return texture;
}