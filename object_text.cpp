#include "object_text.h"


Text_object::Text_object()
{
    default_object();
}

void Text_object::default_object()
{
    renderer = NULL;
    texture = NULL;
    font = NULL;
    rect = new SDL_Rect;
}

void Text_object::destroy_object()
{
    renderer = NULL;
    SDL_DestroyTexture(texture);
    font = NULL;
    delete rect;
}

void Text_object::setFont(TTF_Font *_font)
{
    font = _font;
}

void Text_object::createTexture(std::string &text)
{
    SDL_Color color;
    setColor(&color,255,255,255,255);
        
    SDL_Surface *surface = TTF_RenderUTF8_Blended(font, text.c_str(), color);

    texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_FreeSurface(surface);
}

Text_object::~Text_object()
{
    destroy_object();
}