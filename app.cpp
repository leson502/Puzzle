#include "app.h"

App::App()
{
    Init();
}

void App::Init()
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
                                SDL_RENDERER_PRESENTVSYNC, "font/Roboto-Light.ttf");
}

void App::setPuzzle()
{
    puzzle = new Puzzle();
    puzzle->setRender_target(graphic->getRenderer());

    leftbar = new PuzzleBar();
    leftbar->setRender_target(graphic->getRenderer());

    suffer = new Object();
    suffer->setRender_target(graphic->getRenderer());
}

void App::loadPuzzleTexture()
{
    leftbar->loadObject();
    puzzle->setTexture(leftbar->GetNewTexture());
}

void App::loadObject()
{
    std::string filename = "gfx/background.jpg";
    background = new Object;
    background->setRender_target(graphic->getRenderer());
    background->setPos(0,0);
    background->setSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    background->loadTexture(filename);
    background->SetColorMod(192,192,192);

    filename = "gfx/suffer.png";
    suffer->loadTexture(filename);
    suffer->setPos(1125-100,480);
    suffer->setSize(200,50);
}

void App::loadAllTexture()
{
    loadPuzzleTexture();
    loadObject();
}

void App::updateRender()
{
    SDL_RenderClear(graphic->getRenderer());    

    background->blit();
    leftbar->Blit();
    puzzle->blitPuzzle(1);
    suffer->blit();

    graphic->renderPresent();
}

void App::updatePuzzle()
{
    event->updateEvent();

    puzzle->MouseProcess(event->MousePosX(),event->MousePosY(),event->isLbuttonDown());
    if ( leftbar->MouseProcess(event->MousePosX(),event->MousePosY(),event->isLbuttonDown()) )
        puzzle->setTexture(leftbar->GetNewTexture());
        
    puzzle->updateTilesPos();
    if (hitBoxCheck(event->MousePosX(), event->MousePosY(), 
                    1125-100, 480, 200, 50) && event->isLbuttonDown()) puzzle->Suffer();
    
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