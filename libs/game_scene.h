// Scene class, will be inherited by all game_scenes
#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include <list>
#include "object.h"

class Scene
{
public:
    Scene(std::string obj_name, SDL_Renderer *renderer)
    {
        this->name = obj_name;
        this->renderer = renderer;
    }
    ~Scene(){
        objects.clear();
    }

    // Abstract function update
    virtual void Update() = 0;

    // Get
    std::list<Object *> GetObjects() { return objects; };
    std::string GetName() { return name; };

protected:
    // Props of object //
    // Object name
    std::string name;

    // renderer
    SDL_Renderer *renderer;


    // List of Game Objects in the scene
    std::list<Object *> objects;
};

#endif // GAME_SCENE_H