#include "app.h"


int main(int argc,char *argv[])
{
    App *app = new App;
    
    app->appLoop();
    //delete app;
    return 0;
}