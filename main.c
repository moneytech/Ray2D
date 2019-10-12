#include "raylib.h"
#include "headers/app.h"
#include "headers/ocamera.h"

OCamera *ocamera;

int main(void)
{
    // Crea una instancia de app, recibe el ancho, alto y
    // el titulo de la ventana.
    App app = NewApp();
    // globalWalls = &app.scene.walls;
    ocamera = &app.ocamera;

    // ciclo que actualiza  dibuja los
    // elementos.
    RunApp(&app);
    // libera los recursos que han sido
    // reservados.
    FreeApp(&app);

    return 0;
}

// int main(void) 
// {
//     InitWindow(640, 480, "fonts");

//     Font font = LoadFont("data/fonts/04B_03__.ttf");

//     SetTargetFPS(30);
//     while (!WindowShouldClose())
//     {
//         BeginDrawing();
//         ClearBackground(BLACK);
        
//         DrawTextEx(
//             font,
//             "hello",
//             (Vector2) {100, 100},
//             24,
//             1,
//             RAYWHITE
//         );

//         EndDrawing();
//     }
//     UnloadFont(font);
//     CloseWindow();
    


//     return 0;
// }