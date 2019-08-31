#include "../headers/particle.h"
#include <stdlib.h>

const int MAX_RAY = 4;

Particle NewParticle(Vector2 position)
{
    Particle particle = {0};
    particle.position = position;
    particle.rays = (Ray2D*) malloc(sizeof(Ray2D) * MAX_RAY);
    particle.color = RAYWHITE;

    for (int index=0; index < MAX_RAY; index++)
        particle.rays[index] = NewAngleRay2D(position, (index+90));

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

void DrawParticle(const Particle *const particle)
{
    DrawCircle(particle->position.x, particle->position.y, 2.0f, particle->color);
    
    for (int index=0; index < MAX_RAY; index ++)
        DrawRay2D(&particle->rays[index]);
}

void UpdateParticle(Particle *const particle)
{
    for (int index=0; index < MAX_RAY; index ++)
        UpdateRay2D(&particle->rays[index]);
}