#ifndef H_DESTINATION_STRUCTURE
#define H_DESTINATION_STRUCTURE

#include "base.h"

class Destination_structure
{  
protected:
    SDL_Rect *dstrect;
public:
    Destination_structure();
    Destination_structure(int x,int y,int w,int h);
    void Init();
    void setDestination_Structure_Position(int x,int y);
    void setDestination_Structure_Size(int w,int h);
};


#endif