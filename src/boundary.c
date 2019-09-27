#include "../headers/boundary.h"
#include "../headers/global.h"
#include <stdio.h>

extern Global global;

Boundary NewBoundary(const Vector2 pto0, const Vector2 pto1)
{
    Boundary boundary = {0};
    boundary.pto0 = pto0;
    boundary.pto1 = pto1;
    boundary.color = global.color2;

    return boundary;
}

void UpdateBoundary(Boundary *const boundary)
{
    if (boundary->color.a != global.color2.a)
        boundary->color = global.color2; 
}

void DrawBoundary(const Boundary *const boundary)
{
    if (global.section == CANVAS)
        DrawLine(
            boundary->pto0.x,
            boundary->pto0.y,
            boundary->pto1.x,
            boundary->pto1.y,
            boundary->color
        );
}

void FreeBoundary(Boundary *const boundary)
{
    //Liberear los recursos reservados.
}