#ifndef H_SOURCE_STRUCTURE
#define H_SOURCE_STRUCTURE

#include "base.h"

class Source_structure
{  
protected:
    SDL_Rect *srcrect;
public:
    Source_structure();
    Source_structure(int x,int y,int w,int h);
    void Init();
    void setSource_Structure_Position(int x,int y);
    void setSource_Structure_Size(int w,int h);
};


#endif