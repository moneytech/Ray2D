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
App NewApp(const int screenWidth, const int screenHeight, const char *title)
{
    App app = {0};
    app.screenWidth = screenWidth;
    app.screenHeight = screenHeight;
    app.title = title;
    app.fps = 60;
    app.background = BLUE;
    
    // Obervador. 
    app.player = NewParticle((Vector2) {200.0f, 300.0f});

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

    DisableCursor();
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
    // Libero la memoria reservada para las
    // paredes.
    if (app->walls != NULL)
    {
        free(app->walls);
        app->walls = NULL;
    }
    FreeParticle(&app->player);

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
    // actualiza la posicion de la particula
    // segun el movimiento del mouse.
    UpdateParticle(&app->player, GetMousePosition());
}

static void __DrawApp(const App *const app)
{
    BeginDrawing();
    // limpia la pantalla.
    ClearBackground(app->background);

    // Dibuja las paredes.
    for (int i=0; i < MAX_WALLS; i++)
        DrawBoundary(&(app->walls[i]));
    
    // Dibuja la particula.
    DrawParticle(&app->player);

    EndDrawing();
}