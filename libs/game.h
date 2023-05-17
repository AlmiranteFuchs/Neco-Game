// Header of defines
// Path: libs/defs.hpp
#ifndef _GAME_H_
#define _GAME_H_

#include <list>
#include <iostream>
#include <SDL.h>

#include "object.h"
#include "game_scene.h"

#define WIDTH 1200
#define HEIGHT 720

class Game
{
public:
    Game();
    ~Game();
    void Loop();
    void Update();
    void Input();
    void Draw(std::list<Object *> objects);
    void Render();

    void ChangeScene(Scene *scene);

private:
    // SDL variables
    SDL_Window *window;
    SDL_Renderer *renderer;

    // Logic variables
    bool running;
    bool fullscreen;
    int frame_count, timer_fps, last_frame, fps, last_time;

    // Running scene
    Scene *scene;

    // List of scenes
    std::list<Scene *> scenes;
};

#endif // _GAME_H_