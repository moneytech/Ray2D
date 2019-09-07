#if !defined(RAY2D_H)
#define RAY2D_H

#include "raylib.h"
#include "boundary.h"

typedef struct Ray2D
{
    Vector2 position;
    Vector2 direction;

    float angle;

}Ray2D;

Ray2D NewRay2D(const Vector2 position, const Vector2 direction);

Ray2D NewAngleRay2D(const Vector2 position, float angle);

void UpdateRay2D(Ray2D *const ray2d, const Vector2 position);

void DrawRay2D(const Ray2D *const ray2d);

void FreeRay2d(Ray2D *const ray2d);

Vector2 GetIntersection(const Ray *const ray2d, const Boundary *const wall);

#endif //RAY2D_H