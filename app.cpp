#include "app.h"

App::App()
{
    defaultApp();
}

void App::defaultApp()
{
    setGraphic();
    setPuzzle();
    event = new Event();
}

void App::setGraphic()
{
    graphic = new Graphic;
    graphic->InitSDL(SDL_WINDOW_SHOWN,SDL_RENDERER_ACCELERATED | 
                                SDL_RENDERER_PRESENTVSYNC);
}

void App::setPuzzle()
{
    puzzle = new Puzzle();
    loadPuzzleTexture();
}

void App::loadPuzzleTexture()
{
    std::string puzzlefiles ="gfx/puzzle1/num_.png";
    std::vector<SDL_Texture*> _texture;
    for (int i = 0; i<TILES_NUM; i++) 
    {
        puzzlefiles[15] = i +'0';
        _texture.push_back(graphic->loadTexture(puzzlefiles));
    }
    puzzle->setTexture(_texture);
}

void App::updateRender()
{
    SDL_RenderClear(graphic->getRenderer());
    SDL_SetRenderDrawColor(graphic->getRenderer(), 96, 128, 255, 255);
    puzzle->blitPuzzle(graphic->getRenderer(), 1);
    graphic->renderPresent();
}

void App::updatePuzzle()
{
    event->updateEvent();
    if (event->isLbuttonDown())
    {
        int j = (event->MousePosX()-PUZZLE_ORIGIN_X)/BLOCKSIZE;
        int i = (event->MousePosY()-PUZZLE_ORIGIN_Y)/BLOCKSIZE;
        puzzle->move(i,j);
    }
}

void App::appLoop()
{
    while (true)
    {
        updateRender();
        updatePuzzle();
        if (event->isQuit()) 
            break;
        SDL_Delay(16);
    }
}

void App::AppQuit()
{
    delete puzzle;
    delete event;
    delete graphic;
}

App::~App()
{
    AppQuit();
}
