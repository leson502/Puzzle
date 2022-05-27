#ifndef H_PUZZLE_TILES
#define H_PUZZLE_TILES

#include "base.h"
#include "base_object.h"
#include "destination_structure.h"
#include "source_structure.h"
#include "text_rendering.h"

class Puzzle_tile : public Base_object, public Destination_structure, public Source_structure
{
private:
    int index;
    Text_rendering *text_renderer;
public:
    Puzzle_tile();
    ~Puzzle_tile();
    Puzzle_tile(SDL_Renderer *render_target);
    Puzzle_tile(int t_index);
    Puzzle_tile(SDL_Renderer *render_target, int t_index);
    Puzzle_tile(SDL_Renderer *render_target, SDL_Texture *t_texture);
    Puzzle_tile(SDL_Renderer *render_target, SDL_Texture *t_texture, int t_index);
    Puzzle_tile(SDL_Renderer *render_target, SDL_Texture *t_texture, int t_index, TTF_Font *t_font);
    void setFont(TTF_Font *t_font);
    void Init();
    void setRender_target(SDL_Renderer *render_target);
    void loadTexture(SDL_Texture *t_texture);
    void drawBorder();
    void blit();
    void blitNumber();
    void Destroy();
    void moveTo(int x,int y);
    bool isMatchPosition(int x,int y);
    void MakeVectorSpeed(int &vec);
    void setIndex(int i);
    SDL_Rect getSourceS();
    
};


#endif
