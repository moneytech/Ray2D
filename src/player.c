#include "../headers/player.h"
#include "../headers/helper.h"
#include "../headers/global.h"
#include <stdlib.h>

extern const int MAX_WALLS; // Numero de paredes a colisionar (MODIFICAR). 
extern Global global;

//******************************************************************
//******************FIRMAS DE FUNCIOANES STATIC*********************
//******************************************************************
static void __DrawRay(const Player *const player, const Boundary *const walls);
static void __DrawPlayer(const Player *const player);

//******************************************************************
//*********************IMPLEMENTACION DE FUNCIONES******************
//******************************************************************
Player NewPlayer(const Vector2 position)
{
    Player player = {0};
    player.position = position;
    player.color = RED;
    player.numRays = 90; // angulo de vision del observador.
    player.slices = (float*) calloc(player.numRays, sizeof(float));
    
    player.rays = (Ray2D*) malloc(sizeof(Ray2D) * player.numRays);
    for (int angle=0; angle < player.numRays; angle++)
        player.rays[angle] = NewAngleRay2D(position, angle);

    return player;
}

void UpdatePlayer(Player *const player, const Vector2 position)
{
    // Detectar colision con pared.
    player->position = position; // Mueve la particula segun el mouse.
    
    for (int i=0; i < player->numRays; i++)
        UpdateRay2D(&player->rays[i], position);
}

void DrawPlayer(const Player *const player, const Boundary *const walls)
{
    __DrawRay(player, walls); // Dibuja la vision del player.
    __DrawPlayer(player); // Dibuja la posicion del player.
}

void FreePlayer(Player *const player)
{
    if (player->rays != NULL)
    {
        free(player->rays);
        player->rays = NULL;
    }

    if (player->slices != NULL)
    {
        free(player->slices);
        player->slices = NULL;
    }
}

const float *GetSlicesPlayer(const Player *const player)
{
    return player->slices;
}

const int GetNumRayPlayer(const Player *const player)
{
    return player->numRays;
}


//******************************************************************
//****************IMAPLEMENTACION FUNCIOANES STATIC*****************
//******************************************************************

static void __DrawRay(const Player *const player, const Boundary *const walls)
{
    float max = 1000000000.0f;
    Vector2 pto = {0};
    bool flag = false;

    for (int i=0; i < player->numRays; i++)
    {
        max = 1000000000.f;
        flag = false;

        for (int iWall=0; iWall < MAX_WALLS; iWall++)
        {
            Vector2 auxPoint = GetIntersection(&(player->rays[i]), &walls[iWall]);
            if (auxPoint.x > 0)
           {
               float distance = Distance(player->rays[i].position, auxPoint);
                if (distance < max)
                {
                    max = distance;
                    pto = auxPoint;
                    flag = true;
                }
           }
        }
        player->slices[i] = max; // almaceno las trazas para su renderizado en 'Map'.

        if (flag && global.section == CANVAS)
            DrawLineRay2D(&player->rays[i], pto);
    }
}

static void __DrawPlayer(const Player *const player)
{
    if (global.section == CANVAS)
        DrawCircle(
            player->position.x,
            player->position.y,
            5.0f,
            player->color
        );
}