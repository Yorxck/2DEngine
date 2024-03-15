#ifndef OBJECT_H
#define OBJECT_H
#include "Arduino.h"
#include "Bounds.h"
#include "Metrics.h"

class Object {
  protected:
    void (*onCollideCallback)(void);
    void (*onMoveCallback)(void);
    Vector2 position;

  public:
    // Constructer
    Object(Vector2 Position, Vector2 Velocity, Bounds Bounds) : position(Position), velocity(Velocity), bounds(Bounds) {}

    // Properties
    Bounds bounds;
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
    void SetPosition(Vector2 Position);
    Vector2* GetPosition();
};

class Rectangle : Object {
  public:
    // Constructer
    Rectangle(Vector2 Position, Vector2 Velocity, Vector2 Size) : Object(Position, Velocity, Bounds(Bounds::Square, &position)), size(Size) {
      bounds.Resize(Size);
    }

  private:
  Vector2 size;
};


class Triangle : Object {
  public:
    // Constructer
    Triangle(Vector2 Position, Vector2 Velocity, Vector2 size) : Object(Position, Velocity, Bounds(Bounds::Triangle, &position)) {
      bounds.Resize(size);
    }

  private:
};

class Circle : Object {
  public:
    // Constructer
    Circle(Vector2 Position, Vector2 Velocity, uint8_t radius) : Object(Position, Velocity, Bounds(Bounds::Circle, &position)) {
      bounds.Resize(Vector2(radius, radius));
    }

  private:
};

#endif
