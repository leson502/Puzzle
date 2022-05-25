#include "app.h"

App::App()
{
    InitGraphic();
    InitMedia();
    InitObject();
}

void App::InitObject()
{
    event = new Event;
    leftbar = new PuzzleBar(graphic->getRenderer());
    leftbar->loadTexture();
    puzzle = new Puzzle(3, graphic->getRenderer(), leftbar->GetNewTexture());
    globalTimer = new Timer;
    buttonList = std::vector<Button*>(NUMBER_BUTTON, NULL);
    loadObject();
}

void App::InitGraphic()
{
    graphic = new Graphic;
    graphic->InitSDL(SDL_WINDOW_SHOWN,SDL_RENDERER_ACCELERATED | 
                                SDL_RENDERER_PRESENTVSYNC );
}

void App::InitMedia()
{
    media = new Game_Media();
    media->loadFont("font/Roboto-Light.ttf");
    media->insertChunk("sfx/effect/clack.wav");
}

void App::loadObject()
{
    background = new Display_fullsize_object(graphic->getRenderer(),"gfx/background.jpg", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    buttonList[SUFFER] = new Button(graphic->getRenderer(), "gfx/suffer.png",1025,480, 200,50);
    buttonList[PUZZLE_8] = new Button(graphic->getRenderer(), "gfx/button.png",1025,410, 200,50);
    buttonList[PUZZLE_15] = new Button(graphic->getRenderer(), "gfx/button.png",1025,410-70, 200,50);
    buttonList[PUZZLE_24] = new Button(graphic->getRenderer(), "gfx/button.png",1025,410-140, 200,50);
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

    if (puzzle->isGoal())
        puzzle->blit(0);
    else 
        puzzle->blit(1);
        
    for (auto u: buttonList) u->blit();

    graphic->renderPresent();
}

void App::Update()
{
    event->updateEvent();

    int mouse_x, mouse_y, mouse_click;
    event->getMouseStatus(mouse_x, mouse_y, mouse_click);

    if (puzzle->MouseProcess(mouse_x,mouse_y,mouse_click)) 
        media->playChunk(0);
    leftbar->MouseProcess(mouse_x,mouse_y,mouse_click);
    
    for (auto u: buttonList) 
        u->MouseProcess(mouse_x, mouse_y, mouse_click);
    
    if (leftbar->isCurrentChanged()) 
        puzzle->setTexture(leftbar->GetNewTexture());
        
    if (buttonList[SUFFER]->isClicked()) puzzle->suffer();
    if (buttonList[PUZZLE_8]->isClicked()) puzzle->resize(3);
    if (buttonList[PUZZLE_15]->isClicked()) puzzle->resize(4);
    if (buttonList[PUZZLE_24]->isClicked()) puzzle->resize(5);

    puzzle->updateTilesPos(true);
}

void App::appLoop()
{
    while (!event->isQuit())
    {
        globalTimer->start();
        updateRender();
        Update();
        unsigned int frameTicks = globalTimer->getTicks();
        if (frameTicks < TICKS_PER_FRAME)
            SDL_Delay(TICKS_PER_FRAME - frameTicks);
        globalTimer->stop();
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