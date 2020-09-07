#ifndef RENDERER_H
#define RENDERER_H

#include "SDL2/SDL.h"

#include "Asteroid.h"
#include "Bullet.h"
#include "Player.h"

#include <vector>
#include <memory>
#include <mutex>

class Renderer {
public:
    Renderer(std::size_t, std::size_t);
    Renderer(const Renderer&) = delete;
    Renderer& operator=(const Renderer&) = delete;
    Renderer(Renderer&&);
    Renderer& operator=(Renderer&&);
    ~Renderer();
    void Render(std::vector<std::shared_ptr<Asteroid>>&, std::vector<std::shared_ptr<Bullet>>&, std::shared_ptr<Player>&);
    void UpdateWindowTitle(int, int);
private:
    void AsteroidRender(std::shared_ptr<Asteroid>);
    void BulletRender(std::shared_ptr<Bullet>);
    void PlayerRender(std::shared_ptr<Player>);

    SDL_Window* window;
    SDL_Renderer* renderer;

    std::size_t screen_width;
    std::size_t screen_height;

    std::mutex renderMtx;
};

#endif /* RENDERER_H */