#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "raylib.h"
#include "headers/boundary.h"
#include "headers/result.h"
#include "headers/particle.h"
#include "dos.h"


const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const char *TITLE = "Ray2D";

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
    DisableCursor();
    SetMousePosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    
    Boundary *walls = (Boundary*) malloc(sizeof(Boundary) * 4); 
    for (int i=0; i < 4; i++)
    {
        srand(time(NULL));
        int x0 =  rand() % SCREEN_WIDTH;
        int y0 =  rand() % SCREEN_HEIGHT;
        
        int x1 =  (rand() % SCREEN_WIDTH) + 10;
        int y1 =  (rand() % SCREEN_HEIGHT) + 10;
        _sleep(1000);
        printf("(%d, %d), (%d, %d)\n", x0, y0, x1, y1);
        walls[i] = NewBoundary((Vector2) {x0, y0}, (Vector2) {x1, y1});
    }

    // Boundary wall = NewBoundary((Vector2) {300.0f, 100.0f}, (Vector2) {500.0f, 400.0f});
    Particle particle = NewParticle((Vector2) {200.0f, 200.0f});

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        UpdateParticle(&particle, GetMousePosition());
        BeginDrawing();
        ClearBackground(BLACK);
        
        for (int i=0; i < 4; i++)
            DrawBoundary(&walls[i]);

        DrawParticle(&particle, walls);
        
        EndDrawing();
    }
    FreeParticle(&particle);
    for (int i=0; i < 4; i++)
        FreeBoundary(&walls[i]);
    
    free(walls);
    walls = NULL;

    CloseWindow();    

    return EXIT_SUCCESS;
}