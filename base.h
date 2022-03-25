#ifndef H_BASE
#define H_BASE

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define WINDOW_TITTLE "8Puzzle"
#define BLOCKSIZE 220
#define PUZZLE_ORIGIN_X 310
#define PUZZLE_ORIGIN_Y 30

void logSDLerror(std::ostream &os,std::string msg, bool fatal);
void logGeneralError(std::ostream &os,std::string msg, bool fatal);
void swap(int *A, int *B);

#endif

