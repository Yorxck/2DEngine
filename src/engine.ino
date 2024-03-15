#include "engine.h"

void setup() {
  Serial.begin(9600);
  Vector2 a = Vector2(2, 2);
  IVector2 b = IVector2(4, 4); // new IntVector2 struct;

  b = a; // you can convert IntVector2 to Vector2 and vice versa;

  Serial.println(b.X);
  Serial.println(b.Y);
}

void loop() {

}
