# 2D Engine for arduino

this is a library to create 2d games and detect collisions between diffirent obejcts.

## Features
> Collision layers

## Documentation

## engine

### Basics
to include and initialize the library you can do the following
```cpp
#include "engine.h"

engine simulation;
```

to get the current fps the engine is running at you can use
```cpp
uint16_t fps = simulation.fps();
```

### Collision layers
to set a collision rule you need to use the setCollision function as following
```cpp
uint8_t CollisionLayer1 = 0;
uint8_t CollisionLayer2 = 1;
bool canCollide = false;

simulation.setCollision(CollisionLayer1, CollisionLayer2, canCollide);
```
