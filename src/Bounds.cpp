#include "Bounds.h"
#include "Metrics.h"

const Vector2 Bounds::Square[4] = {
  Vector2(1, 1),
  Vector2(1, -1),
  Vector2(-1, -1),
  Vector2(-1, 1)
};

const Vector2 Bounds::Triangle[3] = {
  Vector2(0, 1),
  Vector2(1, 0),
  Vector2(-1, 0)
};

const Vector2 Bounds::Circle[12] = {
  Vector2(0, 1),
  Vector2(.5f, .866f),
  Vector2(.866f, .5f),
  Vector2(1, 0),
  Vector2(.866f, -.5f),
  Vector2(.5f, -.866f),
  Vector2(0, -1),
  Vector2(.5f, -.866f),
  Vector2(-.866f, -.5f),
  Vector2(-1, 0),
  Vector2(-.866f, .5f),
  Vector2(-.5f, .866f),
};

Bounds::Bounds(Vector2 PointsOffset[], Vector2* Center) {
  center = Center;
  uint8_t pointAmount = sizeof(PointsOffset) / sizeof(int);
  points[pointAmount];
  memcpy(&pointsOffset, &PointsOffset, pointAmount);
  delete[] PointsOffset;

  lines[pointAmount];
  for (int i = 0; i < pointAmount; i++) {
    points[i] = pointsOffset[i] + *center;
    if (i == pointAmount - 1) {
      lines[i] = Line(&points[i], &points[0]);
      break;
    }

    lines[i] = Line(&points[i], &points[i + 1]);
  }
}

void Bounds::RecalculateCollisionLines(Vector2 direction) {
    uint8_t lineAmount = sizeof(lines) / sizeof(int);

    for(int i = 0; i < lineAmount; i++) {
        
    } 
}

bool Bounds::IsColliding(Bounds bounds, Vector2* hitPoint) {
    

  return false;
}

void Bounds::UpdatePoints() {
  uint8_t pointAmount = sizeof(points) / sizeof(int);

  for (int i = 0; i < pointAmount; i++) {
    points[i] = pointsOffset[i] + *center;
  }
}

void Bounds::Resize(Vector2 size) {
  size /= 2;
  uint8_t pointAmount = sizeof(pointsOffset) / sizeof(int);

  for (int i = 0; i < pointAmount; i++) 
     pointsOffset[i] *= size;
  
  UpdatePoints();
}