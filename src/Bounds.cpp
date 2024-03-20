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

void Bounds::RecalulateCollisionLines(Vector2* direction) {
  uint8_t lineAmount = sizeof(lines) / sizeof(int);

  bool started;
  uint8_t startIndex, endIndex;

  for (uint8_t i = 0; i < lineAmount; i++) {
    if (lines[i].getNormal(center).dot(*direction) > 0) {
      if(!started) {
        startIndex = i;
        started = true;
        continue;
      } 
      else 
        endIndex = i;
    }
  }

  collisionLines[endIndex - startIndex + 1];
  uint8_t index;
  for(uint8_t i = startIndex; startIndex <= endIndex; startIndex++) {
    collisionLines[index] = lines[startIndex];
    index++;
  }
}

bool Bounds::IsColliding(Bounds bounds, Vector2* hitPoint) {
  uint8_t collisionLineAmount = sizeof(collisionLines) / sizeof(int);

  auto isInBounds = [&] (Vector2 point) {
    Vector2 directionToPoint = point.operator-(*bounds.center);

    uint8_t lineAmount = sizeof(bounds.lines) / sizeof(int);
    float closestDot = 0;
    Line* lineToCheck;

    for(uint8_t i = 0; i < lineAmount; i++) {
      float dot = directionToPoint.dot(lines[i].getNormal(bounds.center));
      if(dot > closestDot) {
        closestDot = dot;
        lineToCheck = &lines[i];
      }
    }

    Line lineToObject(&point, bounds.center);
    if(lineToObject.intersect(*lineToCheck) == Vector2::zero) 
      return false;
    
    return true;
  };

  for (uint8_t i = 0; i < collisionLineAmount; i++) {
    if(isInBounds(*collisionLines[i].start) || isInBounds(*collisionLines[i].end))
        return true;

    if(collisionLines[i].getSize() > 1) {
      Vector2* points = collisionLines[i].getPointsAlongLine();
      uint8_t pointAmount = sizeof(points) / sizeof(int);

      for(uint8_t o = 0; o < pointAmount; o++) {
        if(isInBounds(points[o]))
          return true;
      }
    } 
  }

  return false;
}



void Bounds::UpdatePoints() {
  uint8_t pointAmount = sizeof(points) / sizeof(int);

  for (uint8_t i = 0; i < pointAmount; i++) {
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