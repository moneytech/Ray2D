#include "../headers/scene.h"
#include <stdlib.h>

const int MAX_WALLS = 4;

//******************************************************************
//*********************IMPLEMENTACION DE FUNCIONES******************
//******************************************************************
Scene NewScene()
{
    Scene scene = {0};

    // Obervador. 
    scene.player = NewPlayer((Vector2) {200.0f, 300.0f});

    // Reservo memoria para almacenar paredes.
    scene.walls = (Boundary*) malloc(sizeof(Boundary) * MAX_WALLS);
    scene.walls[0] = NewBoundary(
        (Vector2) {490.0f, 463.0f},
        (Vector2) {480.0f, 151.0f}
    );

    scene.walls[1] = NewBoundary(
        (Vector2) {493.0f, 43.0f},
        (Vector2) {425.0f, 86.0f}
    );

    scene.walls[2] = NewBoundary(
        (Vector2) {496.0f, 231.0f},
        (Vector2) {241.0f, 21.0f}
    );

    scene.walls[3] = NewBoundary(
        (Vector2) {500.0f, 420.0f},
        (Vector2) {185.0f, 437.0f}
    );

    return scene;
}

void UpdateScene(Scene *const scene)
{
    // actualiza la posicion de la particula
    // segun el movimiento del mouse.
    UpdatePlayer(&scene->player, GetMousePosition());
}

void DrawScene(const Scene *const scene)
{
    // Dibuja las paredes.
    for (int i=0; i < MAX_WALLS; i++)
        DrawBoundary(&(scene->walls[i]));
    
    // Dibuja la particula.
    DrawPlayer(&scene->player, scene->walls);
}

void FreeScene(Scene *const scene)
{
    // Libero la memoria reservada para las
    // paredes.
    if (scene->walls != NULL)
    {
        free(scene->walls);
        scene->walls = NULL;
    }
    
    FreePlayer(&scene->player);
}