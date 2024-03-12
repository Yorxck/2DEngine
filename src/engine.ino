#include "engine.h"

engine simulation;

void setup() {
  Serial.begin(9600);

  simulation.setCollision(1, 2, false);
  simulation.setCollision(1, 2, true);

  Serial.println(simulation.canCollide(2, 1));
}

void loop() {

}
