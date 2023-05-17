// This is a test scene

#include "../game_scene.h"

// Extends the Scene class
class TestScene : public Scene
{
public:
    TestScene(std::string obj_name, SDL_Renderer *renderer) : Scene(obj_name, renderer)
    {

        // Define this scene objects
        Object *obj = new Object();
        obj->setImage("../assets/player.png", renderer);
        obj->SetSrc(0, 0, 175, 88);
        obj->SetDest(0, 0, 175, 88);
        objects.push_back(*obj);

        // New object
        Object *obj2 = new Object();
        obj2->setImage("../assets/player.png", renderer);
        obj2->SetSrc(0, 0, 175, 88);
        obj2->SetDest(100, 0, 175, 88);
        objects.push_back(*obj2);

        std::cout << "TestScene object created" << std::endl;
    }
    ~TestScene()
    {
        // Clear the objects list
        objects.clear();
    }

    // Implement the abstract function
    void Update()
    {
        std::cout << "TestScene Update" << std::endl;
    }
};