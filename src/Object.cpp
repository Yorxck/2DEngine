#include "Arduino.h"
#include "Metrics.h"
#include "Object.h"

// Object functions
void Object::onCollide(Callback _callback) {
  callback = _callback;
}
