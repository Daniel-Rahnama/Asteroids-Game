#include "../include/Player.h"

#include <cmath>

Player::Player() {
    _alive = true;

    _speed = 0;

    _x = 400;
    _y = 400;

    _w = 16;
    _h = 40;

    _angle = 0.0;

    _direction = 0.0;
}

const int& Player::w() {
    return _w;
}

const int& Player::h() {
    return _h;
}

void Player::Update() {
    double angle = 2 * 3.1415 * (_direction / 360);

    _x -= _speed * sin(angle);
    _y += _speed * cos(angle);

    if (_x >= 800) _x = 0;
    if (_y >= 800) _y = 0;
    if (_x <= 0) _x = 800;
    if (_y <= 0) _y = 800;
}