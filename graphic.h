#ifndef H_GRAPHIC
#define H_GRAPHIC

#include "base.h"

class Graphic
{
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
public:
    Graphic();
    ~Graphic();
    void DefaultGraphic();
    SDL_Window *getWindow();
    SDL_Renderer *getRenderer();
    void InitSDL(unsigned int windowFlags, unsigned int rendererFlags);
    void QuitSDL();
    void renderPresent();
};

#endif