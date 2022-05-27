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
    hovered = 0;
    hoverEffect = HOVERED_NORMAL;
}

void Button::blit()
{    
    if (hovered) 
    {
        switch (hoverEffect)
        {
        case HOVERED_NORMAL:
        {
            SDL_RenderCopy(renderer, texture, NULL, dstrect);
            break;
        }
        case HOVERED_FADE:
        {
            SetAlphaMod(128);
            SDL_RenderCopy(renderer, texture, NULL, dstrect);
            SetAlphaMod(255);
            break;
        }
        case HOVERED_LARGER:
        {
            SDL_Rect t_dstrect = *dstrect;
            int delta_x = (t_dstrect.w)/30;
            int delta_y = (t_dstrect.h)/30;
            t_dstrect.x-=delta_x;
            t_dstrect.y-=delta_y;
            t_dstrect.w+= (2*delta_x);
            t_dstrect.h+= (2*delta_y);

            SDL_RenderCopy(renderer, texture, NULL, &t_dstrect);
            break;
        }
        default:
            break;
        }
    }
    else 
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
    hovered =  checkHitBox(x,y);
    clicked = (hovered && m_click);
}

bool Button::isClicked()
{
    return clicked;
}

bool Button::isHovered()
{
    return hovered;
}

void Button::setHoverEffect(int t_hoverEffect)
{
    hoverEffect = t_hoverEffect;
}