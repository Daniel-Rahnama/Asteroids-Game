#include "../include/Bullet.h"

Bullet::Bullet(int x, int y, double angle) : _w(3), _h(3) {
    _alive = true;

    _speed = 2;

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