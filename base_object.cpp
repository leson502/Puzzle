#include "base_object.h"

Base_object::Base_object()
{
    Init();
}

Base_object::Base_object(SDL_Renderer *render_target)
{
    Init();
    setRender_target(render_target);
}

Base_object::~Base_object()
{
    Destroy();
}

void Base_object::Init()
{
    renderer = NULL;
    texture = NULL;
}

void Base_object::Destroy()
{
    renderer = NULL;
    SDL_DestroyTexture(texture);
}


void Base_object::setRender_target(SDL_Renderer *render_target)
{
    renderer = render_target;
}

