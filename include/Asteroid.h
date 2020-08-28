#ifndef ASTEROID_H
#define ASTEROID_H

#include "Entity.h"

#include <memory>
#include "Bullet.h"
#include "Player.h"

enum AsteroidSize {
    large,
    medium,
    small,
};

class Asteroid : public Entity {
public:
    Asteroid(AsteroidSize, int, int, double);
    Asteroid(const Asteroid&) = delete;
    Asteroid& operator=(const Asteroid&) = delete;
    Asteroid(Asteroid&&);
    Asteroid& operator=(Asteroid&&);

    const AsteroidSize& GetSize();
    const int& GetRadius();

    void Update() override;

    bool Collision(std::shared_ptr<Bullet>);
private:
    AsteroidSize _size;
    int _radius;
    
    friend class Player;
};

#endif /* ASTEROID_H */