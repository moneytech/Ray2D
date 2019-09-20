#include "../headers/scene.h"
#include "../headers/global.h"
#include <stdlib.h>

extern Global global;
const int MAX_WALLS = 100000 + 4;
int COUNT_WALLS = 0;

//******************************************************************
//*********************IMPLEMENTACION DE FUNCIONES******************
//******************************************************************
Scene NewScene()
{
    Scene scene = {0};

    // Obervador. 
    scene.player = NewPlayer((Vector2) {0, 0});

    // Reservo memoria para almacenar paredes.
    scene.walls = NULL;
    scene.walls = (Boundary *) malloc(sizeof(Boundary) * MAX_WALLS);
    // scene.walls[0] = NewBoundary(
    //     (Vector2) {-300.0f, -300.0f},
    //     (Vector2) {300.0f, -300.0f}
    // );
    
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
    if (scene->walls != NULL)
    {
        for (int i=0; i < MAX_WALLS; i++)
            DrawBoundary(&(scene->walls[i]));
    }

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

const float *GetSlicesPlayerScene(const Scene *const scene)
{
    return GetSlicesPlayer(&scene->player);
}

const Player *GetPlayerScene(const Scene *const scene)
{
    return &scene->player;
}

const Boundary *GetWallsScene(const Scene *const scene)
{
    return scene->walls;
}