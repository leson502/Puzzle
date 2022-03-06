#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

#define SCREEN_WIDTH 750
#define SCREEN_HEIGHT 750
#define WINDOW_TITTLE "8Puzzle"
#define BLOCKSIZE 250
void logSDLerror(std::ostream &os,std::string msg, bool fatal);
void logGeneralError(std::ostream &os,std::string msg, bool fatal);



