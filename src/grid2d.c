#include "../headers/grid2d.h"
#include "../headers/boundary.h"
#include "../headers/global.h"
#include <stdio.h>
#include <stdlib.h>

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
static void __ResizeWindowUpdateGrid2D(Grid2D *const grid2d);

static void __InitSquaresGrid2D(Grid2D *const grid2d);
static void __DrawSquaresGrid2D(const Grid2D *const grid2d);
static void __UpdateSquaresGrid2D(const Grid2D *const grid2d);
//******************************************************************
//*********************IMPLEMENTACION DE FUNCIONES******************
//******************************************************************
Grid2D NewGrid2D(int slices, Color color)
{
    Grid2D grid2d = {0};
    grid2d.slices = slices;
    grid2d.color = color;
    grid2d.sizeWindow = GetScreenGlobal(&global);

    // Inicializamos la matriz de Squares.
    grid2d.squares = (Square**) malloc(sizeof(Square*) * slices);
    for (int i=0; i < grid2d.slices; i++)
        grid2d.squares[i] = (Square*) malloc(sizeof(Square) * slices);

    // Crea el limite del mapa para el
    // jugador.
    __WallsLimitGrid2D(slices);
    __InitSquaresGrid2D(&grid2d);

    return grid2d;
}

void UpdateGrid2D(Grid2D *const grid2d)
{
    __ResizeWindowUpdateGrid2D(grid2d);
    __UpdateSquaresGrid2D(grid2d);
}

void DrawGrid2D(const Grid2D *const grid2d)
{
    // Dibuja la matriz de Squares.
    __DrawSquaresGrid2D(grid2d);
    
    DrawLine(x*2, 0, -x*2, 0, RED); // linea del eje x
    DrawLine(0, y*2, 0, -y*2, GREEN); // linea del eje y
}

void FreeGrid2D(Grid2D *const grid2d)
{
    if (grid2d->squares != NULL)
    {
        for (int i=0; i < grid2d->slices; i++)
        {
            free(grid2d->squares[i]);
            grid2d->squares[i] = NULL;
        }

        free(grid2d->squares);
        grid2d->squares = NULL;
    }
}

//******************************************************************
//****************IMAPLEMENTACION FUNCIOANES STATIC*****************
//******************************************************************
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

static void __ResizeWindowUpdateGrid2D(Grid2D *const grid2d)
{
    int screenWidth = GetScreenWidthGlobal(&global);
    int screenHeight = GetScreenHeightGlobal(&global);

    if (grid2d->sizeWindow.x != screenWidth || grid2d->sizeWindow.y != screenHeight)
    {
        grid2d->sizeWindow.x = screenWidth;
        grid2d->sizeWindow.y = screenHeight;
    }
}

static void __InitSquaresGrid2D(Grid2D *const grid2d)
{
    float space = 32;
    distance = (grid2d->slices * global.spaceGrid2D);

    float _x = -x;
    float _y = -y;

    for(int i=0; i < grid2d->slices; i++)
    {
        for (int j=0; j < grid2d->slices; j++)
        {
            grid2d->squares[i][j] = NewSquare(_x, _y, space, BLACK);
            _x += space;
        }
        _y += space;
        _x = -x;
    }
}

static void __DrawSquaresGrid2D(const Grid2D *const grid2d)
{
    for (int i=0; i < grid2d->slices; i++)
    {
        for (int j=0; j < grid2d->slices; j++)
            DrawSquare(&grid2d->squares[i][j]);
    }
}

static void __UpdateSquaresGrid2D(const Grid2D *const grid2d)
{
    for (int i=0; i < grid2d->slices; i++)
    {
        for (int j=0; j < grid2d->slices; j++)
            UpdateSquare(&grid2d->squares[i][j]);
    }
}
