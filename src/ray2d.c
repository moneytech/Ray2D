#include "../headers/ray2d.h"
#include "../headers/helper.h"
#include "../headers/app.h"
#include <math.h>

extern App *globalApp;

static void __freeApp()
{
    globalApp->close = true;
}

Ray2D NewRay2D(Vector2 position, Vector2 direction)
{
    Ray2D ray2d = {0};
    ray2d.position = position;
    
    Result result = UnitVectorHelper(
        position,
        direction
    );

    if (!result.ok)
        __freeApp();

    return ray2d;
}

// Crea una instancia de Ray2D a partir de un angulo
// en grando.
Ray2D NewAngleRay2D(Vector2 position, float angle)
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

void UpdateRay2D(Ray2D *const ray2d)
{

}

void DrawRay2D(const Ray2D *const ray2d)
{

}

void FreeRay2d(Ray2D *ray2d)
{

}