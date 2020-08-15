#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "SDL2/SDL.h"

#include "Player.h"

class Controller {
public:
    void HandleInput(bool&, Player&);
private:
    void KeepTrue();
    void MoveForward();
    void TurnLeft();
    void TurnRight();
    void FireBullet();

    friend class Player;
};

#endif /* CONTROLLER_H */