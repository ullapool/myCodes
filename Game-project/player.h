#ifndef PLAYER_H
#define PLAYER_H
#include "gameobject.h"


class Player : public GameObject
{

public:
    Player(int x, int y);
    virtual void move();
};

#endif // PLAYER_H
