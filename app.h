#ifndef H_APP
#define H_APP

#include "graphic.h"
#include "base_object.h"
#include "puzzle.h"
#include "event.h"
#include "puzzlebar.h"
#include "timer.h"
#include "media.h"
#include "button.h"
#include "texted_button.h"

enum {
    SUFFER=0, PUZZLE_8=1, PUZZLE_15=2, PUZZLE_24=3, SHOW_HIDE_NUMBER=4, NUMBER_BUTTON = 5
};

enum{
    FONT_18, FONT_30, FONT_48, FONT_56
};

class App
{
private:
    Graphic *graphic;
    Puzzle *puzzle;
    Event *event;
    PuzzleBar *leftbar;
    Display_fullsize_object *background;
    std::vector<Texted_button*> buttonList;
    Timer *globalTimer;
    Game_Media *media;
    std::vector <TTF_Font*> fontList;
public:
    App();
    ~App();
    void loadAllTexture();
    void loadObject();
    void InitObject();
    void InitGraphic();
    void InitMedia();
    void setPuzzle();
    void loadFont();
    void loadPuzzleTexture();
    void updateRender();
    void Update();
    void appLoop();
    void AppQuit();
    void Play();
};

#endif