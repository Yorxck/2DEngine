#include "Bounds.h"
#include "Metrics.h"

Bounds::Bounds(Vector2 Points[], Object* Object) {
	uint8_t pointAmount = sizeof(Points) / sizeof(int);
	points[pointAmount];
  memcpy(&points, &Points, pointAmount);
  delete[] Points;

  lines[pointAmount];
	for (int i = 0; i < pointAmount; i++) {
    points[i] += object->position;

		if (i == pointAmount - 1) {
			lines[i] = Line(&points[i], &points[0], &object->position);
			break;
		}

		lines[i] = Line(&points[i], &points[i + 1], &object->position);
	}
}

bool Bounds::IsColliding(Bounds bounds, Vector2* hitPoint) {

	return false;
}