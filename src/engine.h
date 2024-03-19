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
    long _currentStep = 0;
    uint16_t _fps;
    uint16_t _stepcount;
    long _lastupdated = -1000;

  public:
    // Constructor
    engine();

    //Properties
    float gravity = 2;
    bool useRotations = false;

    // Method
    void step(); // step forward in simulation
    void stepBack();
    long currentStep();
    uint16_t fps();
    RaycastResult raycast(Vector2 startPosition, Vector2 endPosition);
};

#endif
