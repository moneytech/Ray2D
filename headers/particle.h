#if !defined(PARTICLE_H)
#define PARTICLE_H

#include "raylib.h"
#include "ray2d.h"

typedef struct Particle
{
    Vector2 position;
    Ray2D *rays;
    Color color;

}Particle;

Particle NewParticle(const Vector2 position);

void UpdateParticle(Particle *const particle, const Vector2 position);

void DrawParticle(const Particle *const particle, const Boundary *const walls);

void FreeParticle(Particle *const particle);

#endif //PARTICLE_H