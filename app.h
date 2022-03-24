#ifndef APP__H
#define APP__H

#include "graphic.h"
#include "puzzle.h"
#include "event.h"

class App
{
private:
    Graphic *graphic;
    Puzzle *puzzle;
    Event *event;
    SDL_Texture *background;
public:
    App();
    ~App();
    void defaultApp();
    void setGraphic();
    void setPuzzle();
    void loadPuzzleTexture();
    void updateRender();
    void updatePuzzle();
    void appLoop();
    void AppQuit();
};

#endif
