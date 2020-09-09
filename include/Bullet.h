#ifndef BULLET_H
#define BULLET_H

#include "Entity.h"

class Bullet : public Entity {
public:
    Bullet(int, int, double);

    const int& w();
    const int& h();

    void Update() override;
private:
    int _w;
    int _h;

    friend class Asteroid;
    friend class Player;
};

#endif /* BULLET_H */