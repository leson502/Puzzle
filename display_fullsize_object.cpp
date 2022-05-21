#include "display_fullsize_object.h"

Display_fullsize_object::Display_fullsize_object()
{
    Init();
}

Display_fullsize_object::Display_fullsize_object(int x,int y, int w, int h)
: Display_fullsize_object()
{
    setDestination_Structure_Position(x,y);
    setDestination_Structure_Size(w,h);
}
Display_fullsize_object::Display_fullsize_object(SDL_Renderer *render_target)
: Display_fullsize_object()
{
    setRender_target(render_target);
}

Display_fullsize_object::Display_fullsize_object(SDL_Renderer *render_target, std::string filename)
: Display_fullsize_object(render_target)
{
    loadTexture(filename);
}

Display_fullsize_object::Display_fullsize_object(SDL_Renderer *render_target, SDL_Texture *texture)
: Display_fullsize_object(render_target)
{
    loadTexture(texture);
}

Display_fullsize_object::Display_fullsize_object(SDL_Renderer *render_target, SDL_Texture *t_texture, int x,int y,int w,int h)
: Display_fullsize_object(render_target, t_texture)
{
    setDestination_Structure_Position(x,y);
    setDestination_Structure_Size(w,h);
}

Display_fullsize_object::Display_fullsize_object(SDL_Renderer *render_target, std::string filename, int x,int y,int w,int h)
: Display_fullsize_object(render_target, filename)
{
    setDestination_Structure_Position(x,y);
    setDestination_Structure_Size(w,h);
}

void Display_fullsize_object::Init()
{
    texture = NULL;
    renderer = NULL;
    dstrect = new SDL_Rect;
}

void Display_fullsize_object::loadTexture(std::string filename)
{
    texture = IMG_LoadTexture(renderer, filename.c_str());
}

void Display_fullsize_object::loadTexture(SDL_Texture *t_texture)
{
    texture = t_texture;
}
void Display_fullsize_object::blit()
{
    SDL_RenderCopy(renderer, texture, NULL, dstrect);
}

void Display_fullsize_object::blit(int r,int g,int b)
{
    SDL_SetTextureColorMod(texture, r, g, b);
    SDL_RenderCopy(renderer, texture, NULL, dstrect);
    SDL_SetTextureColorMod(texture, 255, 255, 255); // default color mod
}

void Display_fullsize_object::drawBorder()
{
    SDL_RenderDrawRect(renderer,dstrect);
}

void Display_fullsize_object::Destroy()
{
    renderer = NULL;
    SDL_DestroyTexture(texture);
    delete dstrect;
}

Display_fullsize_object::~Display_fullsize_object()
{
    Destroy();
}