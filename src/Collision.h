#ifndef COLLISIONS_H
#define COLLISIONS_H
#include "Arduino.h"
#include "Collision.h"

class Collision {
  private:
    uint8_t** Rules;
    int size = 0;
    int isRule(uint8_t v, uint8_t x);
    void resizeMatrix(int newSize, int remove);

  public:
    void setCollision(uint8_t v, uint8_t x, bool canCollide);
    bool canCollide(uint8_t v, uint8_t x);
};

#endif