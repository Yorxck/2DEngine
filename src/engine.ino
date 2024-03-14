#include "engine.h"

engine simulation;

Object Square;
Object Square2;

Vector2 points[] = {
  Vector2(1, 1),
  Vector2(1, -1),
  Vector2(-1, -1),
  Vector2(-1, 1)
};

Bounds Square_Bounds(points, &Square);
Bounds Square_Bounds2(points, &Square2);

void setup() {
  Serial.begin(115200);
  Square.position = Vector2(20, 22);
  Square2.position = Vector2(21, 23);
}

void loop() {
  Vector2 hitPoint = Square_Bounds.lines[3].intersect(Square_Bounds2.lines[2]);
  Serial.println(String(hitPoint.X) + String(hitPoint.Y));
}
