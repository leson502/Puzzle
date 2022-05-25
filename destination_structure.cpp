#include "destination_structure.h"


Destination_structure::Destination_structure()
{
    Init();
}

Destination_structure::Destination_structure(int x,int y,int w,int h)
{
    setDestination_Structure_Position(x, y);
    setDestination_Structure_Size(w, h);
}

void Destination_structure::Init()
{
    dstrect = new SDL_Rect;
}

void Destination_structure::setDestination_Structure_Position(int x,int y)
{
    dstrect->x = x;
    dstrect->y = y;
}

void Destination_structure::setDestination_Structure_Size(int w,int h)
{
    dstrect->w = w;
    dstrect->h = h;
}
