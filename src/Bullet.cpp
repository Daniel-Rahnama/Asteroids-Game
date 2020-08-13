#include "../include/Bullet.h"

Bullet::Bullet(int x, int y, double angle) {
    _alive = true;

    _x = x;
    _y = y;

    _angle = angle;
}