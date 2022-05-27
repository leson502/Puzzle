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
    m_key.reset();
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
        case SDL_KEYDOWN:
            doKeyDown(&event.key);
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

void Event::getMouseStatus(int &x, int &y, int &click)
{
    x = mouse_x;
    y = mouse_y;
    click = LbuttonDown;
}

void Event::doKeyDown(SDL_KeyboardEvent *event)
{
    if (event->repeat == 0)
	{
        switch (event->keysym.scancode)
        {
        case SDL_SCANCODE_UP:
            m_key.up = 1;
            break;
        case SDL_SCANCODE_DOWN:
            m_key.down = 1;
            break;
        case SDL_SCANCODE_LEFT:
            m_key.left = 1;
            break;
        case SDL_SCANCODE_RIGHT:
            m_key.right = 1;
            break;
        case SDL_SCANCODE_W:
            m_key.up = 1;
            break;
        case SDL_SCANCODE_S:
            m_key.down = 1;
            break;
        case SDL_SCANCODE_A:
            m_key.left = 1;
            break;
        case SDL_SCANCODE_D:
            m_key.right = 1;
            break;
        default:
            break;
        }
	}
}

Movement_key Event::getMovement()
{
    return m_key;
}

Movement_key::Movement_key()
{
    reset();
}

void Movement_key::reset()
{
    up = down = right = left = 0;
}