#include "../include/Entity.h"

const int& Entity::x() {
    return _x;
}

const int& Entity::y() {
    return _y;
}

const int& Entity::s() {
    return _speed;
}

const bool& Entity::IsAlive() {
    return _alive;
}

const double& Entity::Angle() {
    return _angle;
}

void Entity::Update() {}