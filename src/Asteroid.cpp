#include "../include/Asteroid.h"

#include <cmath>
#include <iostream>

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
    double angle = _angle * (3.1415 / 180);

    _x += _speed * sin(angle);
    _y -= _speed * cos(angle);

    if (_x >= 799) _x = 0;
    if (_y >= 799) _y = 0;
    if (_x <= 0) _x = 799;
    if (_y <= 0) _y = 799;
}

bool Asteroid::Collision(std::shared_ptr<Bullet> b) {
    int tempX = x();
    int tempY = y();

    if (x() < b->x()) tempX = b->x();
    else if (x() < (b->x() + b->w())) tempX = b->x() + b->w();

    if (y() < b->y()) tempY = b->y();
    else if (y() < (b->y() + b->h())) tempY = b->y() + b->h();

    double distX = x() - tempX;
    double distY = y() - tempY;
    double distance = sqrt((distX * distX) + (distY * distY));

    if (distance <= GetRadius()) { _alive = false; return true; }
    return false;
}