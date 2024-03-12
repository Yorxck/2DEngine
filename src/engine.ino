#include "Metrics.h"

void setup() {
  Serial.begin(9600);
  Vector2 a = Vector2::one;
  a.normalize();

  Serial.print(a.X);
  Serial.println(a.Y);
}

void loop() {

}
