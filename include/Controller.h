#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "SDL2/SDL.h"

#include "Player.h"

#include <memory>

class Controller {
public:
    void HandleInput(bool&, std::shared_ptr<Player>);
private:
    void KeepTrue();
    void MoveForward();
    void TurnLeft();
    void TurnRight();
    void FireBullet();

    friend class Player;

    std::shared_ptr<Player> _player;
};

#endif /* CONTROLLER_H */