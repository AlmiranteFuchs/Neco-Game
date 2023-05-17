// Header of defines
// Path: libs/defs.hpp
#ifndef _OBJECT_H
#define _OBJECT_H

#include <string>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

class Object
{
private:
    SDL_Rect src;
    SDL_Rect dest;

    int rotation = 0;
    std::string name;

    SDL_Texture *texture;
    SDL_Renderer *renderer;

public:
    Object(std::string obj_name)
    {
        this->name = obj_name;
    };
    ~Object(){};

    // Get & Set
    SDL_Rect GetSrc() { return src; };
    SDL_Rect GetDest() { return dest; };
    SDL_Texture *GetTex() const { return texture; }
    int GetRotation() const { return rotation; }
    std::string GetName() { return name; };

    void SetSrc(int x, int y, int w, int h);
    void SetDest(int x, int y, int w, int h);
    void setImage(std::string path, SDL_Renderer *renderer);
    void SetRotation(int rotation) { this->rotation = rotation; }
};

#endif // _OBJECT_H