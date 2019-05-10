#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "gameobject.h"


class Obstacle : public GameObject
{
    Q_OBJECT

public:
    Obstacle(int x, int y);
    virtual void move();
};

#endif // OBSTACLE_H
