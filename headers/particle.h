#if !defined(PARTICLE_H)
#define PARTICLE_H

#include "raylib.h"
#include "ray.h"
#include "boundary.h"

typedef struct Particle
{
    Vector2 position;
    Ray2D *rays;
    Color color;

}Particle;

Particle NewParticle(Vector2 position);

void FreeParticle(Particle *particle);

void DrawParticle(const Particle *const particle, const Boundary *const wall);

void UpdateParticle(Particle *const particle, Vector2 mousePos);

#endif //PARTICLE_H