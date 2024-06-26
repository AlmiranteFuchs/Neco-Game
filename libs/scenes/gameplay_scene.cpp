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
        Object *player = new Object("player", 0, 0, 175, 88);
        player->setImage("../assets/player.png", renderer);
        // Place the player in the middle of the height of the screen
        player->SetDest(0, HEIGHT / 2, player->GetDest().w, player->GetDest().h);
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

        // Update the position of the player
        _update_player();
    }

private:
    // Scene variables
    int pipe_above_max_height = 300;
    int pipe_above_min_height = 200;
    int pipe_gap = 900;
    int pipe_horizontal_gap = 500;
    int pipe_speed = 5;

    // Player variables
    int player_speed = 5;

    // List of pipes
    std::list<Object *> pipes;

    // Generate pipes
    void _generate_pipes()
    {
        // Generate pair of 6 pipes

        for (int i = 0; i < 5; i++)
        {
            int x_gap = i * pipe_horizontal_gap;

            // Create a pipe for above
            Object *pipe_above = new Object("pipe_above_" + i, 0, 0, 525, 565);
            pipe_above->setImage("../assets/pipe.png", renderer);

            int random_range = rand() % pipe_above_max_height + pipe_above_min_height;

            // pipe_above->SetDest(WIDTH + x_gap, -random_range, pipe_above->GetDest().w, pipe_above->GetDest().h);
            _generate_pipe(pipe_above, true, x_gap);

            // Push the pipe to the list
            pipes.push_back(pipe_above);
            objects.push_back(pipe_above);

            // Create a pipe for below
            Object *pipe_below = new Object("pipe_below_" + i, 0, 0, 525, 565);
            pipe_below->setImage("../assets/pipe.png", renderer);
            // pipe_below->SetDest(WIDTH + x_gap, -random_range + pipe_gap, pipe_below->GetDest().w, pipe_below->GetDest().h);
            _generate_pipe(pipe_below, false, x_gap);

            // Push the pipe to the list
            pipes.push_back(pipe_below);
            objects.push_back(pipe_below);
        }
    }

    // Update pipes
    void _update_pipes()
    {

        // Update the position of the pipes
        for (std::list<Object *>::iterator it = pipes.begin(); it != pipes.end(); it++)
        {
            // Get the pipe
            Object *pipe = *it;

            // Get the position of the pipe
            SDL_Rect pipe_dest = pipe->GetDest();

            // Update the position of the pipe
            pipe->SetDest(pipe_dest.x - pipe_speed, pipe_dest.y, pipe_dest.w, pipe_dest.h);

            // If pipe outside of window box
            if (pipe_dest.x + pipe_dest.w + pipe_horizontal_gap < 0)
            {
                // Reset the position of the pipe
                _generate_pipe(pipe, pipe->GetRotation() == 0, pipe_horizontal_gap - 200);
            }
        }
    }

    // Generate pipe
    void _generate_pipe(Object *pipe, bool above, int x_gap)
    {
        int random_range = rand() % pipe_above_max_height + pipe_above_min_height;

        pipe->SetDest(WIDTH + x_gap, -random_range, pipe->GetDest().w, pipe->GetDest().h);

        if (!above)
        {
            pipe->SetDest(WIDTH + x_gap, -random_range + pipe_gap, pipe->GetDest().w, pipe->GetDest().h);
            pipe->SetRotation(180);
        }
    }

    // Update player
    void _update_player()
    {
        // Get the player object
        Object *player = objects.front();

        SDL_Rect player_dest = player->GetDest();

        // Set the acceleration of the player
        player->SetAcceleration(0, 1.5);

        // // Update the position of the player
        player->SetDest(player_dest.x, player_dest.y, player_dest.w, player_dest.h);
    }
};

// above: 200 & 500