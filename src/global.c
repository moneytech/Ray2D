#include "../headers/global.h"

Global NewGlobal()
{
    Global global = {0};
    
    global.section = CANVAS;
    global.screenWidth = 800;
    global.screenHeight = 600;
    global.title = "Overflow::Engine";

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