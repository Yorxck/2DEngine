#include "Metrics.h"
#include "Object.h"

class Bounds {
public:
	Bounds(Vector2 Points[], Object* Object);
	bool IsColliding(Bounds bounds, Vector2* hitPoint);

private:
	Object* object;
    Vector2 points[0];
	Line lines[];
};