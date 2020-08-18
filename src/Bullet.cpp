#include "../include/Bullet.h"

#include <cmath>

Bullet::Bullet(int x, int y, double angle) : _w(3), _h(3) {
    _alive = true;

    _speed = 3;

    _x = x;
    _y = y;

    _angle = angle;
}

const int& Bullet::w() {
    return _w;
}

const int& Bullet::h() {
    return _h;
}

void Bullet::Update() {
    double angle = 2 * 3.1415 * (_angle / 360);

    _x += _speed * sin(angle);
    _y -= _speed * cos(angle);

    if (_x > 800) _alive = false;
    if (_y > 800) _alive = false;
}