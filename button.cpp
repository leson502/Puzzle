#include "button.h"

Button::Button()
{
    Init();
}
Button::Button(SDL_Renderer *render_target) 
: Button()
{
    setRender_target(render_target);
}
Button::Button(SDL_Renderer *render_target, std::string filename)
: Button(render_target)
{
    loadTexture(filename);
}
Button::Button(SDL_Renderer *render_target, std::string filename,int x,int y,int w,int h)
: Button(render_target, filename)
{
    setDestination_Structure_Position(x,y);
    setDestination_Structure_Size(w,h);
}

Button::Button(int x,int y,int w, int h)
: Button()
{
    setDestination_Structure_Position(x,y);
    setDestination_Structure_Size(w,h);
}

Button::~Button()
{
    destroy();
}

void Button::Init()
{
    renderer = NULL;
    texture = NULL;
    dstrect = new SDL_Rect;
    clicked = 0;
}

void Button::blit()
{    
    SDL_RenderCopy(renderer, texture, NULL, dstrect);
}
void Button::SetAlphaMod(const int a)
{
    SDL_SetTextureAlphaMod(texture, a);
}

bool Button::checkHitBox(int x, int y)
{
    return hitBoxCheck(x, y, dstrect->x, dstrect->y, dstrect->w, dstrect->h);
}

void Button::loadTexture(std::string filename)
{
    texture = IMG_LoadTexture(renderer, filename.c_str());
}

void Button::destroy()
{
    renderer = NULL;
    SDL_DestroyTexture(texture);
    delete dstrect;
}

void Button::MouseProcess(const int x, const int y, const bool m_click)
{
    if (checkHitBox(x,y)) 
    {
        SetAlphaMod(128);
        clicked = m_click;
    }   
    else 
        SetAlphaMod(255);
}

bool Button::isClicked()
{
    return clicked;
}