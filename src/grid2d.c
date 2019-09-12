#include "../headers/grid2d.h"
#include "../headers/boundary.h"
#include "../headers/global.h"
#include <stdio.h>

extern Boundary **globalWalls;
extern Global global;
extern int MAX_WALLS; // MAX_WALLS debe tener un valor >= a 4.

float distance = 0; 
float x = 0;
float y = 0;

//******************************************************************
//******************FIRMAS DE FUNCIOANES STATIC*********************
//******************************************************************
static void __WallsLimitGrid2D(int slices);
//******************************************************************
//*********************IMPLEMENTACION DE FUNCIONES******************
//******************************************************************
Grid2D NewGrid2D(int slices, Color color)
{
    Grid2D grid2d = {0};
    grid2d.slices = slices;
    grid2d.color = color;

    // Crea el limite del mapa para el
    // jugador.
    __WallsLimitGrid2D(slices);

    return grid2d;
}

void UpdateGrid2D(Grid2D *const grid2d)
{
    // implementar funcion
}

void DrawGrid2D(const Grid2D *const grid2d)
{
    for (int i=0; i < grid2d->slices + 1; i++)
    {
        DrawLine(-x, (i * global.spaceGrid2D) - y, x, (i * global.spaceGrid2D) - y, grid2d->color); // horizontal
        DrawLine((i * global.spaceGrid2D) - x, -y, (i * global.spaceGrid2D) - x, y, grid2d->color); // vertical
    }

    DrawLine(x, 0, -x, 0, RED); // linea del eje x
    DrawLine(0, y, 0, -y, GREEN); // linea del eje y
}

void FreeGrid2D(Grid2D *const grid2d)
{
    // implementar funcion
}

static void __WallsLimitGrid2D(int slices)
{
    distance = (slices * global.spaceGrid2D);
    x = distance / 2;
    y = distance / 2;

    // limite superior.
    globalWalls[0][0] = NewBoundary(
        (Vector2) {-x, -y},
        (Vector2) {x, -y}
    );

    // limite inferior.
    (*globalWalls)[MAX_WALLS - 3] = NewBoundary(
        (Vector2) {-x, y},
        (Vector2) {x, y}
    );

    // limite izquierdo.
    (*globalWalls)[MAX_WALLS - 2] = NewBoundary(
        (Vector2) {-x, y},
        (Vector2) {-x, -y}
    );

    // limite derecho.
    (*globalWalls)[MAX_WALLS - 1] = NewBoundary(
        (Vector2) {x, y},
        (Vector2) {x, -y}
    );
}