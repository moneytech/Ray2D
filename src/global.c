#include "../headers/global.h"

Global NewGlobal()
{
    Global global = {0};
    
    global.section = CANVAS; // inicializa en la seccion canvas.
    global.screenWidth = 810; // ancho de la ventana.
    global.screenHeight = 600; // altura de la ventana.
    global.title = "Overflow::Engine"; // titulo de la app.

    global.velocityPlayer = 0.09; // velocidad de desplazamiento del player.

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