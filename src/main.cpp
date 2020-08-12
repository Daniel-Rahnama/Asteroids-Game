#include "SDL2/SDL.h"

#include <iostream>

int main(int argv, char* argc[]) {
    SDL_Window* window = SDL_CreateWindow("Asteroids", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_SHOWN);
    std::cin.get();
    return 0;
}