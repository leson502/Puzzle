#include "text_rendering.h"

Text_rendering::Text_rendering()
{
    Init();
}

Text_rendering::Text_rendering(SDL_Renderer *render_target, TTF_Font *t_font)
: Text_rendering()
{
    setRender_target(render_target);
    setFont(t_font);
}

Text_rendering::~Text_rendering()
{
    destroy();
}

void Text_rendering::Init()
{
    font = NULL;
    renderer = NULL;
    setRendering_color(255,255,255,255); // default white
    scale = 1;
}

void Text_rendering::destroy()
{
    font = NULL;
    renderer = NULL;
}

void Text_rendering::setFont(TTF_Font *t_font)
{
    font = t_font;

    if (font == NULL)
        SDL_Log("Set font failed");
}

void Text_rendering::setRendering_color(int r,int g,int b, int a)
{
    render_color.r = r;
    render_color.g = g;
    render_color.b = b;
    render_color.a = a;
}

void Text_rendering::setRender_target(SDL_Renderer *render_target)
{
    renderer = render_target;
}

SDL_Texture *Text_rendering::getTextureFromSurface(SDL_Surface *surface, bool free_surface)
{
    SDL_Texture *texture;
    texture = SDL_CreateTextureFromSurface(renderer, surface);

    if (free_surface)
        SDL_FreeSurface(surface);

    return texture;
}

SDL_Texture *Text_rendering::getTextureFromText(std::string &text)
{
    SDL_Surface *surface;
    SDL_Texture *texture;
    surface = getSurfaceFromText(text);
    texture = getTextureFromSurface(surface, true);
    return texture;
}

SDL_Surface *Text_rendering::getSurfaceFromText(std::string &text)
{
    SDL_Surface *surface;
    surface = TTF_RenderUTF8_Blended(font, text.c_str() , render_color);
    return surface;
}

void Text_rendering::renderTexture(SDL_Texture *texture, SDL_Rect *dstrect)
{
    SDL_RenderCopy(renderer, texture, NULL, dstrect);
}

void Text_rendering::renderText(std::string text, int x,int y)
{
    SDL_Texture *texture = getTextureFromText(text);

    SDL_Rect dstrect;
    dstrect.x = x;
    dstrect.y = y;
    SDL_QueryTexture(texture, NULL, NULL, &dstrect.w, &dstrect.h);

    dstrect.w = int(float(dstrect.w)*scale);
    dstrect.h = int(float(dstrect.h)*scale);

    renderTexture(texture, &dstrect);

    SDL_DestroyTexture(texture);
}

void Text_rendering::rendetText_mid_of(std::string text, int x,int y, int w, int h)
{
    SDL_Texture *texture = getTextureFromText(text);
    
    SDL_Rect dstrect;
    SDL_QueryTexture(texture, NULL, NULL ,&dstrect.w, &dstrect.h);
    
    dstrect.w = int(float(dstrect.w)*scale);
    dstrect.h = int(float(dstrect.h)*scale);

    // Number rendering to midpoint of target
    dstrect.x = x + w/2 - dstrect.w/2;
    dstrect.y = y + h/2 - dstrect.h/2;
    
    renderTexture(texture, &dstrect);

    SDL_DestroyTexture(texture);
}


void Text_rendering::setScale(float t_scale)
{
    scale = t_scale;
}