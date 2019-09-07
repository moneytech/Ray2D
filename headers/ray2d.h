#if !defined(RAY2D_H)
#define RAY2D_H

#include "raylib.h"


typedef struct Ray2D
{
    Vector2 position;
    Vector2 direction;

    float angle;

}Ray2D;

Ray2D NewRay2D(Vector2 position, Vector2 direction);

Ray2D NewAngleRay2D(Vector2 position, float angle);

void UpdateRay2D(Ray2D *const ray2d);

void DrawRay2D(const Ray2D *const ray2d);

void FreeRay2d(Ray2D *ray2d);

#endif //RAY2D_H