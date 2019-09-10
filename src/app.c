#include "../headers/app.h"
#include "../headers/global.h"
#include <stdlib.h>

Global global;
Camera2D camera;

//******************************************************************
//******************FIRMAS DE FUNCIOANES STATIC*********************
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
    // rgb(30, 39, 46)
    // app.backgroundCanvas = (Color) {45.0f, 52.0f, 54.0f, 255.0f};
    app.backgroundCanvas = (Color) {30.0f, 39.0f, 46.0f, 255.0f};
    app.backgroundMap = BLACK;
    
    camera.target = (Vector2) {
        app.scene.player.position.x + 20,
        app.scene.player.position.y + 20
    };

    camera.offset = (Vector2) {
        global.screenWidth / 2,
        global.screenHeight / 2
    };

    camera.zoom = 1.0f;
    camera.rotation = 0.0f;

    app.scene = NewScene();
    app.canvas = NewCanvas();
    app.map = NewMap();

    // Inicializacion de la ventana.   
    InitWindow(
        GetScreenWidthGlobal(&global), // Ancho de la ventana.
        GetScreenHeightGlobal(&global), // Alto de la ventana.
        GetTitleGlobal(&global) // Titulo de la ventana.
    );

    HideCursor();
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
    if (IsKeyPressed(KEY_TAB))
        global.section = (global.section == CANVAS) ? (MAP) : (CANVAS);
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

    BeginMode2D(camera);
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
    EndMode2D();

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

static void __UpdateCanvasApp(App *const app)
{
    UpdateCanvas(&(app->canvas));
}

static void __UpdateMapApp(App *const app)
{
    UpdateMap(&app->map);
}