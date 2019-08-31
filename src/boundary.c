#include "../headers/boundary.h"


Boundary NewBoundary(Vector2 first, Vector2 last)
{
    Boundary boundary = {0};
    boundary.first = first;
    boundary.last = last;
    boundary.color = RAYWHITE;

    return boundary;
}

void FreeBoundary(Boundary *boundary)
{

}

void DrawBoundary(const Boundary *const boundary)
{
    DrawLine(
        boundary->first.x,
        boundary->first.y,
        boundary->last.x,
        boundary->last.y,
        boundary->color
    );
}

void UpdateBoundary(Boundary *const boundary)
{

}