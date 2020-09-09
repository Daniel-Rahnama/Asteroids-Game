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
    double angle = _direction * (3.1415 / 180);

    // _x += _speed * sin(angle);
    // _y -= _speed * cos(angle);

    _x += _speed * cos(angle);
    _y -= _speed * sin(angle);

    if (_x >= 800) _x = 0;
    if (_y >= 800) _y = 0;
    if (_x <= 0) _x = 800;
    if (_y <= 0) _y = 800;
}

void Player::Collision(std::shared_ptr<Asteroid> a) {
    double angle = Angle() * (3.1415 / 180);

    double x1 = x();
    double y1 = y() - h() / 2;
    double x2 = x() + w() / 2;
    double y2 = y() + h() / 2;
    double x3 = x() - w() / 2;
    double y3 = y2;

    double x1r = ((x1 - x()) * cos(angle) - (y1 - y()) * sin(angle) + x());
    double y1r = ((x1 - x()) * sin(angle) + (y1 - y()) * cos(angle) + y());

    double x2r = ((x2 - x()) * cos(angle) - (y2 - y()) * sin(angle) + x());
    double y2r = ((x2 - x()) * sin(angle) + (y2 - y()) * cos(angle) + y());

    double x3r = ((x3 - x()) * cos(angle) - (y3 - y()) * sin(angle) + x());
    double y3r = ((x3 - x()) * sin(angle) + (y3 - y()) * cos(angle) + x());

    double c1x = x1r - a->x();
    double c1y = y1r - a->y();

    double c2x = x2r - a->x();
    double c2y = y2r - a->y();

    double c3x = x3r - a->x();
    double c3y = y3r - a->y();

    if (sqrt(((c1x * c1x) + (c1y * c1y)) <= a->GetRadius())) { _alive = false; a->_alive = false; return; }
    if (sqrt(((c2x * c2x) + (c2y * c2y)) <= a->GetRadius())) { _alive = false; a->_alive = false; return; }
    if (sqrt(((c3x * c3x) + (c3y * c3y)) <= a->GetRadius())) { _alive = false; a->_alive = false; return; }

    if ((((y2r - y1r) * (a->x() - x1r) - (x2r - x1r) * (a->y() - y1r)) >= 0) && 
        (((y3r - y2r) * (a->x() - x2r) - (x3r - x2r) * (a->y() - y2r)) >= 0) &&
        (((y1r - y3r) * (a->x() - x3r) - (x1r - x3r) * (a->x() - x3r)) >= 0)) { _alive = false; a->_alive = false; return; }

    double k;

    c1x = a->x() - x1r;
    c1y = a->y() - y1r;

    double e1x = x2r - x1r;
    double e1y = y2r - y1r;

    k = c1x * e1x + c1y * e1y;

    if (k > 0) {
        double len = sqrt(e1x * e1x + e1y * e1y);
        k /= len;

        if (k < len) {
            if (sqrt(c1x * c1x + c1y * c1y - k * k) <= a->GetRadius()) { _alive = false; a->_alive = false; return; }
        }
    }

    c2x = a->x() - x2r;
    c2y = a->y() - y2r;

    double e2x = x3r - x2r;
    double e2y = y3r - y2r;

    k = c2x * e2x + c2y * e2y;

    if (k > 0) {
        double len = sqrt(e2x * e2x + e2y * e2y);
        k /= len;

        if (k < len) {
             if (sqrt(c2x * c2x + c2y * c2y - k * k) <= a->GetRadius()) { _alive = false; a->_alive = false; return; }
        }
    }

    c3x = a->x() - x3r;
    c3y = a->y() - y3r;

    double e3x = x1r - x3r;
    double e3y = y1r - y3r;

    k = c3x * e3x + c3y * e3y;

    if (k > 0) {
        double len = sqrt(e3x * e3x + e3y * e3y);
        k /= len;

        if (k < len) {
            if (sqrt(c3x * c3x + c3y * c3y - k * k) <= a->GetRadius()) { _alive = false; a->_alive = false; return; }
        }
    }
}