#include "../headers/ray2d.h"
#include "../headers/helper.h"
#include "../headers/app.h"
#include "../headers/global.h"
#include <math.h>
#include <stdio.h>

extern Global global;

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
        ray2d->position.x + (ray2d->direction.x * global.visionDistance),
        ray2d->position.y + (ray2d->direction.y * global.visionDistance),
        RAYWHITE
    );
}

void DrawLineRay2D(const Ray2D *const ray2d, const Vector2 position)
{
    DrawLine(
        ray2d->position.x,
        ray2d->position.y,
        position.x,
        position.y,
        RAYWHITE
    );
}

void FreeRay2d(Ray2D *const ray2d)
{
    //Liberacion de recursos...
}

Vector2 GetIntersectionRay2D(const Ray2D *const ray2d, const Boundary *const wall)
{
    Vector2 pto = {-1000000.0f, -1000000.0f};

    float x1 = wall->pto0.x;
    float y1 = wall->pto0.y;
    float x2 = wall->pto1.x;
    float y2 = wall->pto1.y;
    

    float x3 = ray2d->position.x;
    float y3 = ray2d->position.y;
    float x4 = ray2d->position.x + ray2d->direction.x;
    float y4 = ray2d->position.y + ray2d->direction.y;

    float d = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
    if (d == 0)
        return pto;

    float t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / d; 
    float u = ((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / d;

    if (t >= 0 && t <= 1 && u > 0)
    {
        pto.x = x1 + t * (x2 - x1);
        pto.y = y1 + t * (y2 - y1);
    }

    return pto;
}

void SetAngleRay2D(Ray2D *const ray2d, float angle)
{
    ray2d->direction = (Vector2) {
        cos(angle * DEG2RAD),
        sin(angle * DEG2RAD)
    };
}