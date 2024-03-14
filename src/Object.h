#ifndef OBJECT_H
#define OBJECT_H
#include "Arduino.h"
#include "Metrics.h"

class Object {
  protected:
    void (*onCollideCallback)(void);
    void (*onMoveCallback)(void);

  public:
    // Properties
    Vector2 position;
    Vector2 velocity;
    float rotation;
    float mass;
    float bounciness = 1;
    bool anchored = true;
    bool gravity = false;
    uint8_t collisionLayer;

    // Methods
    void onMove(void(*func)());
    void onCollide(void (*func)(void));
};

class Rectangle : public Object {
  private:

  public:
    // Constructors
    Rectangle(Vector2 _position, Vector2 _size) : position(_position), size(_size) {}

    // Properties
    Vector2 position;
    Vector2 size;
};

#endif
