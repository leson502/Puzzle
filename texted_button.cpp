#include "texted_button.h"

Texted_button::Texted_button()
{
    Init();
}

Texted_button::Texted_button(SDL_Renderer *render_target)
: Texted_button()
{
    setRender_target(render_target);
}   

Texted_button::Texted_button(SDL_Renderer *render_target, std::string filename)
: Texted_button(render_target)
{
    loadTexture(filename);
}

Texted_button::Texted_button(int x,int y,int w, int h)
: Texted_button()
{
    setDestination_Structure_Position(x,y);
    setDestination_Structure_Size(w,h);
}
Texted_button::Texted_button(SDL_Renderer *render_target, std::string filename,int x,int y,int w,int h)
: Texted_button(render_target, filename)
{
    setDestination_Structure_Position(x,y);
    setDestination_Structure_Size(w,h);
}

Texted_button::Texted_button(SDL_Renderer *render_target, std::string filename,int x,int y,int w,int h, std::string t_text)
: Texted_button(render_target, filename, x, y, w, h)
{
    setText(t_text);
}   

Texted_button::~Texted_button()
{
    destroy();
}

void Texted_button::Init()
{
    Button::Init();
    text_renderer = new Text_rendering;
    text.clear();
}
void Texted_button::setRender_target(SDL_Renderer *render_target)
{
    Button::setRender_target(render_target);
    text_renderer->setRender_target(render_target);
}

void Texted_button::setFont(TTF_Font *t_font)
{
    text_renderer->setFont(t_font);
}

void Texted_button::blit()
{
    Button::blit();
    if (hovered && hoverEffect == HOVERED_LARGER)
        text_renderer->setScale(1.033333);
    else    
        text_renderer->setScale(1.0);
    text_renderer->rendetText_mid_of(text, dstrect->x, dstrect->y, dstrect->w, dstrect->h);
}

void Texted_button::setTextColor(int r,int g,int b,int a)
{   
    text_renderer->setRendering_color(r,g,b,a);
}   

void Texted_button::setText(std::string t_text)
{
    text = t_text;
}

void Texted_button::destroy()
{
    Button::destroy();
    delete text_renderer;
}