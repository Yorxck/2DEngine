#include "Arduino.h"
#include "Object.h"
#include "Metrics.h"
#include "engine.h"

// engine functions
long engine::currentStep() {
  return _currentStep;
}

void engine::step() {
  if ((millis() - _lastupdated) > 1000) {
    _lastupdated = millis(); // reset tmr
    _fps = _stepcount;
    _stepcount = 0;
  }
  _currentStep++;
  _stepcount++;
}

uint16_t engine::fps() {
  return _fps;
}