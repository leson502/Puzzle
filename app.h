#include "graphic.h"
#include "tiles.h"
#include "puzzle.h"

class App
{
private:
    Graphic *graphic;
    Tiles *tiles;
    Puzzle *puzzle;
public:
    App();
    void defaultApp();
    void setTiles();
    void setGraphic();
    void setPuzzle();
    void updatePresent();
};


