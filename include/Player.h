#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Asteroid.h"

#include <memory>

class Player : public Entity {
public:
    Player();
    Player(const Player&) = delete;
    Player& operator=(const Player&) = delete;
    Player(Player&&);
    Player& operator=(Player&&);

    const int& w();
    const int& h();

    void Update() override;

    void Collision(std::shared_ptr<Asteroid>);
private:
    friend class Controller;
    int _w;
    int _h;
    double _direction;
};

#endif /* ENTITY_H */