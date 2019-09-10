#include "../headers/grid2d.h"

Grid2D NewGrid2D(float diff, Color color)
{
    Grid2D grid2d = {0};
    grid2d.diff = diff;
    grid2d.color = color;

    return grid2d;
}

void UpdateGrid2D(Grid2D *const grid2d)
{
    // implementar funcion
}

void DrawGrid2D(const Grid2D *const grid2d)
{
    DrawLine(1000000.0f, 0, -1000000.0f, 0, RED);
    DrawLine(0, 1000000.0f, 0, -1000000.0f, GREEN);
}

void FreeGrid2D(Grid2D *const grid2d)
{
    // implementar funcion
}