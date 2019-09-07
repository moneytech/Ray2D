#include "../headers/boundary.h"


Boundary NewBoundary(const Vector2 pto0, const Vector2 pto1)
{
    Boundary boundary = {0};
    boundary.pto0 = pto0;
    boundary.pto1 = pto1;
    boundary.color = RAYWHITE;

    return boundary;
}

void UpdateBoundary(Boundary *const boundary)
{
    //Actualizar Boundary.
}

void DrawBoundary(const Boundary *const boundary)
{
    DrawLine(
        boundary->pto0.x,
        boundary->pto0.y,
        boundary->pto1.x,
        boundary->pto1.y,
        boundary->color
    );
}

void FreeBoundary(const Boundary *const boundary)
{
    //Liberear los recursos reservados.
}