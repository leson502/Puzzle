#ifndef H_TEXT_RENDERING
#define H_TEXT_RENDERING

#include "base.h"

class Text_rendering
{
private:
    SDL_Renderer *renderer;
    TTF_Font *font;
    SDL_Color render_color;
    float scale;
public:
    Text_rendering();
    Text_rendering(SDL_Renderer *render_target, TTF_Font *t_font);
    ~Text_rendering();
    void Init();
    void destroy();
    void setFont(TTF_Font *t_font);
    void setRendering_color(int r,int g,int b,int a);
    void setRender_target(SDL_Renderer *render_target);
    SDL_Texture *getTextureFromSurface(SDL_Surface *surface, bool free_surface);
    SDL_Texture *getTextureFromText(std::string &text);
    SDL_Surface *getSurfaceFromText(std::string &text);
    void renderTexture(SDL_Texture *texture, SDL_Rect *dstrect);
    void renderText(std::string text, int x,int y);
    void rendetText_mid_of(std::string text, int x,int y, int w, int h);
    void setScale(float t_scale);
};


#endif