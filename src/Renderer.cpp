#include "../include/Renderer.h"

#include <iostream>

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

    Render();

}

Renderer::~Renderer() {
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Renderer::Render() {
    SDL_Rect block;
    block.w = 50;
    block.h = 50;

    SDL_SetRenderDrawColor(renderer, 0x1E, 0x1E, 0x1E, 0xFF);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0x33, 0x3C, 0xFF, 0xFF);
    block.x = 0;
    block.y = 0;
    SDL_RenderFillRect(renderer, &block);

    SDL_RenderPresent(renderer);
}