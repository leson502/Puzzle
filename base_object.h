#ifndef H_BASE_OBJECT
#define H_BASE_OBJECT

#include "base.h"

class Object

{
protected:
    SDL_Texture *texture;
    SDL_Rect *rect;
    SDL_Renderer *renderer;
public:
    Object();
    ~Object();
    void Init();
    void setPos(int x,int y);
    void setSize(int w,int h);
    void loadTexture(std::string &filename);
    void setRender_target(SDL_Renderer *render_target);
    SDL_Texture *getTexture();
    SDL_Rect *getRect();
    void SetColorMod(int r,int g,int b);
    void SetAlphaMod(int a);
    void blit();
    void destroy_object();
};

#endif