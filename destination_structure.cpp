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

void Destination_structure::moveTo(int x,int y)
{
    int vecX = x-dstrect->x;
    int vecY = y-dstrect->y;

    MakeVectorSpeed(vecX);
    MakeVectorSpeed(vecY);

    setDestination_Structure_Position(dstrect->x + vecX, dstrect->y + vecY);
}

void Destination_structure::MakeVectorSpeed(int &vec)
{
     for (int div=3; div>1; div/=2)
        if (abs(vec)>=div) 
            {
                vec/=div;
                return;
            }
}