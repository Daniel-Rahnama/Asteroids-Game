#ifndef GAME_H
#define GAME_H

#include "SDL2/SDL.h"

#include "Entity.h"

#include "Renderer.h"
#include "Controller.h"

#include "Asteroid.h"
#include "Bullet.h"
#include "Player.h"

#include <vector>
#include <memory>

class Game {
public:
    Game(std::size_t, std::size_t);
    void Run(Controller&, Renderer&, const int& Target_Frame_Duration);
private:
    void Update();

    std::vector<std::shared_ptr<Asteroid>> Asteroids;
    std::vector<std::shared_ptr<Bullet>> Bullets;
    std::shared_ptr<Player> Player;

    std::size_t Grid_Width;
    std::size_t Grid_Height;

    unsigned int Score;
};

#endif /* GAME_H */