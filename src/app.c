#include "../headers/app.h"
#include "../headers/global.h"
#include <stdlib.h>

Global global;
Boundary **globalWalls;
Camera2D camera;

//******************************************************************
//******************FIRMAS DE FUNCIOANES STATIC*********************
//******************************************************************
static void __KeyEventsApp(App *const app);
static void __UpdateApp(App *const app);
static void __DrawApp(const App *const app);
static void __DrawCanvasApp(const App *const app);
static void __DrawMapApp(const App *const app);
static void __DrawObjectsApp(const App *const app);
static void __UpdateCanvasApp(App *const app);
static void __UpdateMapApp(App *const app);
static void __InitCameraApp(const App *const app);
//******************************************************************
//*********************IMPLEMENTACION DE FUNCIONES******************
//******************************************************************
App NewApp()
{
    global = NewGlobal();
    App app = {0};

    app.backgroundCanvas = (Color) {61.0f, 61.0f, 61.0f, 255.0f};
    app.backgroundMap = BLACK;
    
    __InitCameraApp(&app);

    app.scene = NewScene();
    globalWalls = &app.scene.walls;
    
    app.canvas = NewCanvas();
    app.map = NewMap();

    // Inicializacion de la ventana.   
    InitWindow(
        GetScreenWidthGlobal(&global), // Ancho de la ventana.
        GetScreenHeightGlobal(&global), // Alto de la ventana.
        GetTitleGlobal(&global) // Titulo de la ventana.
    );

    // HideCursor();
    SetMousePosition(GetScreenWidthGlobal(&global)/2, GetScreenHeightGlobal(&global)/2);
    SetExitKey(KEY_F8);
    SetTargetFPS(GetFPSGlobal(&global));

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
    static bool flag = false;

    if (IsKeyPressed(global.keySectionCanvas) && GetCurrentSectionGlobal(&global) != CANVAS)
    {
        if (flag == false)
            HideFOVPlayer(&app->scene.player);
        else
            ShowFOVPlayer(&app->scene.player);

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

        SetSectionGlobal(&global, MAP);
    }
}

static void __UpdateApp(App *const app)
{
    __KeyEventsApp(app);
    UpdateScene(&app->scene); // la escene se actualiza siempre.

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
    
    if (global.section == CANVAS)
    {
        BeginMode2D(camera);
            __DrawObjectsApp(app);
        EndMode2D();
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
}

static void __InitCameraApp(const App *const app)
{
    camera.target = (Vector2) {
        app->scene.player.position.x + 20,
        app->scene.player.position.y + 20
    };

    camera.offset = (Vector2) {
        global.screenWidth / 2,
        global.screenHeight / 2
    };

    camera.zoom = 1.0f;
    camera.rotation = 0.0f;
}