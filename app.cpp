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
    puzzle->setFont(fontList[FONT_30], fontList[FONT_56]);
    globalTimer = new Timer;
    buttonList = std::vector<Texted_button*>(NUMBER_BUTTON, NULL);
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
    media->insertChunk("sfx/effect/clack.wav");
    loadFont();
}

void App::loadObject()
{
    background = new Display_fullsize_object(graphic->getRenderer(),"gfx/background2.jpg", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    buttonList[SUFFER] = new Texted_button(graphic->getRenderer(), "gfx/button.png",1025,600, 200,50, "Suffer");
    buttonList[PUZZLE_8] = new Texted_button(graphic->getRenderer(), "gfx/button.png",1025,530, 200,50, "8Puzzle");
    buttonList[PUZZLE_15] = new Texted_button(graphic->getRenderer(), "gfx/button.png",1025,460, 200,50, "15Puzzle");
    buttonList[PUZZLE_24] = new Texted_button(graphic->getRenderer(), "gfx/button.png",1025,390, 200,50, "24Puzzle");
    buttonList[SHOW_HIDE_NUMBER] = new Texted_button(graphic->getRenderer(), "gfx/button.png",1025,320, 200,50, "Show Number");

    for(auto u:buttonList) 
    {
        u->setHoverEffect(2);
        u->setFont(fontList[FONT_30]);
        u->setTextColor(255,255,0,255);
    }
}

void App::loadAllTexture()
{
    loadObject();
}

void App::loadFont()
{
    fontList.push_back(TTF_OpenFont("font/Roboto-Light.ttf", 18));
    fontList.push_back(TTF_OpenFont("font/Roboto-Light.ttf", 30));
    fontList.push_back(TTF_OpenFont("font/Roboto-Light.ttf", 48));
    fontList.push_back(TTF_OpenFont("font/Roboto-Light.ttf", 56));
}

void App::updateRender()
{
    SDL_RenderClear(graphic->getRenderer());    

    background->blit();
    leftbar->blit();

    puzzle->blit();
        
    for (auto u: buttonList) u->blit();

    graphic->renderPresent();
}

void App::Update()
{
    event->updateEvent();

    int mouse_x, mouse_y, mouse_click;
    Movement_key m_key = event->getMovement();

    event->getMouseStatus(mouse_x, mouse_y, mouse_click);

    if (puzzle->MouseProcess(mouse_x,mouse_y,mouse_click)) 
        media->playChunk(MEDIA_CHUNK_CLACK);

    if (puzzle->MovementProcess(m_key.up, m_key.down, m_key.left, m_key.right))
        media->playChunk(MEDIA_CHUNK_CLACK);

    leftbar->MouseProcess(mouse_x,mouse_y,mouse_click);
    
    for (auto u: buttonList) 
        u->MouseProcess(mouse_x, mouse_y, mouse_click);
    
    if (leftbar->isCurrentChanged()) 
        puzzle->setTexture(leftbar->GetNewTexture());
        
    if (buttonList[SUFFER]->isClicked()) puzzle->suffer();
    if (buttonList[PUZZLE_8]->isClicked()) puzzle->resize(3);
    if (buttonList[PUZZLE_15]->isClicked()) puzzle->resize(4);
    if (buttonList[PUZZLE_24]->isClicked()) puzzle->resize(5);
    if (buttonList[SHOW_HIDE_NUMBER]->isClicked()) 
    {
        if (puzzle->show_hide_number())
            buttonList[SHOW_HIDE_NUMBER]->setText("Hide Number");
        else 
            buttonList[SHOW_HIDE_NUMBER]->setText("Show Number");
    }
    puzzle->updatePuzzle();
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
    delete globalTimer;
    delete media;
    for (auto u: buttonList) delete u;
    for (auto u: fontList) TTF_CloseFont(u);
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