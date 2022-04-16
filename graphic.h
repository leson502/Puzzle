#ifndef H_GRAPHIC
#define H_GRAPHIC

#include "base.h"

class Graphic
{
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    TTF_Font *mainFont;
public:
    Graphic();
    ~Graphic();
    void DefaultGraphic();
    SDL_Window *getWindow();
    SDL_Renderer *getRenderer();
    void InitSDL(unsigned int windowFlags,
            unsigned int rendererFlags, std::string &fontfilename);
    void QuitSDL();
    SDL_Texture *loadTexture(const std::string& filename);
    void DrawTexture(SDL_Texture *texture, int x, int y);
    void renderPresent();
};

#endif