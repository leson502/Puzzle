#ifndef H_APP
#define H_APP

#include "graphic.h"
#include "base_object.h"
#include "puzzle.h"
#include "event.h"
#include "puzzlebar.h"


class App
{
private:
    Graphic *graphic;
    Puzzle *puzzle;
    Event *event;
    PuzzleBar *leftbar;
    Display_fullsize_object *background;
    Button *Suffer;
public:
    App();
    ~App();
    void loadAllTexture();
    void loadObject();
    void InitObject();
    void InitGraphic();
    void setPuzzle();
    void loadPuzzleTexture();
    void updateRender();
    void updatePuzzle();
    void appLoop();
    void AppQuit();
    void Play();
};

#endif