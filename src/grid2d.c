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
    int space = 20;
    for (int i=0; i < 50.0f; i++) {
        DrawLine(0, i * space, 1000.0f, i * space, GRAY);
        
        for (int j=0; j < 50.0f; j++)
            DrawLine(j * space, 0, j * space, 1000.0f, GRAY);
    }
}

void FreeGrid2D(Grid2D *const grid2d)
{
    // implementar funcion
}