#ifndef GAME_H
#define GAME_H

#include "SDL2/SDL.h"

#include "../include/Renderer.h"
#include "../include/Controller.h"

#include "Asteroid.h"
#include "Bullet.h"
#include "Player.h"

#include <vector>
#include <memory>

class Game {
public:
    Game(std::size_t, std::size_t);
    void Run(Controller&, Renderer&);
private:
    void Update();

    Controller& controller;
    Renderer& renderer;
    std::vector<std::shared_ptr<Asteroid>> Asteroids;
    std::vector<std::shared_ptr<Bullet>> Bullets;
    std::shared_ptr<Player> player;
};

#endif /* GAME_H */