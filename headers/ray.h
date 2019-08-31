#if !defined(Ray2D)
#define RAY_H

#include <stdlib.h>
#include "raylib.h"
#include "boundary.h"
#include "result.h"

typedef struct Ray2D
{
    Vector2 position;
    Vector2 direction;
    Color color;

}Ray2D;

Ray2D NewRay2D(Vector2 position, Vector2 direction);

Ray2D NewAngleRay2D(Vector2 position, float angle);

void FreeRay2D(Ray2D *ray);

void UpdateRay2D(Ray2D *const ray, Vector2 position);

void DrawRay2D(const Ray2D *const ray);

Result CastRay2D(const Ray2D *const ray, const Boundary *const wall); 

void LookAtRayCastion(Ray2D *const ray, Vector2 position);

#endif //RAY_H