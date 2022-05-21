#ifndef H_DISPLAY_FULLSIZE_OBJECT
#define H_DISPLAY_FULLSIZE_OBJECT

#include "base.h"
#include "base_object.h"
#include "destination_structure.h"
class Display_fullsize_object: public Base_object, public Destination_structure
{
private:
public:
    Display_fullsize_object();
    Display_fullsize_object(int x,int y,int w,int h);
    Display_fullsize_object(SDL_Renderer *render_target);
    Display_fullsize_object(SDL_Renderer *render_target, std::string filename);
    Display_fullsize_object(SDL_Renderer *render_target, SDL_Texture *t_texture);
    Display_fullsize_object(SDL_Renderer *render_target, std::string filename, int x,int y,int w,int h);
    Display_fullsize_object(SDL_Renderer *render_target, SDL_Texture *t_texture, int x,int y,int w,int h);
    void Init();
    void loadTexture(std::string filename);
    void loadTexture(SDL_Texture *t_texture);
    void blit();
    void blit(int r,int g,int b);
    void drawBorder();
    void Destroy();
    ~Display_fullsize_object();
};

#endif