#include "../headers/ray.h"
#include <math.h>

Ray2D NewRay2D(Vector2 position, Vector2 direction)
{
    Ray2D ray = {0};
    ray.position = position;
    ray.direction = direction;
    ray.color = RAYWHITE;

    return ray;
}

Ray2D NewAngleRay2D(Vector2 position, float angle)
{
    Ray2D ray = {0};
    ray.position = position;

    ray.direction = (Vector2) {
        cos(angle),
        sin(angle)
    };

    ray.color = RAYWHITE;

    return ray;
}

void FreeRay2D(Ray2D *ray)
{

}

void UpdateRay2D(Ray2D *const ray, Vector2 position)
{
    ray->position = position;
}

void DrawRay2D(const Ray2D *const ray)
{
    DrawLine(
        ray->position.x, 
        ray->position.y, 
        ray->position.x + ray->direction.x * 10, 
        ray->position.y + ray->direction.y * 10, 
        ray->color
    );
}

Result CastRay2D(const Ray2D *const ray, const Boundary *const wall)
{
    Vector2 pto = (Vector2) {-1, -1};
    
    float x1 = wall->first.x;
    float y1 = wall->first.y;
    float x2 = wall->last.x;
    float y2 = wall->last.y;

    float x3 = ray->position.x;
    float y3 = ray->position.y;
    float x4 = ray->position.x + ray->direction.x;
    float y4 = ray->position.y + ray->direction.y;

    float den = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
    if (den == 0)
        return NewResult(0);

    float t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / den;
    float u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / den;

    if (0 < t && t < 1 && u > 0)
    {
        pto.x = x1 + t * (x2 - x1);
        pto.y = y1 + t * (y2 - y1);

        return NewResult(pto);
    }
    
    return NewResult(0);
}

void LookAtRayCastion(Ray2D *const ray, Vector2 position)
{
    ray->direction.x = position.x - ray->position.x;
    ray->direction.y = position.y - ray->position.y;

    float x = pow(ray->direction.x, 2);
    float y = pow(ray->direction.y, 2);
    float mag = sqrt(x + y);

    if (mag != 0)
    {
        ray->direction.x = ray->direction.x / mag;
        ray->direction.y = ray->direction.y / mag;
    }
}