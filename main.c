#include <stdlib.h>
#include <stdio.h>
#include "raylib.h"
#include "headers/boundary.h"
#include "headers/result.h"
#include "headers/particle.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const char *TITLE = "Ray2D";

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
    DisableCursor();
    SetMousePosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    
    Boundary wall = NewBoundary((Vector2) {300.0f, 100.0f}, (Vector2) {500.0f, 400.0f});
    Particle particle = NewParticle((Vector2) {200.0f, 200.0f});

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        UpdateParticle(&particle, GetMousePosition());
        UpdateBoundary(&wall);
        BeginDrawing();
        ClearBackground(BLACK);
        DrawBoundary(&wall);
        DrawParticle(&particle, &wall);
        
        EndDrawing();
    }
    FreeParticle(&particle);
    FreeBoundary(&wall);
    CloseWindow();    

    return EXIT_SUCCESS;
}