#ifndef H_BUTTON
#define H_BUTTON

#include "base.h"
#include "base_object.h"
#include "destination_structure.h"
#include "event.h"

class Button : public Base_object, public Destination_structure
{
private:
public:
    Button();
    Button(SDL_Renderer *render_target);
    Button(SDL_Renderer *render_target, std::string filename);
    Button(int x,int y,int w, int h);
    Button(SDL_Renderer *render_target, std::string filename,int x,int y,int w,int h);
    ~Button();
    void Init();
    void blit();
    void SetAlphaMod(const int a);
    bool checkHitBox(int x,int y);
    void loadTexture(std::string filename);
    SDL_Texture* getTexture();
    void destroy();
};

#endif