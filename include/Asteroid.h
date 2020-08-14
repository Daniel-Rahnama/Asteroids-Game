#ifndef ASTEROID_H
#define ASTEROID_H

#include "Entity.h"

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
private:
    AsteroidSize _size;
    int _radius;
};

#endif /* ASTEROID_H */