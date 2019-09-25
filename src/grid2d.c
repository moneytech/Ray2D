#include "../headers/grid2d.h"
#include "../headers/boundary.h"
#include "../headers/global.h"
#include "../headers/list.h"
#include <stdio.h>
#include <stdlib.h>

extern Global global;

float distance = 0; 
float x = 0;
float y = 0;

const int SIZE_LINE = 5;

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
    
    DrawLine(x*SIZE_LINE, 0, -x*SIZE_LINE, 0, OVE_COLOR1); // linea del eje x
    DrawLine(0, y*SIZE_LINE, 0, -y*SIZE_LINE, OVE_COLOR1);// linea del eje y
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

void InitLimitWallsGrid2D(Grid2D *const grid2d)
{
    Node node = NewNode(4, -1);

    // // limite superior.
    Boundary boundary = NewBoundary(
        (Vector2) {-x, -y},
        (Vector2) {x, -y}
    );
    AddElementNode(&node, boundary, 0);

    // // limite inferior.
    boundary = NewBoundary(
        (Vector2) {-x, y},
        (Vector2) {x, y}
    );
    AddElementNode(&node, boundary, 1);

    // // limite izquierdo.
    boundary = NewBoundary(
        (Vector2) {-x, y},
        (Vector2) {-x, -y}
    );
    AddElementNode(&node, boundary, 2);

    // // limite derecho.
    boundary = NewBoundary(
        (Vector2) {x, y},
        (Vector2) {x, -y}
    );
    AddElementNode(&node, boundary, 3);

    // almacena el nodo en la lista de paredes.
    AddElementList(&(global.listWalls), node);
}


//******************************************************************
//****************IMAPLEMENTACION FUNCIOANES STATIC*****************
//******************************************************************
static void __WallsLimitGrid2D(int slices)
{
    distance = (slices * global.spaceGrid2D);
    x = distance / 2;
    y = distance / 2;

    
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
    float space = global.spaceGrid2D;
    distance = (grid2d->slices * global.spaceGrid2D);

    float _x = -x;
    float _y = -y;
    int count = 0;
    for(int i=0; i < grid2d->slices; i++)
    {
        for (int j=0; j < grid2d->slices; j++)
        {
            grid2d->squares[i][j] = NewSquare(_x, _y, space, OVE_COLOR2, count);
            count++;
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
