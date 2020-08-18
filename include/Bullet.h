#ifndef BULLET_H
#define BULLET_H

#include "Entity.h"

class Bullet : public Entity {
public:
    Bullet(int, int, double);
    Bullet(const Bullet&) = delete;
    Bullet& operator=(const Bullet&) = delete;
    Bullet(Bullet&&);
    Bullet& operator=(Bullet&&);

    const int& w();
    const int& h();
private:
    int _w;
    int _h;
};

#endif /* BULLET_H */