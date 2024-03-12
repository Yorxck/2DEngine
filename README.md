# 2D Engine for arduino

## Features
> Collision layers

## Documentation

### Collision layers
to set a collision rule you need to use the setCollision function as following
```cpp
#include "engine.h"

engine simulation;

uint8_t CollisionLayer1 = 0;
uint8_t CollisionLayer1 = 1;

simulation.setCollision(0, 1, true)
```
