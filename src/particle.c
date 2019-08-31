#include "../headers/particle.h"
#include <stdlib.h>
#include <math.h>

const int MAX_RAY = 360;

static float __distance(Vector2 pto0, Vector2 pto1);

Particle NewParticle(Vector2 position)
{
    Particle particle = {0};
    particle.position = position;
    particle.rays = (Ray2D*) malloc(sizeof(Ray2D) * MAX_RAY);
    particle.color = RAYWHITE;

    for (int index=0; index < MAX_RAY; index++)
        particle.rays[index] = NewAngleRay2D(position, (index));

    return particle;
}

void FreeParticle(Particle *particle)
{
    if (particle->rays != NULL)
    {
        free(particle->rays);
        particle->rays = NULL;
    }
}

void DrawParticle(const Particle *const particle, const Boundary *const walls)
{
    DrawCircle(particle->position.x, particle->position.y, 2.0f, particle->color);
    Result result = {0};

    Vector2 closest = (Vector2) {-1.0f, -1.0f};

    for (int index=0; index < MAX_RAY; index++)
    {
        float record = 100000000.0f;

        for (int iWall=0; iWall < 4; iWall++)
        {
            DrawRay2D(&particle->rays[index]);
            result = CastRay2D(&particle->rays[index], &walls[iWall]);
            if (result.ok)
            {
                float d = __distance(particle->position, *((Vector2*) result.value));
                if (d < record)
                {
                    record = d;
                    closest = *((Vector2*) result.value);
                }
            }

        }
        if (closest.x > 0)
            DrawLine(
                particle->position.x,
                particle->position.y,
                closest.x,
                closest.y,
                particle->color
            );
    }
}

void UpdateParticle(Particle *const particle, Vector2 mousePos)
{
    particle->position = mousePos;

    for (int index=0; index < MAX_RAY; index ++)
        UpdateRay2D(&particle->rays[index], particle->position);
}

static float __distance(Vector2 pto0, Vector2 pto1)
{
    float a = pow(pto0.x - pto1.x, 2);
    float b = pow(pto0.y - pto1.y, 2);
    float c =  sqrt(a + b);
    
    return c;
}
