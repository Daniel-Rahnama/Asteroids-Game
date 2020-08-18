#ifndef ENTITY_H
#define ENTITY_H

class Entity {
public:
    const unsigned int& x();
    const unsigned int& y();
    const unsigned int& s();
    const bool& IsAlive();
    const double& Angle();

    virtual void Update() = 0;
protected:
    friend class Controller;
    unsigned int _x;
    unsigned int _y;
    unsigned int _speed;
    bool _alive;
    double _angle;
};

#endif /* ENTITY_H */