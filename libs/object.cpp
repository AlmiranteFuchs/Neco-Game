#include "object.h"

void Object::SetSrc(int x, int y, int w, int h)
{
    src.x = x;
    src.y = y;
    src.w = w;
    src.h = h;
}

void Object::SetDest(int x, int y, int w, int h)
{
    // Get Acceleration of the object
    Acceleration acceleration = GetAcceleration();

    dest.x = x + acceleration.ax;
    dest.y = y + acceleration.ay;
    dest.w = w;
    dest.h = h;

    // Remove acceleration
    SetAcceleration(0, 0);
}

void Object::setImage(std::string path, SDL_Renderer *ren)
{
    renderer = ren;
    SDL_Surface *surface = IMG_Load(path.c_str());
    texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_FreeSurface(surface);
}
