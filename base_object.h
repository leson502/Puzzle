#ifndef H_BASE_OBJECT
#define H_BASE_OBJECT

#include "base.h"

class Base_object
{
protected:
    SDL_Texture *texture;
    SDL_Renderer *renderer;
public:
    Base_object();
    Base_object(SDL_Renderer *render_target);
    ~Base_object();
    void Init();
    void setRender_target(SDL_Renderer *render_target);
    void Destroy();
};

#endif