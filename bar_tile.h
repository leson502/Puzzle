#ifndef H_BAR_TILE
#define H_BAR_TILE

#include "base.h"
#include "base_object.h"
#include "destination_structure.h"

enum {
    BAR_TILES_BLIT_NORMAL = 0,
    BAR_TILES_BLIT_LARGE = 1
};

class Bar_tile : public Base_object, public Destination_structure
{
private:
    int BlitFlags;
    bool clicked;
public:
    Bar_tile();
    Bar_tile(SDL_Renderer *render_target);
    Bar_tile(SDL_Renderer *render_target, std::string filename);
    Bar_tile(int x,int y,int w, int h);
    Bar_tile(SDL_Renderer *render_target, std::string filename,int x,int y,int w,int h);
    ~Bar_tile();
    void Init();
    void blit();
    bool checkHitBox(const int x,const int y);
    void loadTexture(std::string filename);
    void setBlitFlags(const int Flags);
    bool isClicked();
    void MouseProcess(const int x, const int y, const bool m_click);
    SDL_Texture* getTexture();
    void destroy();
};



#endif