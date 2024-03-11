#ifndef ENGINE_H
#define ENGINE_H
#include "Arduino.h"
#include "Object.h"
#include "Metrics.h"

class engine {
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
}

#endif