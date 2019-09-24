#include "../headers/global.h"
#include "../headers/ocamera.h"
#include <stdlib.h>

extern OCamera *ocamera;

Global NewGlobal()
{
    Global global = {0};
    
    // configuraciones para la ventana.
    global.section = CANVAS; // inicializa en la seccion canvas.
    global.screenWidth = 810; // ancho de la ventana.
    // global.screenWidth = 900; // ancho de la ventana.
    global.screenHeight = 600; // altura de la ventana.
    // global.screenHeight = 700; // altura de la ventana.
    global.title = "Overflow::Engine"; // titulo de la app.
    global.fps = 60;
    
    // configuraciones para el player.
    global.velocityPlayer = 2.09; // velocidad de desplazamiento del player.
    global.visionAngle = 45.0f;
    global.posPlayer = NULL;
    global.diffAngle = PI/8; // P/6
    global.visionDistance = 1000.0f; // distancia de vision del player.

    // configuraciones para la grilla.
    global.spaceGrid2D = 32; 
    global.numLinesGrid2D = 16;

    global.keySectionCanvas = KEY_F1;
    global.keySectionMap = KEY_F2;

    global.walls = NULL;
    global.maxWalls = 1000 + 4;
    global.countWalls = 0;

    global.listWalls = NewList();

    return global;
}

const int GetScreenWidthGlobal(const Global *const global)
{
    return global->screenWidth;
}

const int GetScreenHeightGlobal(const Global *const global)
{
    return global->screenHeight;
}

const Vector2 GetScreenGlobal(const Global *const global)
{
    return (Vector2) {
        (int) GetScreenWidthGlobal(global),
        (int) GetScreenHeightGlobal(global)
    };
}

const int GetFPSGlobal(const Global *const global)
{
    return global->fps;
}

const char *GetTitleGlobal(const Global *const global)
{
    return global->title;
}

void SetSectionGlobal(Global *const global, Section section)
{
    global->section = section;
}

Section GetCurrentSectionGlobal(const Global *const global)
{
    return global->section;
}

Vector2 GetMousePositionGlobal(const Global *const global)
{
    Vector2 mousePosition = GetMousePosition();
    
    int _x = (mousePosition.x + global->posPlayer->x) - (GetScreenWidthGlobal(global) / 2);
    int _y = (mousePosition.y + global->posPlayer->y) - (GetScreenHeightGlobal(global) / 2); 

    return (Vector2) {
        _x,
        _y
    };
}

void UpdateCenterGlobal(Global *const global)
{
    // Falta implementar.
}

void FreeGlobal(Global *const global)
{
    FreeList(&(global->listWalls));
}