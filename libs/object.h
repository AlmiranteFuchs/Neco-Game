// Header of defines
// Path: libs/defs.hpp
#ifndef _OBJECT_H
#define _OBJECT_H

#include <string>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

// Struct for object acceleration
struct Acceleration
{
    float ax;
    float ay;
};

class Object
{
private:
    SDL_Rect src;
    SDL_Rect dest;

    int rotation = 0;
    // Acceleration properties
    Acceleration acceleration;

    std::string name;

    SDL_Texture *texture;
    SDL_Renderer *renderer;

public:
    Object(std::string obj_name, int x, int y, int w, int h)
    {
        this->name = obj_name;

        // Set the source and destination
        this->src = {x, y, w, h};
        this->dest = {x, y, w, h};

        // Set the acceleration
        this->acceleration.ax = 0;
        this->acceleration.ay = 0;
    };
    ~Object(){};

    // Get & Set
    SDL_Rect GetSrc() { return src; };
    SDL_Rect GetDest() { return dest; };
    SDL_Texture *GetTex() const { return texture; }
    int GetRotation() const { return rotation; }
    std::string GetName() { return name; };
    Acceleration GetAcceleration() { return acceleration; }

    void SetSrc(int x, int y, int w, int h);
    void SetDest(int x, int y, int w, int h);
    void setImage(std::string path, SDL_Renderer *renderer);
    void SetRotation(int rotation) { this->rotation = rotation; }
    void SetAcceleration(float ax, float ay)
    {
        this->acceleration.ax = ax;
        this->acceleration.ay = ay;
    }
};

#endif // _OBJECT_H