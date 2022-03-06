#include "app.h"


int main(int argc,char *argv[])
{
    App *app = new App;
    app->updatePresent();
    SDL_Delay(5000);
}