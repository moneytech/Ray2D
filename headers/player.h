#if !defined(PLAYER_H)
#define PLAYER_H

#include "raylib.h"
#include "ray2d.h"

typedef struct Player
{
    Vector2 position;
    Ray2D *rays;
    Color color;

    int numRays;
    int *slices;

}Player;

Player NewPlayer(const Vector2 position);

void UpdatePlayer(Player *const player, const Vector2 position);

void DrawPlayer(const Player *const player, const Boundary *const walls);

void FreePlayer(Player *const player);

const int *GetSlicesPlayer(const Player *const player);

#endif //PLAYER_H