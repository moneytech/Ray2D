#if !defined (BOUNDARY_H)
#define BOUNDARY_H

#include "raylib.h"

typedef struct Boundary
{
    Vector2 pto0;
    Vector2 pto1;
    Color color;
}Boundary;

Boundary NewBoundary(const Vector2 pto0, const Vector2 pto1);

void UpdateBoundary(Boundary *const boundary);

void DrawBoundary(const Boundary *const boundary);

void FreeBoundary(Boundary *const boundary);

#endif //BOUNDARY_H