#ifndef RENDERER_H
#define RENDERER_H

#include "SDL2/SDL.h"

#include "Asteroid.h"
#include "Bullet.h"
#include "Player.h"

#include <vector>
#include <memory>

class Renderer {
public:
    Renderer(std::size_t, std::size_t, std::size_t, std::size_t);
    ~Renderer();
    void Render(std::vector<std::shared_ptr<Asteroid>>&, std::vector<std::shared_ptr<Bullet>>&, std::shared_ptr<Player>&);
private:
    void AsteroidRender(std::shared_ptr<Asteroid>&);
    void BulletRender(std::shared_ptr<Bullet>&);
    void PlayerRender(std::shared_ptr<Player>&);

    SDL_Window* window;
    SDL_Renderer* renderer;

    std::size_t screen_width;
    std::size_t screen_height;
    std::size_t grid_width;
    std::size_t grid_height;

    std::vector<std::shared_ptr<Asteroid>> asteroids;
    std::vector<std::shared_ptr<Bullet>> bullets;
    std::shared_ptr<Player> player;
};

#endif /* RENDERER_H */