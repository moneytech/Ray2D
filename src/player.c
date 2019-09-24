#include "../headers/player.h"
#include "../headers/helper.h"
#include "../headers/global.h"
#include "../headers/ocamera.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

extern const int MAX_WALLS; // Numero de paredes a colisionar (MODIFICAR). 
extern Global global;
extern OCamera *ocamera; //Puntero a la camera de la estructura OCamera (Corregir).

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
    player.color = OVE_RED;
    player.numRays = global.visionAngle; // angulo de vision del observador.
    player.slices = (float*) calloc(player.numRays, sizeof(float));
    player.angle = 0;
    player.showFOV = false;

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
    if (walls != NULL && player->showFOV)
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

bool ShowFOVPlayer(Player *const player)
{
    player->showFOV = true;
    return player->showFOV;
}

bool HideFOVPlayer(Player *const player)
{
    player->showFOV = false;
    return player->showFOV;
}

bool IsHideFOVPlayer(const Player *const player)
{
    return !player->showFOV;
}

bool IsShowFOVPlayer(const Player *const player)
{
    return player->showFOV;
}

Vector2 GetPositionPlayer(const Player *const player)
{
    return player->position;
}

void SetPositionXPlayer(Player *const player, float x)
{
    player->position.x = x;
}

void SetPositionYPlayer(Player *const player, float y)
{
    player->position.y = y;
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
        max = 0xF00000;
        flag = false;

        for (int iWall=0; iWall < MAX_WALLS; iWall++)
        {
            Vector2 auxPoint = GetIntersectionRay2D(&(player->rays[i]), &walls[iWall]);
            if (auxPoint.x > -100000.0f)
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

        player->slices[i] = (max < global.visionDistance) ? max : 0xF00000; // almaceno las trazas para su renderizado en 'Map'.

        if (flag && global.section == CANVAS && max < global.visionDistance)
            DrawLineRay2D(&player->rays[i], pto);
        
        else if (global.section == CANVAS)
            DrawLine(
                player->position.x,
                player->position.y,
                player->rays[i].position.x + player->rays[i].direction.x * (-global.visionDistance),
                player->rays[i].position.y + player->rays[i].direction.y * (-global.visionDistance),
                OVE_DARKGRAY
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
            player->position.x + cos(player->angle * DEG2RAD + global.diffAngle) * 20,
            player->position.y + sin(player->angle * DEG2RAD + global.diffAngle) * 20,
            player->color
        );

        DrawLine(
            player->position.x,
            player->position.y,
            player->position.x + cos((player->angle - 45)  * DEG2RAD + global.diffAngle) * 10,
            player->position.y + sin((player->angle - 45) * DEG2RAD + global.diffAngle) * 10,
            player->color
        );
        
        DrawLine(
            player->position.x,
            player->position.y,
            player->position.x + cos((player->angle + 45)  * DEG2RAD + global.diffAngle) * 10,
            player->position.y + sin((player->angle + 45) * DEG2RAD + global.diffAngle) * 10,
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
        ocamera->camera.offset.y += global.velocityPlayer * sin(player->angle * DEG2RAD + global.diffAngle);
        ocamera->camera.offset.x += global.velocityPlayer * cos(player->angle * DEG2RAD + global.diffAngle);
    }

    else if (IsKeyDown(KEY_DOWN))
    {
        __MovePlayer(player, global.velocityPlayer);
        ocamera->camera.offset.y -= global.velocityPlayer * sin(player->angle * DEG2RAD + global.diffAngle);
        ocamera->camera.offset.x -= global.velocityPlayer * cos(player->angle * DEG2RAD + global.diffAngle);
    }
    
    if (IsKeyPressed(KEY_F3) && global.section == CANVAS)
        player->showFOV = !player->showFOV;
    
    ocamera->camera.target.x = player->position.x + 20;
    ocamera->camera.target.y = player->position.y + 20;

    global.posPlayer = &player->position;  
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
    player->position.x += cos(player->angle * DEG2RAD + global.diffAngle) * velocity;
    player->position.y += sin(player->angle * DEG2RAD + global.diffAngle) * velocity;
}