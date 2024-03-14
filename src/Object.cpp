#include "Arduino.h"
#include "Metrics.h"
#include "Object.h"

// Object functions
void Object::onCollide(void (*func)(void)) {
  onCollideCallback = func;
}

void Object::onMove(void (*func)(void)) {
  onMoveCallback = func;
}