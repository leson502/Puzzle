#ifndef H_BAR_TILE
#define H_BAR_TILE

#include "base.h"
#include "base_object.h"
#include "destination_structure.h"

class Bar_tile : public Base_object, public Destination_structure
{
private:
public:
    Bar_tile();
    Bar_tile(SDL_Renderer *render_target);
    Bar_tile(SDL_Renderer *render_target, std::string filename);
    Bar_tile(int x,int y,int w, int h);
    Bar_tile(SDL_Renderer *render_target, std::string filename,int x,int y,int w,int h);
    ~Bar_tile();
    void Init();
    void blit();
    bool checkHitBox(int x,int y);
    void loadTexture(std::string filename);
    SDL_Texture* getTexture();
    void destroy();
};



#endif