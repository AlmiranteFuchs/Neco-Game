#include "game.h"
#include "scenes/gameplay_scene.cpp"
// Constructor
Game::Game()
{
    // Print
    std::cout << "Game object created" << std::endl;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "Failed at SDL_Init()" << std::endl;
        exit(1);
    }
    else if (SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer) < 0)
    {
        std::cout << "Failed at SDL_CreateWindowAndRenderer()" << std::endl;
        exit(1);
    }

    // Srand system time
    srand(time(NULL));

    // SDL settings
    SDL_SetWindowTitle(window, "SDL2 Game");
    SDL_ShowCursor(1);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    // Logic variables
    running = true;
    fullscreen = false;
    frame_count = 0;
    timer_fps = 0;
    last_frame = 0;
    fps = 0;
    last_time = 0;

    // Set the running scene
    scene = new GameplayScene("Gameplay", renderer);

    // Game loop
    Loop();
}

// Destructor
Game::~Game()
{
    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

// Runs the game loop
void Game::Loop()
{
    while (running)
    {
        // FPS Counter
        last_frame = SDL_GetTicks();
        if (last_frame >= (last_time + 1000))
        {
            last_time = last_frame;
            fps = frame_count;
            frame_count = 0;
        }

        // Game loop
        Input();
        Update();
        Render();
    }
}

// Handles the drawing of the game
void Game::Render() // Handles the drawing of the game
{
    // Draws the game

    // Clear the screen
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 40, 43, 200, 255); // This is the background color, in RGBA

    // SDL_Rect rect;
    // rect.x = 0;
    // rect.y = 0;
    // rect.w = WIDTH;
    // rect.h = HEIGHT;

    // SDL_RenderFillRect(renderer, &rect);

    // Draw
    Draw(scene->GetObjects());

    frame_count++;
    int timer_fps = SDL_GetTicks() - last_frame;
    if (timer_fps < (1000 / 60))
        SDL_Delay((1000 / 60) - timer_fps);

    SDL_RenderPresent(renderer);
}

// Handles the input of the game
void Game::Input()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        // Quit
        if (event.type == SDL_QUIT)
            running = false;

        const Uint8 *keystate = SDL_GetKeyboardState(NULL);
        if (keystate[SDL_SCANCODE_ESCAPE])
            running = false;

        // Fullscreen
        if (keystate[SDL_SCANCODE_F11])
        {
            if (fullscreen)
            {
                SDL_SetWindowFullscreen(window, 0);
                fullscreen = false;
            }
            else
            {
                SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
                fullscreen = true;
            }
        }
    }
}

// Handles the updating of the game
void Game::Update()
{
    this->scene->Update();
    // Updates the game
}

// Handles drawing of the game
void Game::Draw(std::list<Object *> objects)
{
    // Draw the game
    // All elements in the game are drawn here

    // For all objects in the list
    for (std::list<Object *>::iterator it = objects.begin(); it != objects.end(); it++)
    {
        // Get the object pointer
        Object *obj = *it;

        SDL_Rect dest = obj->GetDest();
        SDL_Rect src = obj->GetSrc();


        // Draw
        SDL_RenderCopyEx(renderer, obj->GetTex(), &src, &dest, obj->GetRotation(), NULL, SDL_FLIP_NONE);
    }
}

// Changes the running scene to the given scene
void Game::ChangeScene(Scene *scene)
{
    // Destroy current scene
    delete this->scene;

    // Change the running scene
    this->scene = scene;
}
