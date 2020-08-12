#ifndef RENDERER_H
#define RENDERER_H

#include "SDL2/SDL.h"

class Renderer {
public:
    Renderer(std::size_t, std::size_t);
    ~Renderer();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    std::size_t screen_width;
    std::size_t screen_height;
};

#endif