#ifndef H_BASE
#define H_BASE

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <time.h>
#include <string>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <utility>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#define WINDOW_TITTLE "8Puzzle"

const unsigned int SCREEN_WIDTH = 1280;
const unsigned int SCREEN_HEIGHT = 720;
const unsigned int FONT_SIZE = 60;
const unsigned int FPS = 100;
const unsigned int TICKS_PER_FRAME = 1000/FPS;

void logSDLerror(std::ostream &os,std::string msg, bool fatal);
void logGeneralError(std::ostream &os,std::string msg, bool fatal);
void setRect(SDL_Rect* rect,const int x, const int y, const int w, const int h);
void setColor(SDL_Color *color, const int r, const int g, const int b, const int a);
bool hitBoxCheck(int x,int y,int X,int Y,int W,int H);
#endif