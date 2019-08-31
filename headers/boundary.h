#if !defined(BOUNDARY_H)
#define BOUNDARY_H

#include "raylib.h"

typedef struct Boundary
{
    Vector2 first;
    Vector2 last;
    Color color;

}Boundary;

Boundary NewBoundary(Vector2 first, Vector2 last);

void FreeBoundary(Boundary *boundary);

void UpdateBoundary(Boundary *const boundary);

void DrawBoundary(const Boundary *const boundary);

#endif //BOUNDARY_H