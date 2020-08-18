#include "../include/Game.h"

#include <iostream>
#include <future>
#include <algorithm>

Game::Game(std::size_t Grid_Width, std::size_t Grid_Height) : Grid_Width(Grid_Width), Grid_Height(Grid_Height), Score(0) {
    asteroids.emplace_back(std::make_shared<Asteroid>(large, 100, 100, 135));
    asteroids.emplace_back(std::make_shared<Asteroid>(large, 100, 700, 45));
    asteroids.emplace_back(std::make_shared<Asteroid>(large, 700, 100, 225));
    asteroids.emplace_back(std::make_shared<Asteroid>(large, 700, 700, 315));

    player = std::make_shared<Player>();

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

        controller.HandleInput(running, player, bullets);

        Update();

        if (!asteroids.empty()) asteroids.erase(std::remove_if(asteroids.begin(), asteroids.end(), [](std::shared_ptr<Asteroid>& a) { return !a->IsAlive(); }));
        if (!bullets.empty()) bullets.erase(std::remove_if(bullets.begin(), bullets.end(), [](std::shared_ptr<Bullet>& b) { return !b->IsAlive(); }));

        if (!player->IsAlive()) running = false;

        renderer.Render(asteroids, bullets, player);

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
    std::cout << "Game Over!" << std::endl;
    std::cout << "Score: " << Score << std::endl;
}

void Game::Update() {
    std::vector<std::future<void>> futures;

    for (std::shared_ptr<Bullet>& b : bullets) {
        futures.emplace_back(std::async(&Bullet::Update, b.get()));
    }

    for (std::shared_ptr<Asteroid>& a : asteroids) {
        futures.emplace_back(std::async(&Asteroid::Update, a.get()));
    }
}