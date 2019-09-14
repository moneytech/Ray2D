#include "raylib.h"
#include "headers/app.h"


int main(void)
{
    // Crea una instancia de app, recibe el ancho, alto y
    // el titulo de la ventana.
    App app = NewApp();
    // ciclo que actualiza  dibuja los
    // elementos.
    RunApp(&app);
    // libera los recursos que han sido
    // reservados.
    FreeApp(&app);

    return 0;
}

// #include "raylib.h"
// #include <stdio.h>
// #include <stdlib.h>

// typedef struct Data
// {


// } Data;

// int main(void)
// {
//     InitWindow(640, 480, "test camera.");

//     Rectangle player = {0};
//     player.x = 0;
//     player.y = 0;
//     player.width = 50;
//     player.height = 50;

//     Camera2D camera = {0};
//     camera.zoom = 1.0f;
//     camera.rotation = 0.0f;
    
//     camera.target = (Vector2) {
//         player.x,
//         player.y
//     };
//     camera.offset = (Vector2) {
//         320 + player.x,
//         240 + player.y
//     };

//     SetTargetFPS(30);
//     while (!WindowShouldClose())
//     {
//         if (IsKeyDown(KEY_UP))
//         {
//             player.y -= 2.1;
//             camera.offset.y = 240 - player.y;
//         }
//         else if (IsKeyDown(KEY_DOWN))
//         {
//             player.y += 2.1;
//             camera.offset.y = 240 - player.y;
//         }
//         else if (IsKeyDown(KEY_LEFT))
//         {
//             player.x -= 2.1;
//             camera.offset.x = 320 - player.x;
//         }
//         else if (IsKeyDown(KEY_RIGHT))
//         {
//             player.x += 2.1;
//             camera.offset.x = 320 - player.x;
//         }

//         camera.target = (Vector2) {player.x, player.y};
      
//         BeginDrawing();
//         ClearBackground(BLACK);
//             BeginMode2D(camera);
//                 DrawRectangleRec(player, BLUE);
//                 DrawLine(-100, 0, 100, 0, RED);
//                 DrawLine(0, -100, 0, 100, GREEN);
//             EndMode2D();
//         EndDrawing();
//     }
//     CloseWindow();

//     return 0;
// }
