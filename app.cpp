#include "app.h"

App::App()
{
    InitGraphic();
    InitObject();
}

void App::InitObject()
{
    event = new Event;
    leftbar = new PuzzleBar(graphic->getRenderer());
    leftbar->loadTexture();
    puzzle = new Puzzle(6, graphic->getRenderer(), leftbar->GetNewTexture());
    loadObject();

}

void App::InitGraphic()
{
    graphic = new Graphic;
    graphic->InitSDL(SDL_WINDOW_SHOWN,SDL_RENDERER_ACCELERATED | 
                                SDL_RENDERER_PRESENTVSYNC, "font/Roboto-Light.ttf");
}

void App::loadObject()
{
    background = new Display_fullsize_object(graphic->getRenderer(),"gfx/background.jpg", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    Suffer = new Button(graphic->getRenderer(), "gfx/suffer.png",1025,480, 200,50);
}

void App::loadAllTexture()
{
    loadObject();
}

void App::updateRender()
{
    SDL_RenderClear(graphic->getRenderer());    

    background->blit();
    leftbar->blit();
    puzzle->blit(1);
    Suffer->blit();

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
                    1125-100, 480, 200, 50) && event->isLbuttonDown()) puzzle->suffer();
    
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
    puzzle->suffer(); 
    appLoop();
}

App::~App()
{
    AppQuit();
}