#include "../include/Player.h"

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

void Player::Update() {}