#ifndef H_EVENT
#define H_EVENT

#include "base.h"

struct Movement_key
{
    bool up, down, left, right;
    Movement_key();
    void reset();
};

class Event
{
private:
    int mouse_x, mouse_y;
    bool LbuttonDown;
    bool App_quit; 
    Movement_key m_key;
public:
    Event();
    void updateEvent();
    void Init();
    void doMouseButtonDown(SDL_MouseButtonEvent *event);
    int MousePosX();
    int MousePosY();
    bool isLbuttonDown();
    bool isQuit();
    void doKeyDown(SDL_KeyboardEvent *event);
    void getMouseStatus(int &x, int &y, int &click);
    Movement_key getMovement();
};
 
#endif