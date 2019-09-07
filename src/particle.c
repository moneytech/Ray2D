#include "../headers/particle.h"
#include "../headers/helper.h"
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
    float max = 1000000000.f;
    Vector2 pto = {0};
    bool flag = false;

    for (int i=0; i < MAX_RAYS; i++)
    {
        max = 1000000000.f;
        flag = false;

        for (int iWall=0; iWall < MAX_WALLS; iWall++)
        {
            Vector2 auxPoint = GetIntersection(&(particle->rays[i]), &walls[iWall]);
            if (auxPoint.x > 0)
           {
               float distance = Distance(particle->rays[i].position, auxPoint);
                if (distance < max)
                {
                    max = distance;
                    pto = auxPoint;
                    flag = true;
                }
           }
        }

        if (flag)
            DrawLineRay2D(&particle->rays[i], pto);
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