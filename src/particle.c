#include "../headers/particle.h"
#include <stdlib.h>

extern const int MAX_WALLS;
const int MAX_RAYS = 360; // angulo de vision del observador.

Particle NewParticle(const Vector2 position)
{
    Particle particle = {0};
    particle.position = position;

    particle.rays = (Ray2D*) malloc(sizeof(Ray2D) * MAX_RAYS);
    for (int angle=0; angle < MAX_RAYS; angle++)
        particle.rays[angle] = NewAngleRay2D(position, angle);

    return particle;
}

void UpdateParticle(Particle *const particle, const Vector2 position)
{
    // Detectar colision con pared.
    particle->position = position; // Mueve la particula segun el mouse.
    
    for (int i=0; i < MAX_RAYS; i++)
        UpdateRay2D(&particle->rays[i], position);
    
    
}

void DrawParticle(const Particle *const particle, const Boundary *const walls)
{
    Vector2 pto = {0};

    for (int iWall=0; iWall < MAX_WALLS; iWall++)
    {
        for (int i=0; i < MAX_RAYS; i++)
        {
            pto = GetIntersection(&(particle->rays[i]), &walls[iWall]);
            if (pto.x > 0)
                DrawLineRay2D(&(particle->rays[i]), pto);
        }
    }

}

void FreeParticle(Particle *const particle)
{
    if (particle->rays != NULL)
    {
        free(particle->rays);
        particle->rays = NULL;
    }
}