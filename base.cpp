#include "base.h"


void logSDLerror(std::ostream &os,std::string msg, bool fatal)
{
    std::cout << msg <<"Error: " << SDL_GetError()<< std::endl;
    if (fatal)
    {
        SDL_Quit();
        exit(1);
    }
}

void logGeneralError(std::ostream &os,std::string msg, bool fatal)
{
    std::cout << msg << std::endl;
    if (fatal)
    {
        SDL_Quit();
        exit(1);
    }
}


void setRect(SDL_Rect* rect,const int x, const int y, const int w, const int h)
{
    rect->x = x;
    rect->y = y;
    rect->w = w;
    rect->h = h;
}

void setColor(SDL_Color *color, const int r, const int g, const int b, const int a)
{
    color->a = a;
    color->b = b;
    color->g = g;
    color->r = r;
}

bool hitBoxCheck(int x,int y,int X,int Y,int W,int H)
{
    return (X <= x && Y <= y &&
            (X + W) >= x && (Y+H) >=y);
}