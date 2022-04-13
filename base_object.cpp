#include "base_object.h"

Object::Object()
{
    null_object();
}

Object::~Object()
{
    null_object();
}
void Object::null_object()
{
    texture = nullptr;
    rect = new SDL_Rect;
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

void Object::setTexture(SDL_Texture *p_texture)
{
    texture = p_texture;
}

void Object::blit(SDL_Renderer *render_target)
{
    SDL_RenderCopy(render_target, texture, NULL, rect);
}

SDL_Texture *Object::getTexture()
{
    return texture;
}