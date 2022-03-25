#include "app.h"

App::App()
{
    defaultApp();
}

void App::defaultApp()
{
    setGraphic();
    setPuzzle();
    loadAllTexture();
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
}

void App::loadPuzzleTexture()
{
    std::string puzzlefiles ="gfx/puzzle1.png";
    puzzle->setTexture(graphic->loadTexture(puzzlefiles));
}

void App::loadAllTexture()
{
    loadPuzzleTexture();
    std::string filename = "gfx/background.png";
    background = new Object;
    background->setPos(0,0);
    background->setSize(SCREEN_WIDTH,SCREEN_HEIGHT);
    background->setTexture(graphic->loadTexture(filename));
}
void App::updateRender()
{
    SDL_RenderClear(graphic->getRenderer());    
    background->blit(graphic->getRenderer());
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
