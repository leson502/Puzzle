#ifndef H_MEDIA
#define H_MEDIA

#include "base.h"

class Game_Media
{
private:
    TTF_Font *mainfont;
    std::vector <Mix_Music*> g_music;
    std::vector <Mix_Chunk*> g_chunk;
public:
    Game_Media();
    ~Game_Media();
    void Init();
    void InitFont();
    void loadFont(std::string filename);
    TTF_Font *getFont();

    void insertMusic(std::string filename);
    void playMusicRandom();
    void insertChunk(std::string filename);
    void playChunk(int index);
};
#endif

