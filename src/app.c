#include "../headers/app.h"
#include "../headers/global.h"
#include <stdlib.h>
#include <stdio.h>

Global global;
Boundary **globalWalls;

//******************************************************************
//******************FIRMAS DE FUNCIOANES STATIC*********************
//******************************************************************
static void __KeyEventsApp(App *const app);
static void __UpdateApp(App *const app);
static void __DrawApp(App *const app);
static void __DrawCanvasApp(const App *const app);
static void __DrawMapApp(const App *const app);
static void __DrawObjectsApp(const App *const app);
static void __UpdateCanvasApp(App *const app);
static void __UpdateMapApp(App *const app);
static void __InitConfigWindowApp(const App *const app);
static void __ResizeWindowApp(App *const app);
//******************************************************************
//*********************IMPLEMENTACION DE FUNCIONES******************
//******************************************************************
App NewApp()
{
    global = NewGlobal();
    App app = {0};

    // app.backgroundCanvas = (Color) {61.0f, 61.0f, 61.0f, 255.0f};
    app.backgroundCanvas = BLACK;
    app.backgroundMap = BLACK;
    app.scene = NewScene();
    // se inicializa antes que el scene
    // y depues del canvas.
    globalWalls = &app.scene.walls; 
    app.canvas = NewCanvas();
    app.map = NewMap();
    app.menu = NewMenu();
    app.icon = LoadImage("data/ico.png");

    __InitConfigWindowApp(&app);
    
    app.ocamera = NewOCamera();

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
    FreeMenu(&app->menu);
    FreeScene(&app->scene);
    FreeMap(&app->map);
    FreeCanvas(&app->canvas);
    UnloadImage(app->icon);
    CloseWindow();
}

//******************************************************************
//****************IMAPLEMENTACION FUNCIOANES STATIC*****************
//******************************************************************
static void __KeyEventsApp(App *const app)
{
    static bool flag = false;

    if (IsKeyPressed(global.keySectionCanvas) && GetCurrentSectionGlobal(&global) != CANVAS)
    {
        if (flag == false)
            HideFOVPlayer(&app->scene.player);
        else
            ShowFOVPlayer(&app->scene.player);

        ShowCursor();
        SetSectionGlobal(&global, CANVAS);
    }
    else if (IsKeyPressed(global.keySectionMap) && GetCurrentSectionGlobal(&global) != MAP)
    {
        if (!IsShowFOVPlayer(&app->scene.player))
        {
            flag = false;
            ShowFOVPlayer(&app->scene.player);
        }
        else
            flag = true;

        HideCursor();
        SetSectionGlobal(&global, MAP);
    }
    else if (IsKeyPressed(KEY_F11))
    {
        printf("full\n");
        SetConfigFlags(FLAG_FULLSCREEN_MODE);
    }
}

static void __UpdateApp(App *const app)
{
    __ResizeWindowApp(app);
    
    __KeyEventsApp(app);
    UpdateScene(&app->scene); // la escene se actualiza siempre.

    switch (global.section)
    {
        case CANVAS:
            __UpdateCanvasApp(app);
            UpdateMenu(&app->menu);
            break;
        
        default:
            __UpdateMapApp(app);
    }
}

static void __DrawApp(App *const app)
{
    BeginDrawing();
    
    if (GetCurrentSectionGlobal(&global) == CANVAS)
    {
        BeginMode2D(*GetCameraOCamera(&app->ocamera));
            __DrawObjectsApp(app);
        EndMode2D();
        DrawMenu(&app->menu);
    }
    else
        __DrawObjectsApp(app);

    EndDrawing();
}

static void __DrawCanvasApp(const App *const app)
{
    DrawCanvas(&app->canvas, &app->scene);
}

static void __DrawMapApp(const App *const app)
{
    DrawMap(&app->map, &app->scene);
}

static void __DrawObjectsApp(const App *const app)
{
    switch (global.section)
    {
        case CANVAS:
            ClearBackground(app->backgroundCanvas); // limpia la pantalla.
            __DrawCanvasApp(app);
            break;
        
        default:
            ClearBackground(app->backgroundMap); // limpia la pantalla.
            __DrawMapApp(app);
    }
}

static void __UpdateCanvasApp(App *const app)
{
    UpdateCanvas(&(app->canvas));
}

static void __UpdateMapApp(App *const app)
{
    UpdateMap(&app->map);
    ResizeOCamera(&app->ocamera);
}

static void __InitConfigWindowApp(const App *const app)
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    // Inicializacion de la ventana.   
    InitWindow(
        GetScreenWidthGlobal(&global), // Ancho de la ventana.
        GetScreenHeightGlobal(&global), // Alto de la ventana.
        GetTitleGlobal(&global) // Titulo de la ventana.
    );

    SetMousePosition(
        GetScreenWidthGlobal(&global)/2, 
        GetScreenHeightGlobal(&global)/2
    );

    SetWindowIcon(app->icon);
    SetExitKey(KEY_F8);
    SetTargetFPS(GetFPSGlobal(&global));
}

static void __ResizeWindowApp(App *const app)
{
    if (global.screenWidth != GetScreenWidth() || global.screenHeight != GetScreenHeight())
    {
        global.screenWidth = GetScreenWidth();
        global.screenHeight = GetScreenHeight();
        ResizeOCamera(&app->ocamera);
    }
}