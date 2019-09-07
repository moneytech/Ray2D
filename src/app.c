#include "../headers/app.h"

static void __UpdateApp(const App *const app);
static void __DrawApp(const App *const app);

App NewApp(int screenWidth, int screenHeight, const char *title)
{
    App app = {0};
    app.screenWidth = screenWidth;
    app.screenHeight = screenHeight;
    app.title = title;
    app.fps = 60;
    app.background = BLUE;

    InitWindow(
        app.screenWidth,
        app.screenHeight,
        app.title
    );

    SetTargetFPS(app.fps);


    return app;
}

void RunApp(const App *const app)
{
    while (!WindowShouldClose())
    {
        __UpdateApp(app);
        __DrawApp(app);
    }
}

void FreeApp(App *app)
{
    CloseWindow();
}

static void __UpdateApp(const App *const app)
{
    // eventos y actualizacion de datos.
}

static void __DrawApp(const App *const app)
{
    BeginDrawing();
    ClearBackground(app->background);

    EndDrawing();
}