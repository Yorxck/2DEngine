#include "Arduino.h"
#include "Metrics.h"
#include "Object.h"

// Object functions
void Object::onCollide(void (*func)(void)) {
  Callback = func;
}