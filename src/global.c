#include "../headers/global.h"
#include "../headers/ocamera.h"
#include <stdlib.h>
#include <stdio.h>

extern OCamera *ocamera;

//******************************************************************
//******************FIRMAS DE FUNCIOANES STATIC*********************
//******************************************************************
static void __KeyEventGlobal(Global *const global);
static void __UpdateThemeGlobal(Global *const global);

//******************************************************************
//*********************IMPLEMENTACION DE FUNCIONES******************
//******************************************************************
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

    global.indexTheme = 0;
    __UpdateThemeGlobal(&global);

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

void UpdateGlobal(Global *const global)
{
    __KeyEventGlobal(global);
}

//******************************************************************
//****************IMAPLEMENTACION FUNCIOANES STATIC*****************
//******************************************************************
static void __KeyEventGlobal(Global *const global)
{
    if(IsKeyPressed(KEY_F10))
    {
        global->indexTheme = (global->indexTheme >= 7) ? 0 : global->indexTheme + 1;
        printf("indexTheme: %d\n", global->indexTheme);
        __UpdateThemeGlobal(global);
    }
}

static void __UpdateThemeGlobal(Global *const global)
{
    switch(global->indexTheme)
    {
        case 0:
            global->color0 = OVE_MIST_COLOR0;
            global->color1 = OVE_MIST_COLOR1;
            global->color2 = OVE_MIST_COLOR2;
            global->color3 = OVE_MIST_COLOR3;
            break;
        
        case 1:
            global->color0 = OVE_CRIMSON_COLOR0;
            global->color1 = OVE_CRIMSON_COLOR1;
            global->color2 = OVE_CRIMSON_COLOR2;
            global->color3 = OVE_CRIMSON_COLOR3;
            break;
        
        case 2:
            global->color0 = OVE_DIRTYBOY_COLOR0;
            global->color1 = OVE_DIRTYBOY_COLOR1;
            global->color2 = OVE_DIRTYBOY_COLOR2;
            global->color3 = OVE_DIRTYBOY_COLOR3;
            break;
        
        case 3:
            global->color0 = OVE_AYY4_COLOR0;
            global->color1 = OVE_AYY4_COLOR1;
            global->color2 = OVE_AYY4_COLOR2;
            global->color3 = OVE_AYY4_COLOR3;
            break;
        
        case 4:
            global->color0 = OVE_RUSTIC_COLOR0;
            global->color1 = OVE_RUSTIC_COLOR1;
            global->color2 = OVE_RUSTIC_COLOR2;
            global->color3 = OVE_RUSTIC_COLOR3;
            break;
        
        case 5:
            global->color0 = OVE_KIROKAZE_COLOR0;
            global->color1 = OVE_KIROKAZE_COLOR1;
            global->color2 = OVE_KIROKAZE_COLOR2;
            global->color3 = OVE_KIROKAZE_COLOR3;
            break;
        
        case 6:
            global->color0 = OVE_LINKS_COLOR0;
            global->color1 = OVE_LINKS_COLOR1;
            global->color2 = OVE_LINKS_COLOR2;
            global->color3 = OVE_LINKS_COLOR3;
            break;
        
        default:
            global->color0 = OVE_MUDDYSAND_COLOR0;
            global->color1 = OVE_MUDDYSAND_COLOR1;
            global->color2 = OVE_MUDDYSAND_COLOR2;
            global->color3 = OVE_MUDDYSAND_COLOR3;
    }
}
