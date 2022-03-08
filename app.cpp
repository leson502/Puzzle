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
    event = new Event();
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

void App::updateRender()
{
    for (int i=0; i<PUZZLE_SIZE; i++)
        for (int j=0; j<PUZZLE_SIZE; j++)
            tiles[puzzle->getIndex(i,j)].setPos(j*BLOCKSIZE,i*BLOCKSIZE);
    for (int i=0; i<TILES_NUM; i++)
        graphic->DrawTexture(tiles[i].getTexture(),
                            tiles[i].getPosx(),tiles[i].getPosy());
    graphic->renderPresent();
}

void App::updatePuzzle()
{
    event->updateEvent();
    if (event->isLbuttonDown())
    {
        int j = event->MousePosX()/BLOCKSIZE;
        int i = event->MousePosY()/BLOCKSIZE;
        puzzle->move(i,j);
    }
}

void App::appLoop()
{
    while (true)
    {
        updatePuzzle();
        updateRender();
        if (event->isQuit()) 
            break;
        SDL_Delay(16);
    }
}

void App::AppQuit()
{
    delete tiles;
    delete puzzle;
    delete event;
    delete graphic;
}

App::~App()
{
    AppQuit();
}
