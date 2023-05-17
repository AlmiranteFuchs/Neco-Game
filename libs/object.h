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

    int x, y, z, w, h;
    int rotation = 0;
    std::string name;

    SDL_Texture *texture;
    SDL_Renderer *renderer;

public:
    Object(std::string obj_name, int x, int y, int w, int h);
    {
        this->name = obj_name;
        this->x = x;
        this->y = y;
        this->w = w;
        this->h = h;

        this->src = {0, 0, w, h};
        this->dest = {x, y, w, h};
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