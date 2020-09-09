#ifndef ASTEROID_H
#define ASTEROID_H

#include "Entity.h"

#include <memory>
#include "Bullet.h"

enum AsteroidSize {
    large,
    medium,
    small,
};

class Asteroid : public Entity {
public:
    Asteroid(AsteroidSize, int, int, double);

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