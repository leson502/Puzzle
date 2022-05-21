#ifndef H_PUZZLE_TILES
#define H_PUZZLE_TILES

#include "base.h"
#include "base_object.h"
#include "destination_structure.h"
#include "source_structure.h"

class Puzzle_tile : public Base_object, public Destination_structure, public Source_structure
{
public:
    Puzzle_tile();
    ~Puzzle_tile();
    Puzzle_tile(SDL_Renderer *render_target);
    Puzzle_tile(SDL_Renderer *render_target, SDL_Texture *t_texture);
    void Init();
    void loadTexture(SDL_Texture *t_texture);
    void drawBorder();
    void blit();
    void Destroy();
    SDL_Rect getSourceS();
    
};


#endif
