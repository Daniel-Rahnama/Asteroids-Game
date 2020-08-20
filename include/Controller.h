#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "SDL2/SDL.h"

#include "Player.h"
#include "Entity.h"
#include "Bullet.h"

#include <memory>
#include <vector>

class Controller {
public:
    void HandleInput(bool&, std::shared_ptr<Player>, std::vector<std::shared_ptr<Bullet>>&);
private:
    void MoveForward();
    void TurnLeft();
    void TurnRight();
    void FireBullet();

    std::shared_ptr<Player> _player;
    std::vector<std::shared_ptr<Bullet>>* _bullets;
};

#endif /* CONTROLLER_H */