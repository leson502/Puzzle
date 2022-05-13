#include "base_object.h"

Object::Object()
{
    Init();
}

Object::~Object()
{
    destroy_object();
}

void Object::Init()
{
    renderer = NULL;
    texture = NULL;
    rect = new SDL_Rect;
}

void Object::destroy_object()
{
    renderer = NULL;
    SDL_DestroyTexture(texture);
    delete rect;
}
void Object::setPos(int x,int y)
{
    rect->x = x;
    rect->y = y;
}

void Object::setSize(int w,int h)
{
    rect->w = w;
    rect->h = h;
}


void Object::blit()
{
    SDL_RenderCopy(renderer, texture, NULL, rect);
}

SDL_Texture *Object::getTexture()
{
    return texture;
}

void Object::loadTexture(std::string &filename)
{
    texture = IMG_LoadTexture(renderer, filename.c_str());
}

void Object::setRender_target(SDL_Renderer *render_target)
{
    renderer = render_target;
}

void Object::SetColorMod(int r,int g,int b)
{
    SDL_SetTextureColorMod(texture, r, g, b);
}

void Object::SetAlphaMod(int a)
{
    SDL_SetTextureAlphaMod(texture, a);
}