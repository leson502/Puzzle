#ifndef H_MEDIA
#define H_MEDIA

#include "base.h"
enum{
    MEDIA_CHUNK_CLACK
};

class Game_Media
{
private:
    std::vector <Mix_Music*> g_music;
    std::vector <Mix_Chunk*> g_chunk;
public:
    Game_Media();
    ~Game_Media();
    void Init();
    void InitFont();
    void insertMusic(std::string filename);
    void playMusicRandom();
    void insertChunk(std::string filename);
    void playChunk(int index);
    void destroy();
};
#endif

