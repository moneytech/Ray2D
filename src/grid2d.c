#include "../headers/grid2d.h"

Grid2D NewGrid2D(int slices, Color color)
{
    Grid2D grid2d = {0};
    grid2d.slices = slices;
    grid2d.color = color;

    return grid2d;
}

void UpdateGrid2D(Grid2D *const grid2d)
{
    // implementar funcion
}

void DrawGrid2D(const Grid2D *const grid2d)
{
    int diff = 30;
    float distance = (grid2d->slices * diff);
    float x = distance / 2;
    float y = distance / 2;

    for (int i=0; i < grid2d->slices + 1; i++)
    {
        DrawLine(-x, (i * diff) - y, x, (i * diff) - y, grid2d->color); // horizontal
        DrawLine((i * diff) - x, -y, (i * diff) - x, y, grid2d->color); // vertical
    }

    DrawLine(x, 0, -x, 0, RED); // linea del eje x
    DrawLine(0, y, 0, -y, GREEN); // linea del eje y
}

void FreeGrid2D(Grid2D *const grid2d)
{
    // implementar funcion
}