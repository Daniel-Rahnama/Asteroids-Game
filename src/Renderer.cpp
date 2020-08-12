#include "../include/Renderer.h"

#include <iostream>
#include <future>

Renderer::Renderer(std::size_t screen_width, std::size_t screen_height, std::size_t grid_width, std::size_t grid_height) : 
    screen_width(screen_width), 
    screen_height(screen_height),
    grid_width(grid_width),
    grid_height(grid_height) {
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0) { 
        std::cout << "SDL could not initialize.\n";
        std::cout << "SDL Error: " << SDL_GetError() << std::endl;
    }

    window = SDL_CreateWindow("Asteroids", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_width, screen_height, SDL_WINDOW_SHOWN);

    if (window == nullptr) {
        std::cout << "Window could not be created.\n";
        std::cout << "SDL Error: " << SDL_GetError() << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1 ,SDL_RENDERER_ACCELERATED);

    if (renderer == nullptr) {
        std::cout << "Renderer could not be created.\n";
        std::cout << "SDL Error: " << SDL_GetError() << std::endl;
    }
}

Renderer::~Renderer() {
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Renderer::Render(std::vector<std::shared_ptr<Asteroid>>& asteroids, std::vector<std::shared_ptr<Bullet>>& bullets, std::shared_ptr<Player>& player) {
    this->asteroids = asteroids;
    this->bullets = bullets;
    this->player = player;

    SDL_SetRenderDrawColor(renderer, 0x1E, 0x1E, 0x1E, 0xFF);
    SDL_RenderClear(renderer);

    std::vector<std::future<void>> futures;

    for (std::shared_ptr<Asteroid>& a : asteroids) {
        futures.emplace_back(std::async(&Renderer::AsteroidRender, this, std::ref(a)));
    }

    for (std::shared_ptr<Bullet>& b : bullets) {
        futures.emplace_back(std::async(&Renderer::BulletRender, this, std::ref(b)));
    }

    futures.emplace_back(std::async(&Renderer::PlayerRender, this, std::ref(player)));

    for (std::future<void>& f : futures) {
        f.wait();
    }

    SDL_RenderPresent(renderer);
}

void Renderer::AsteroidRender(std::shared_ptr<Asteroid>& a) {}

void Renderer::BulletRender(std::shared_ptr<Bullet>& b) {}

void Renderer::PlayerRender(std::shared_ptr<Player>& p) {}

/*
    SDL_SetRenderDrawColor(renderer, 0x1E, 0x1E, 0x1E, 0xFF);
    SDL_RenderClear(renderer);

    // bullet size

    SDL_Rect Bullet;

    Bullet.w = 3;
    Bullet.h = 3;

    SDL_SetRenderDrawColor(renderer, 0x33, 0x3C, 0xFF, 0xFF);
    Bullet.x = 0;
    Bullet.y = 0;
    SDL_RenderFillRect(renderer, &Bullet);

    // Starship size
    
    SDL_Rect StarShip;

    StarShip.w = 15;
    StarShip.h = 40;

    SDL_SetRenderDrawColor(renderer, 0x33, 0x3C, 0xFF, 0xFF);
    StarShip.x = 300;
    StarShip.y = 300;
    SDL_RenderFillRect(renderer, &StarShip);

    SDL_RenderPresent(renderer);
*/