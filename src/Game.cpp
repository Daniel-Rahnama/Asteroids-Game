#include "../include/Game.h"

Game::Game(std::size_t Grid_Width, std::size_t Grid_Height) : Grid_Width(Grid_Width), Grid_Height(Grid_Height), Score(0) {
    Asteroids.emplace_back(std::make_shared<Asteroids>(large, 100, 100, 135));
    Asteroids.emplace_back(std::make_shared<Asteroids>(large, 100, 700, 45));
    Asteroids.emplace_back(std::make_shared<Asteroids>(large, 700, 100, 225));
    Asteroids.emplace_back(std::make_shared<Asteroids>(large, 700, 700, 315));

    Player = std::make_shared<Player>();
}

void Game::Run(Controller& controller, Renderer& renderer, const int& Target_Frame_Duration) {
    Uint32 Title_Timestamp = SDL_GetTicks();
    Uint32 Frame_Start;
    Uint32 Frame_End;
    Uint32 Frame_Duration;
    unsigned int Frame_Count = 0;

    bool running = true;

    while (running) {
        Frame_Start = SDL_GetTicks();

        controller.HandleInput(running, Player);

        renderer.Render(Asteroids, Bullets, Player);

        Frame_End = SDL_GetTicks();

        Frame_Duration = Frame_End - Frame_Start;
        Frame_Count++;

        if (Frame_End - Title_Timestamp >= 1000) {
            renderer.UpdateWindowTitle(Score, Frame_Count);
            Frame_Count = 0;
            Title_Timestamp = Frame_End;
        }

        if (Frame_Duration < Target_Frame_Duration) {
            SDL_Delay(Target_Frame_Duration - Frame_Duration);
        }
    }
}