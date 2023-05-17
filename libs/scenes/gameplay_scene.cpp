// Main gameplay scene

#include "../game_scene.h"
#include "../game.h"

// Extends the Scene class
class GameplayScene : public Scene
{
public:
    GameplayScene(std::string obj_name, SDL_Renderer *renderer) : Scene(obj_name, renderer)
    {
        // Defines object and stuff for this scene gameplay

        // New Player object
        Object *player = new Object("player");
        player->setImage("../assets/player.png", renderer);
        // Place the player in the middle of the height of the screen
        player->SetDest(0, HEIGHT / 2, 175, 88);
        player->SetSrc(0, 0, 175, 88);
        objects.push_back(player);

        // Generate pipes
        _generate_pipes();
    }
    ~GameplayScene()
    {
        // Clear the objects list
        objects.clear();
        pipes.clear();
    }

    // Implement the abstract function
    void Update()
    {
        // Update the position of the pipes
        _update_pipes();
    }

private:
    // Scene variables
    int pipe_above_max_height = 300;
    int pipe_above_min_height = 200;
    int pipe_gap = 800;
    int pipe_horizontal_gap = 500;
    int pipe_speed = 5;

    // List of pipes
    std::list<Object*> pipes;

    // Generate pipes
    void _generate_pipes()
    {
        // Generate pair of 6 pipes

        for (int i = 0; i < 6; i++)
        {
            int x_gap = i * pipe_horizontal_gap;

            // Create a pipe for above
            Object *pipe_above = new Object("pipe_above_" + i);
            pipe_above->setImage("../assets/pipe.png", renderer);

            int random_range = rand() % pipe_above_max_height + pipe_above_min_height;

            pipe_above->SetDest(x_gap + 400, -random_range, 525, 565);
            pipe_above->SetSrc(0, 0, 525, 565);

            // Push the pipe to the list
            pipes.push_back(pipe_above);
            objects.push_back(pipe_above);

            // Create a pipe for below
            Object *pipe_below = new Object("pipe_below_" + i);
            pipe_below->setImage("../assets/pipe.png", renderer);
            pipe_below->SetDest(x_gap + 400, -random_range + pipe_gap, 525, 565);
            pipe_below->SetSrc(0, 0, 525, 565);
            // rotate the pipe in vertical
            pipe_below->SetRotation(180);

            // Push the pipe to the list
            pipes.push_back(pipe_below);
            objects.push_back(pipe_below);
        }
    }

    // Update pipes
    void _update_pipes()
    {

        // Update the position of the pipes
        for (std::list<Object*>::iterator it = pipes.begin(); it != pipes.end(); it++)
        {
            // Get the pipe
            Object *pipe = *it;

            // Get the position of the pipe
            SDL_Rect pipe_dest = pipe->GetDest();

            // Update the position of the pipe
            pipe->SetDest(pipe_dest.x - pipe_speed, pipe_dest.y, pipe_dest.w, pipe_dest.h);
        }
    }
};

// above: 200 & 500