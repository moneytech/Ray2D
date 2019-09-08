#include "../headers/player.h"
#include "../headers/helper.h"
#include <stdlib.h>

extern const int MAX_WALLS;
const int MAX_RAYS = 360; // angulo de vision del observador.

Player NewPlayer(const Vector2 position)
{
    Player particle = {0};
    particle.position = position;

    particle.rays = (Ray2D*) malloc(sizeof(Ray2D) * MAX_RAYS);
    for (int angle=0; angle < MAX_RAYS; angle++)
        particle.rays[angle] = NewAngleRay2D(position, angle);

    return particle;
}

void UpdatePlayer(Player *const player, const Vector2 position)
{
    // Detectar colision con pared.
    player->position = position; // Mueve la particula segun el mouse.
    
    for (int i=0; i < MAX_RAYS; i++)
        UpdateRay2D(&player->rays[i], position);
}

void DrawPlayer(const Player *const player, const Boundary *const walls)
{
    float max = 1000000000.f;
    Vector2 pto = {0};
    bool flag = false;

    for (int i=0; i < MAX_RAYS; i++)
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

        if (flag)
            DrawLineRay2D(&player->rays[i], pto);
    }

}

void FreePlayer(Player *const player)
{
    if (player->rays != NULL)
    {
        free(player->rays);
        player->rays = NULL;
    }
}