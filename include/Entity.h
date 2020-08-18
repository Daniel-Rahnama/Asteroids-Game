#ifndef ENTITY_H
#define ENTITY_H

class Entity {
public:
    virtual void Update();
    const int& x();
    const int& y();
    const int& s();
    const bool& IsAlive();
    const double& Angle();
protected:
    friend class Controller;
    int _x;
    int _y;
    int _speed;
    bool _alive;
    double _angle;
};

#endif /* ENTITY_H */