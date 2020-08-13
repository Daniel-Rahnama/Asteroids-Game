#include "../include/Asteroid.h"

Asteroid::Asteroid(AsteroidSize size, int x, int y, double angle) : _size(size) {
    _angle = angle;

    _x = x;
    _y = y;

    _alive = true;

    switch (_size) {
        case large: _radius = 60; _speed = 2; break;
        case medium: _radius = 40; _speed = 4; break;
        case small: _radius = 20; _speed = 6; break;
    }
}