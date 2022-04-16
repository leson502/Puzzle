#include "graphic.h"

Graphic:: Graphic()
{
   DefaultGraphic();
}

void Graphic::DefaultGraphic()
{
    window = NULL;
    renderer = NULL;
    mainFont = NULL;
}

SDL_Window*  Graphic:: getWindow(){
    return window;
}
SDL_Renderer* Graphic:: getRenderer()
{
    return renderer;
}
void Graphic:: InitSDL(unsigned int windowFlags,
            unsigned int rendererFlags, std::string &fontfilename)
{
   if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logSDLerror(std::cout, "SDL Init",1);
    
    window = SDL_CreateWindow(WINDOW_TITTLE, SDL_WINDOWPOS_CENTERED, 
            SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);
    if (window == NULL)
        logSDLerror(std::cout, "SDL create window", 1); 
    
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear"); 

    renderer = SDL_CreateRenderer(window, -1, rendererFlags);
    if (renderer == NULL)
        logSDLerror(std::cout, "SDL create renderer", 1); 

    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

    if (TTF_Init() < 0) 
        SDL_Log("%s", TTF_GetError());
    mainFont = TTF_OpenFont(fontfilename.c_str(), FONT_SIZE);
}

void Graphic:: QuitSDL()
{
    SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}


SDL_Texture *Graphic::loadTexture(const std::string& filename)
    {
        SDL_Texture *texture;

        texture = IMG_LoadTexture(renderer , filename.c_str());
    
        return texture;
    }

void Graphic::DrawTexture(SDL_Texture *texture, int x,int y)
{
    SDL_Rect dest;

    dest.x = x;
    dest.y = y;
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

    SDL_RenderCopy(renderer, texture, NULL, &dest);
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