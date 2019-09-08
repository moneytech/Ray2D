#include "../headers/app.h"
#include "../headers/global.h"
#include <stdlib.h>

Global global;

//******************************************************************
//*********************FIRMA FUNCIOANES STATIC**********************
//******************************************************************
static void __KeyEventsApp(App *const app);
static void __UpdateApp(App *const app);
static void __DrawApp(const App *const app);
static void __DrawCanvasApp(const App *const app);
static void __DrawMapApp(const App *const app);
static void __UpdateCanvasApp(App *const app);
static void __UpdateMapApp(App *const app);
//******************************************************************
//*********************IMPLEMENTACION DE FUNCIONES******************
//******************************************************************
App NewApp(const int screenWidth, const int screenHeight, const char *title)
{
    global = NewGlobal();

    App app = {0};
    app.screenWidth = screenWidth;
    app.screenHeight = screenHeight;
    app.title = title;
    app.fps = 60;
    app.background = BLACK;
    app.canvas = NewCanvas();
    
    // Inicializacion de la ventana.   
    InitWindow(
        app.screenWidth, // Ancho de la ventana.
        app.screenHeight, // Alto de la ventana.
        app.title // Titulo de la ventana.
    );

    HideCursor();
    SetMousePosition(screenWidth/2, screenHeight/2);
    SetExitKey(KEY_F8);
    SetTargetFPS(app.fps);

    return app;
}

void RunApp(App *const app)
{
    while (!WindowShouldClose())
    {
        __UpdateApp(app);
        __DrawApp(app);
    }
}

void FreeApp(App *const app)
{
    FreeCanvas(&app->canvas);
    CloseWindow();
}

//******************************************************************
//****************IMAPLEMENTACION FUNCIOANES STATIC*****************
//******************************************************************
static void __KeyEventsApp(App *const app)
{
    if (IsKeyPressed(KEY_TAB))
        global.section = (global.section == CANVAS) ? (MAP) : (CANVAS);
}

static void __UpdateApp(App *const app)
{
    __KeyEventsApp(app);

    switch (global.section)
    {
        case CANVAS:
            __UpdateCanvasApp(app);
            break;
        
        default:
            __UpdateMapApp(app);
    }
}

static void __DrawApp(const App *const app)
{
    BeginDrawing();
    ClearBackground(app->background); // limpia la pantalla.

    switch (global.section)
    {
        case CANVAS:
            __DrawCanvasApp(app);
            break;
        
        default:
            __DrawMapApp(app);
    }

    EndDrawing();
}

static void __DrawCanvasApp(const App *const app)
{
    DrawCanvas(&app->canvas);
}

static void __DrawMapApp(const App *const app)
{
    // falta implementar
}

static void __UpdateCanvasApp(App *const app)
{
    UpdateCanvas(&(app->canvas));
}

static void __UpdateMapApp(App *const app)
{
    // falta implementar
}