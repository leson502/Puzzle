#ifndef H_APP
#define H_APP

#include "graphic.h"
#include "base_object.h"
#include "puzzle.h"
#include "event.h"
#include "puzzlebar.h"
#include "timer.h"
#include "media.h"
enum {
    SUFFER=0, PUZZLE_8=1, PUZZLE_15=2, PUZZLE_24=3, NUMBER_BUTTON = 4
};


class App
{
private:
    Graphic *graphic;
    Puzzle *puzzle;
    Event *event;
    PuzzleBar *leftbar;
    Display_fullsize_object *background;
    std::vector<Button*> buttonList;
    Timer *globalTimer;
    Game_Media *media;
public:
    App();
    ~App();
    void loadAllTexture();
    void loadObject();
    void InitObject();
    void InitGraphic();
    void InitMedia();
    void setPuzzle();
    void loadPuzzleTexture();
    void updateRender();
    void Update();
    void appLoop();
    void AppQuit();
    void Play();
};

#endif