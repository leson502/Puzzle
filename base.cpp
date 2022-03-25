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
