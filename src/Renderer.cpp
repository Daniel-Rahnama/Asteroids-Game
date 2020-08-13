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

Renderer::Renderer(Renderer&& source) {
    this->window = source.window;
    this->renderer = source.renderer;

    source.window = nullptr;
    source.renderer = nullptr;

    this->screen_width = source.screen_width;
    this->screen_height = source.screen_height;
    
    this->grid_width = source.grid_width;
    this->grid_height = source.grid_height;
}

Renderer& Renderer::operator=(Renderer&& source) {
    if (this == &source) return *this;

    this->window = source.window;
    this->renderer = source.renderer;

    source.window = nullptr;
    source.renderer = nullptr;

    this->screen_width = source.screen_width;
    this->screen_height = source.screen_height;
    
    this->grid_width = source.grid_width;
    this->grid_height = source.grid_height;

    return *this;
}

Renderer::~Renderer() {
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Renderer::Render(std::vector<std::shared_ptr<Asteroid>>& asteroids, std::vector<std::shared_ptr<Bullet>>& bullets, std::shared_ptr<Player>& player) {

    SDL_SetRenderDrawColor(renderer, 0x1E, 0x1E, 0x1E, 0xFF);
    SDL_RenderClear(renderer);

    std::vector<std::future<void>> futures;

    for (std::shared_ptr<Asteroid>& a : asteroids) {
        futures.emplace_back(std::async(&Renderer::AsteroidRender, this, a));
    }

    for (std::shared_ptr<Bullet>& b : bullets) {
        futures.emplace_back(std::async(&Renderer::BulletRender, this, b));
    }

    futures.emplace_back(std::async(&Renderer::PlayerRender, this, player));

    for (std::future<void>& f : futures) {
        f.wait();
    }

    SDL_RenderPresent(renderer);
}

void Renderer::AsteroidRender(std::shared_ptr<Asteroid> a) {}

void Renderer::BulletRender(std::shared_ptr<Bullet> b) {
    SDL_Rect bullet;

    bullet.w = 3;
    bullet.h = 3;

    bullet.x = b->x();
    bullet.y = b->y();

    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(renderer, &bullet);
}

void Renderer::PlayerRender(std::shared_ptr<Player> p) {
    SDL_Rect player;

    player.w = p->w();
    player.h = p->h();

    player.x = p->x();
    player.y = p->y();

    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(renderer, &player);
}