#ifndef H_OBJECT_TEXT
#define H_OBJECT_TEXT

#include "base.h"
#include "base_object.h"

class Text_object : public Object
{
protected:
    TTF_Font *font;
public:
    Text_object();
    ~Text_object();
    void default_object();
    void destroy_object();
    void setFont(TTF_Font *_font);
    void createTexture(std::string &text);
};


#endif