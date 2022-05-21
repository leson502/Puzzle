#include "source_structure.h"


Source_structure::Source_structure()
{
    Init();
}

Source_structure::Source_structure(int x,int y,int w,int h)
{
    setSource_Structure_Position(x, y);
    setSource_Structure_Size(w, h);
}

void Source_structure::Init()
{
    srcrect = new SDL_Rect;
}

void Source_structure::setSource_Structure_Position(int x,int y)
{
    srcrect->x = x;
    srcrect->y = y;
}

void Source_structure::setSource_Structure_Size(int w,int h)
{
    srcrect->w = w;
    srcrect->h = h;
}