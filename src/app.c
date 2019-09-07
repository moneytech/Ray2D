#include "../headers/app.h"

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
    app.close = false;
    app.ray2d = NewRay2D(
        (Vector2) {100.0f, 100.0f},
        (Vector2) {500.0f, 500.0f}
    );


    InitWindow(
        app.screenWidth,
        app.screenHeight,
        app.title
    );

    SetTargetFPS(app.fps);

    return app;
}

void RunApp(App *const app)
{
    while (!app->close)
    {
        __UpdateApp(app);
        __DrawApp(app);
    }
}

void FreeApp(App *app)
{
    CloseWindow();
}

//******************************************************************
//****************IMAPLEMENTACION FUNCIOANES STATIC*****************
//******************************************************************
static void __KeyEventsApp(App *const app)
{
    if (IsKeyPressed(KEY_F8))
        app->close = true;
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

    EndDrawing();
}