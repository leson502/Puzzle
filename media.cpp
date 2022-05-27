#include "media.h"

Game_Media::Game_Media()
{
    Init();
}

void Game_Media::Init()
{
    InitFont();
    g_chunk.clear();
    g_music.clear();
}

void Game_Media::InitFont()
{
    if (TTF_Init() < 0) 
        SDL_Log("%s", TTF_GetError());
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
        SDL_Log( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
}   

void Game_Media::insertMusic(std::string filename)
{
    Mix_Music *t_music = Mix_LoadMUS(filename.c_str());
    g_music.push_back(t_music);
}

void Game_Media::playMusicRandom()
{
    if (Mix_PlayingMusic() == 0) 
    {
        int index = rand() % g_music.size();
        Mix_PlayMusic(g_music[index], 1);
    }    
}

void Game_Media::insertChunk(std::string filename)
{
    Mix_Chunk *t_chunk = Mix_LoadWAV(filename.c_str());
    g_chunk.push_back(t_chunk);
}

void Game_Media::playChunk(int index)
{
    if (g_chunk.size() > index)
        Mix_PlayChannel(-1, g_chunk[index], 0);
}

void Game_Media::destroy()
{
    for (auto u:g_chunk) Mix_FreeChunk(u);
    for (auto u:g_music) Mix_FreeMusic(u);

}

Game_Media::~Game_Media()
{
    destroy();
}