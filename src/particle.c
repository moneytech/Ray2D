#include "../headers/particle.h"
#include <stdlib.h>

const int MAX_RAY = 360;

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

void DrawParticle(const Particle *const particle, const Boundary *const wall)
{
    DrawCircle(particle->position.x, particle->position.y, 2.0f, particle->color);
    Result result = {0};

    for (int index=0; index < MAX_RAY; index ++)
    {
        DrawRay2D(&particle->rays[index]);
        result = CastRay2D(&particle->rays[index], wall);
        if (result.ok)
        {
            DrawLine(
                particle->position.x,
                particle->position.y,
                ((Vector2*) result.value)->x,
                ((Vector2*) result.value)->y,
                particle->color
            );
        } 
    }
}

void UpdateParticle(Particle *const particle, Vector2 mousePos)
{
    particle->position = mousePos;

    for (int index=0; index < MAX_RAY; index ++)
        UpdateRay2D(&particle->rays[index], particle->position);
}