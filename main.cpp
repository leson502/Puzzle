#include "app.h"


int main(int argc,char *argv[])
{
    srand(time(NULL));
    App *app = new App;
    
    app->Play();
    delete app;
    return 0;
}