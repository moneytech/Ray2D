#include "../headers/canvas.h"
#include <stdlib.h>

const int MAX_WALLS = 4;

Canvas NewCanvas()
{
    Canvas canvas = {0};
    canvas.slices = 100;
    canvas.spacing = 1.0f;
    canvas.color = GRAY;

    // Obervador. 
    canvas.player = NewPlayer((Vector2) {200.0f, 300.0f});

    // Reservo memoria para almacenar paredes.
    canvas.walls = (Boundary*) malloc(sizeof(Boundary) * MAX_WALLS);
    canvas.walls[0] = NewBoundary(
        (Vector2) {490.0f, 463.0f},
        (Vector2) {480.0f, 151.0f}
    );

    canvas.walls[1] = NewBoundary(
        (Vector2) {493.0f, 43.0f},
        (Vector2) {425.0f, 86.0f}
    );

    canvas.walls[2] = NewBoundary(
        (Vector2) {496.0f, 231.0f},
        (Vector2) {241.0f, 21.0f}
    );

    canvas.walls[3] = NewBoundary(
        (Vector2) {500.0f, 420.0f},
        (Vector2) {185.0f, 437.0f}
    );


    return canvas;
}

void UpdateCanvas(Canvas *const canvas)
{
    // actualiza la posicion de la particula
    // segun el movimiento del mouse.
    UpdatePlayer(&canvas->player, GetMousePosition());
}

void DrawCanvas(const Canvas *const canvas)
{
    DrawGrid(canvas->slices, canvas->spacing);

    // Dibuja las paredes.
    for (int i=0; i < MAX_WALLS; i++)
        DrawBoundary(&(canvas->walls[i]));
    
    // Dibuja la particula.
    DrawPlayer(&canvas->player, canvas->walls);
}

void FreeCanvas(Canvas *const canvas)
{
    // Libero la memoria reservada para las
    // paredes.
    if (canvas->walls != NULL)
    {
        free(canvas->walls);
        canvas->walls = NULL;
    }
    FreePlayer(&canvas->player);
    
}