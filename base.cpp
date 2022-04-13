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

void swap(int *A, int *B)
{
    int temp = *A;
    *A = *B;
    *B = temp;
}

int max(const int A, const int B)
{
    return (A>B) ? A : B;
}

int min(const int A, const int B)
{
    return (A>B) ? B : A;
}

void setRect(SDL_Rect* rect,const int x, const int y, const int w, const int h)
{
    rect->x = x;
    rect->y = y;
    rect->w = w;
    rect->h = h;
}