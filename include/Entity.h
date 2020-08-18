#ifndef ENTITY_H
#define ENTITY_H

#include <cmath>

class Entity {
public:
    const int& x();
    const int& y();
    const int& s();
    const bool& IsAlive();
    const double& Angle();
    virtual void Update();
protected:
    friend class Controller;
    int _x;
    int _y;
    int _speed;
    bool _alive;
    double _angle;
};

#endif /* ENTITY_H */