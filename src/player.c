#include "../headers/player.h"
#include "../headers/helper.h"
#include "../headers/global.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

extern const int MAX_WALLS; // Numero de paredes a colisionar (MODIFICAR). 
extern Global global;
extern Camera2D camera;

//******************************************************************
//******************FIRMAS DE FUNCIOANES STATIC*********************
//******************************************************************
static void __DrawRayPlayer(const Player *const player, const Boundary *const walls);
static void __DrawPlayer(const Player *const player);
static void __KeyEventPlayer(Player *const player);
static void __RotatePlayer(Player *const player, float angle);
static void __MovePlayer(Player *const player, float velocity);

//******************************************************************
//*********************IMPLEMENTACION DE FUNCIONES******************
//******************************************************************
Player NewPlayer(const Vector2 position)
{
    Player player = {0};
    player.position = position;
    player.color = (Color) {231.0f, 76.0f, 60.0f, 255.0f};
    player.numRays = 60; // angulo de vision del observador.
    player.slices = (float*) calloc(player.numRays, sizeof(float));
    player.angle = 0;

    player.rays = (Ray2D*) malloc(sizeof(Ray2D) * player.numRays);
    for (int angle=0; angle < player.numRays; angle++)
        player.rays[angle] = NewAngleRay2D(position, angle);

    return player;
}

void UpdatePlayer(Player *const player, const Vector2 position)
{   
    __KeyEventPlayer(player);
    
    for (int i=0; i < player->numRays; i++)
        UpdateRay2D(&player->rays[i], player->position);
}

void DrawPlayer(const Player *const player, const Boundary *const walls)
{
    if (walls != NULL)
        __DrawRayPlayer(player, walls); // Dibuja la vision del player.
    
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

static void __DrawRayPlayer(const Player *const player, const Boundary *const walls)
{
    float max = 0xF00000; //15728640
    Vector2 pto = {0};
    bool flag = false;

    for (int i=0; i < player->numRays; i++)
    {
        max = 1000000000.f;
        flag = false;

        for (int iWall=0; iWall < MAX_WALLS; iWall++)
        {
            Vector2 auxPoint = GetIntersectionRay2D(&(player->rays[i]), &walls[iWall]);
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
        
        else if (global.section == CANVAS)
            DrawLine(
                player->position.x,
                player->position.y,
                player->rays[i].position.x + player->rays[i].direction.x * (-1000),
                player->rays[i].position.y + player->rays[i].direction.y * (-1000),
                GRAY
            );
    }
}

static void __DrawPlayer(const Player *const player)
{
    if (global.section == CANVAS)
    {
        DrawLine(
            player->position.x,
            player->position.y,
            player->position.x + cos(player->angle * DEG2RAD + PI/6) * 20,
            player->position.y + sin(player->angle * DEG2RAD + PI/6) * 20,
            player->color
        );

        DrawLine(
            player->position.x,
            player->position.y,
            player->position.x + cos((player->angle - 45)  * DEG2RAD + PI/6) * 10,
            player->position.y + sin((player->angle - 45) * DEG2RAD + PI/6) * 10,
            player->color
        );
        
        DrawLine(
            player->position.x,
            player->position.y,
            player->position.x + cos((player->angle + 45)  * DEG2RAD + PI/6) * 10,
            player->position.y + sin((player->angle + 45) * DEG2RAD + PI/6) * 10,
            player->color
        );
    }
}

static void __KeyEventPlayer(Player *const player)
{
    if (IsKeyDown(KEY_LEFT))
        __RotatePlayer(player, -global.velocityPlayer);
    
    else if (IsKeyDown(KEY_RIGHT))
        __RotatePlayer(player, global.velocityPlayer);
    
    else if (IsKeyDown(KEY_UP))
    {
        __MovePlayer(player, -global.velocityPlayer);
        camera.offset.y += global.velocityPlayer * sin(player->angle * DEG2RAD + PI/6);
        camera.offset.x += global.velocityPlayer * cos(player->angle * DEG2RAD + PI/6);
    }
    
    camera.target.x = player->position.x + 20;
    camera.target.y = player->position.y + 20;
}

static void __RotatePlayer(Player *const player, float angle)
{
    player->angle += angle;
    if (player->angle > 360 || player->angle < -360)
        player->angle = 0;

    for (int i=0; i < GetNumRayPlayer(player); i++)
        SetAngleRay2D(&player->rays[i], i + player->angle);
}

static void __MovePlayer(Player *const player, float velocity)
{
    player->position.x += cos(player->angle * DEG2RAD + PI/6) * velocity;
    player->position.y += sin(player->angle * DEG2RAD + PI/6) * velocity;
}