#include "Arduino.h"
#include "Collision.h"

int Collision::isRule(uint8_t v, uint8_t x) {
  for (int i = 0; i < size; i++) {
    if ((Rules[i][0] == v && Rules[i][1] == x) || (Rules[i][0] == x && Rules[i][1] == v)) {
      return i;
    }
  }
  return -1;
}

void Collision::resizeMatrix(int newSize, int remove) {
  uint8_t** tmp = new uint8_t*[newSize];

  for (int i, l = 0; i < size; i++) {
    if (i != remove) {
      l++;
      tmp[l] = new uint8_t[2];

      for (int j = 0; j < 2; j++) {
        tmp[l][j] = Rules[i][j]; 
      }

      delete Rules[i];
    }
  }

  delete[] Rules;
  Rules = tmp;
  size = newSize;
}

void Collision::setCollision(uint8_t v, uint8_t x, bool _canCollide) {
  if (_canCollide && canCollide(v, x)) return; // No need to change anything, default rule is collideable
  else if (!_canCollide && !canCollide(v, x)) return; // rule already defined
  else if (_canCollide && !canCollide(v, x)) {
    resizeMatrix(size - 1, isRule(v, x)); // removes before non collideable rule
    return;
  }

  resizeMatrix(size + 1, -1); // -1 for no deletion
  uint8_t* insert = new uint8_t[2] {v, x};
  Rules[size - 1] = insert; // adds new rule to rules
}

bool Collision::canCollide(uint8_t v, uint8_t x) {
  return (isRule(v, x) < 0);
}
