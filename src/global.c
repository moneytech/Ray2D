#include "../headers/global.h"

Global NewGlobal()
{
    Global global = {0};
    
    // configuraciones para la ventana.
    global.section = CANVAS; // inicializa en la seccion canvas.
    global.screenWidth = 810; // ancho de la ventana.
    global.screenHeight = 600; // altura de la ventana.
    global.title = "Overflow::Engine"; // titulo de la app.
    global.fps = 60;
    // configuraciones para el player.
    global.velocityPlayer = 2.09; // velocidad de desplazamiento del player.
    
    // configuraciones para la grilla.
    global.spaceGrid2D = 30; 
    global.numLinesGrid2D = 30;

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