#include "base.h"

class Tiles
{
private:
    int x,y;
    SDL_Texture *texture;
public:
    Tiles();
    Tiles(int x,int y);
    Tiles(int posx,int posy,SDL_Texture *p_texture);
    void setPos(int posx,int posy);
    void setTexture(SDL_Texture *p_texture);
    int getPosx();
    int getPosy();
    SDL_Texture *getTexture();
};