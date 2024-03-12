#ifndef ENGINE_H
#define ENGINE_H
#include "Arduino.h"
#include "Object.h"
#include "Metrics.h"
#include "Collision.h"

struct RaycastResult {
  float distance;
  Object* hit;
  Vector2 position;
};

class engine : public Collision {
  private:
    int _currentStep = 0;
  public:
    // Constructor
    engine();

    //Properties
    float gravity = 2;

    // Method
    void step(); // step forward in simulation
    void stepBack();
    void currentStep();
    RaycastResult raycast(Vector2 startPosition, Vector2 endPosition);
};

#endif
