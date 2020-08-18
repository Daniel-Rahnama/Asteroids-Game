#include "../include/Entity.h"

const unsigned int& Entity::x() {
    return _x;
}

const unsigned int& Entity::y() {
    return _y;
}

const unsigned int& Entity::s() {
    return _speed;
}

const bool& Entity::IsAlive() {
    return _alive;
}

const double& Entity::Angle() {
    return _angle;
}