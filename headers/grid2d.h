#if !defined(GRID_H)
#define GRID_H

#include "raylib.h"

typedef struct Grid2D {
    float diff;
    Color color;

}Grid2D;

Grid2D NewGrid2D(float diff, Color color);

void UpdateGrid2D(Grid2D *const grid2d);

void DrawGrid2D(const Grid2D *const grid2d);

void FreeGrid2D(Grid2D *const grid2d);

#endif //GRID_H