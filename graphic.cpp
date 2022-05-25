#include "graphic.h"

Graphic:: Graphic()
{
   DefaultGraphic();
}

void Graphic::DefaultGraphic()
{
    window = NULL;
    renderer = NULL;
}

SDL_Window*  Graphic:: getWindow(){
    return window;
}

SDL_Renderer* Graphic:: getRenderer()
{
    return renderer;
}

void Graphic:: InitSDL(unsigned int windowFlags, unsigned int rendererFlags)
{
   if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logSDLerror(std::cout, "SDL Init",1);
    
    window = SDL_CreateWindow(WINDOW_TITTLE, SDL_WINDOWPOS_CENTERED, 
            SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);
    if (window == NULL)
        logSDLerror(std::cout, "SDL create window", 1); 
    
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"); 

    renderer = SDL_CreateRenderer(window, -1, rendererFlags);
    if (renderer == NULL)
        logSDLerror(std::cout, "SDL create renderer", 1); 

    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);


}

void Graphic:: QuitSDL()
{
    SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Graphic::renderPresent()
{
    SDL_RenderPresent(renderer);
}

Graphic::~Graphic()
{
    QuitSDL();
    DefaultGraphic();
}