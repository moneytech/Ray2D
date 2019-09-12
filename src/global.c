#include "../headers/global.h"
#include "raylib.h"

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
    global.diffAngle = PI/8; // P/6
    global.visionDistance = 250.0f; // distancia de vision del player.


    // configuraciones para la grilla.
    global.spaceGrid2D = 30; 
    global.numLinesGrid2D = 20;

    global.keySectionCanvas = KEY_F1;
    global.keySectionMap = KEY_F2;

    return global;
}

const int GetScreenWidthGlobal(const Global *const global)
{
    return global->screenWidth;
}

const int GetFPSGlobal(const Global *const global)
{
    return global->fps;
}

const int GetScreenHeightGlobal(const Global *const global)
{
    return global->screenHeight;
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
