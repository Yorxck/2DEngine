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

void Object::SetPosition(Vector2 Position) {
  position = Position;
  bounds.UpdatePoints();
  onMoveCallback();
}

Vector2* Object::GetPosition() {
  return &position;
}
