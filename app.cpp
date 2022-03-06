#include "app.h"

App::App()
{
    defaultApp();
}

void App::defaultApp()
{
    setGraphic();
    setPuzzle();
    setTiles();
}

void App::setGraphic()
{
    Graphic *p_graphic = new Graphic;
    graphic = p_graphic;
    graphic->InitSDL(SDL_WINDOW_SHOWN,SDL_RENDERER_ACCELERATED | 
                                SDL_RENDERER_PRESENTVSYNC);
}

void App::setTiles()
{
    Tiles *p_tiles= new Tiles[TILES_NUM];
    tiles = p_tiles;
    std::string filename = "gfx/num_.png";
    for (char i='0';i<'9';i++) 
    {
        filename[7]=i;
        tiles[i-'0'].setTexture(graphic->loadTexture(filename));
    }
    for (int i=0; i<PUZZLE_SIZE; i++)
        for (int j=0; j<PUZZLE_SIZE; j++)
            tiles[puzzle->getIndex(i,j)].setPos(j*BLOCKSIZE,i*BLOCKSIZE);

}

void App::setPuzzle()
{
    Puzzle *p_puzzle = new Puzzle();
    puzzle = p_puzzle;
}

void App::updatePresent()
{
    for (int i=0; i<TILES_NUM; i++)
        graphic->DrawTexture(tiles[i].getTexture(),
                            tiles[i].getPosx(),tiles[i].getPosy());
    graphic->renderPresent();
}