#include "../headers/ray2d.h"
#include "../headers/helper.h"
#include "../headers/app.h"
#include <math.h>
#include <stdio.h>

const int LENGTH = 100;

Ray2D NewRay2D(const Vector2 position, const Vector2 direction)
{
    Ray2D ray2d = {0};
    ray2d.position = position;
    
    Result result = UnitVectorHelper(
        position,
        direction
    );

    ray2d.direction = result.pto;

    return ray2d;
}

// Crea una instancia de Ray2D a partir de un angulo
// en grando.
Ray2D NewAngleRay2D(const Vector2 position, float angle)
{
    Ray2D ray2d = {0};
    ray2d.position = position;
    ray2d.angle = angle * DEG2RAD;

    // direccion del vector
    ray2d.direction = (Vector2) {
        cos(ray2d.angle),
        sin(ray2d.angle)
    };

    return ray2d;
}

void UpdateRay2D(Ray2D *const ray2d, const Vector2 position)
{
    ray2d->position = position;
}

void DrawRay2D(const Ray2D *const ray2d)
{
    DrawLine(
        ray2d->position.x,
        ray2d->position.y,
        ray2d->position.x + (ray2d->direction.x * LENGTH),
        ray2d->position.y + (ray2d->direction.y * LENGTH),
        RAYWHITE
    );
}

void FreeRay2d(Ray2D *const ray2d)
{
    //Liberacion de recursos...
}