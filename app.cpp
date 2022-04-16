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
    std::string fontfilename = "font/Roboto-Light.ttf";
    graphic->InitSDL(SDL_WINDOW_SHOWN,SDL_RENDERER_ACCELERATED | 
                                SDL_RENDERER_PRESENTVSYNC, fontfilename);
}

void App::setPuzzle()
{
    puzzle = new Puzzle();
    leftbar = new PuzzleBar();
}

void App::loadPuzzleTexture()
{
    leftbar->loadObject(graphic->getRenderer());
    puzzle->setTexture(leftbar->GetNewTexture());
}

void App::loadBackground()
{
    std::string filename = "gfx/background.png";
    background = new Object;
    background->setPos(0,0);
    background->setSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    background->loadTexture(graphic->getRenderer(), filename);
}

void App::loadAllTexture()
{
    loadPuzzleTexture();
    loadBackground();
}

void App::updateRender()
{
    SDL_RenderClear(graphic->getRenderer());    

    background->blit(graphic->getRenderer());
    leftbar->Blit(graphic->getRenderer());
    puzzle->blitPuzzle(graphic->getRenderer(), 1);

    graphic->renderPresent();
}

void App::updatePuzzle()
{
    event->updateEvent();

    puzzle->MouseProcess(event->MousePosX(),event->MousePosY(),event->isLbuttonDown());
    if ( leftbar->MouseProcess(event->MousePosX(),event->MousePosY(),event->isLbuttonDown()) )
        puzzle->setTexture(leftbar->GetNewTexture());
    puzzle->updateTilesPos();
}

void App::appLoop()
{
    while (!event->isQuit())
    {
        updateRender();
        updatePuzzle();
        SDL_Delay(16);
    }
}

void App::AppQuit()
{
    delete puzzle;
    delete event;
    delete graphic;
    delete background;
    delete leftbar;
}

void App::Play()
{
    puzzle->Suffer();
    appLoop();
}
App::~App()
{
    AppQuit();
}