#include "event.h"

Event::Event()
{
    Init();
}
void Event::Init()
{
    SDL_GetMouseState(&mouse_x,&mouse_y);
    App_quit = 0;
    LbuttonDown = 0;
}
void Event::updateEvent()
{
    SDL_Event event;
    SDL_GetMouseState(&mouse_x,&mouse_y);
    LbuttonDown = 0;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            App_quit = 1;
            break;
        case SDL_MOUSEBUTTONDOWN:
            doMouseButtonDown(&event.button);
            break;
        default:
            break;
        }
    } 
}

void Event::doMouseButtonDown(SDL_MouseButtonEvent *event)
{

   switch (event->button)
   {
   case SDL_BUTTON_LEFT:
       LbuttonDown = 1;
       break;
   default:
       break;
   }
}

bool Event::isLbuttonDown()
{
    return LbuttonDown;
}

int Event::MousePosX()
{
    return mouse_x;
}

int Event::MousePosY()
{
    return mouse_y;
}

bool Event::isQuit()
{
    return App_quit;
}