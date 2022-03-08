#include "graphic.h"
#include "tiles.h"
#include "puzzle.h"
#include "event.h"
class App
{
private:
    Graphic *graphic;
    Tiles *tiles;
    Puzzle *puzzle;
    Event *event;
public:
    App();
    ~App();
    void defaultApp();
    void setTiles();
    void setGraphic();
    void setPuzzle();
    void updateRender();
    void updatePuzzle();
    void appLoop();
    void AppQuit();
};


