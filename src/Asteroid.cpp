#include "../include/Asteroid.h"

Asteroid::Asteroid(AsteroidSize size, int x, int y, double angle) : _size(size) {
    _angle = angle;

    _x = x;
    _y = y;

    _alive = true;

    switch (_size) {
        case large: _radius = 60; _speed = 1; break;
        case medium: _radius = 40; _speed = 2; break;
        case small: _radius = 20; _speed = 3; break;
    }
}

const AsteroidSize& Asteroid::GetSize() {
    return _size;
}

const int& Asteroid::GetRadius() {
    return _radius;
}

void Asteroid::Update() {
    double angle = 2 * 3.1415 * (_angle / 360);

    _x += _speed * cos(angle);
    _y += _speed * sin(angle);

    if (_x > 800 || _y > 800) _alive = false;
}