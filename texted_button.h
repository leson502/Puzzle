#ifndef H_TEXTED_BUTTON
#define H_TEXTED_BUTTON

#include "base.h"
#include "button.h"
#include "text_rendering.h"
class Texted_button: public Button
{
private:
    Text_rendering *text_renderer;
    std::string text;
public:
    Texted_button();
    Texted_button(SDL_Renderer *render_target);
    Texted_button(SDL_Renderer *render_target, std::string filename);
    Texted_button(int x,int y,int w, int h);
    Texted_button(SDL_Renderer *render_target, std::string filename,int x,int y,int w,int h);
    Texted_button(SDL_Renderer *render_target, std::string filename,int x,int y,int w,int h, std::string t_text);
    ~Texted_button();
    void setFont(TTF_Font *t_font);
    void setText(std::string t_text);
    void Init();
    void destroy();
    void blit();
    void setRender_target(SDL_Renderer *render_target);
    void setTextColor(int r,int g,int b,int a);
    
};



#endif