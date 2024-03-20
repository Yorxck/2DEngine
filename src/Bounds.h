#ifndef BOUNDS.H
#include "Metrics.h"

class Bounds {
public:
  // Constructer
  Bounds() {}
  Bounds(Vector2 Points[], Vector2* Center);
  
  // Static 
  static const Vector2 Square[4];
  static const Vector2 Triangle[3];
  static const Vector2 Circle[12];

  // Methods
  bool IsColliding(Bounds bounds, Vector2* hitPoint);
  void UpdatePoints();
  void Resize(Vector2 size);
  void RecalulateCollisionLines(Vector2* direction);

  private:
  // Properties
  Vector2* center;
  Vector2 points[0];
  Vector2 pointsOffset[0];
  Line* collisionLines;
  Line lines[];
};

#endif