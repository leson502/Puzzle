#ifndef H_BASE_OBJECT
#define H_BASE_OBJECT

#include "base.h"

class Object

{
private:
    SDL_Texture *texture;
    SDL_Rect *rect;
public:
    Object();
    ~Object();
    void null_object();
    void setPos(int x,int y);
    void setSize(int w,int h);
    void loadTexture(SDL_Renderer *render_target, std::string &filename);
    SDL_Texture *getTexture();
    SDL_Rect *getRect();
    void blit(SDL_Renderer *render_target);
};

#endif