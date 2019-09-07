#include "../headers/app.h"
#include <stdlib.h>

const int MAX_WALLS = 1;

//******************************************************************
//*********************FIRMA FUNCIOANES STATIC**********************
//******************************************************************
static void __KeyEventsApp(App *const app);
static void __UpdateApp(App *const app);
static void __DrawApp(const App *const app);

//******************************************************************
//*********************IMPLEMENTACION DE FUNCIONES******************
//******************************************************************
App NewApp(int screenWidth, int screenHeight, const char *title)
{
    App app = {0};
    app.screenWidth = screenWidth;
    app.screenHeight = screenHeight;
    app.title = title;
    app.fps = 60;
    app.background = BLUE;
    
    // Obervador. 
    app.ray2d = NewRay2D(
        (Vector2) {125.0f, 200.0f}, // posicion
        (Vector2) {0.0f, 0.0f} // direccion
    );

    // Reservo memoria para almacenar paredes.
    app.walls = (Boundary*) malloc(sizeof(Boundary) * MAX_WALLS);
    app.walls[0] = NewBoundary(
        (Vector2) {400.0f, 10.0f},
        (Vector2) {400.0f, 400.0f}
    );


    InitWindow(
        app.screenWidth,
        app.screenHeight,
        app.title
    );

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

void FreeApp(App *app)
{
    // Libero la memoria reservada para las
    // paredes.
    if (app->walls != NULL)
    {
        free(app->walls);
        app->walls = NULL;
    }

    CloseWindow();
}

//******************************************************************
//****************IMAPLEMENTACION FUNCIOANES STATIC*****************
//******************************************************************
static void __KeyEventsApp(App *const app)
{
}

static void __UpdateApp(App *const app)
{
    __KeyEventsApp(app);
    UpdateRay2D(&app->ray2d, GetMousePosition());
}

static void __DrawApp(const App *const app)
{
    BeginDrawing();
    ClearBackground(app->background);

    DrawRay2D(&app->ray2d);

    for (int i=0; i < MAX_WALLS; i++)
        DrawBoundary(&(app->walls[i]));

    EndDrawing();
}