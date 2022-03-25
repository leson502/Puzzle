#ifndef H_APP
#define H_APP

#include "graphic.h"
#include "base_object.h"
#include "puzzle.h"
#include "event.h"

class App
{
private:
    Graphic *graphic;
    Puzzle *puzzle;
    Event *event;
    Object *background;
public:
    App();
    ~App();
    void loadAllTexture();
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
