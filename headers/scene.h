#if !defined(SCENE_H)
#define SCENE_H

#include "player.h"
#include "boundary.h"

typedef struct Scene
{
    Boundary *walls;
    Player player;

} Scene;

Scene NewScene();

void UpdateScene(Scene *const scene);

void DrawScene(const Scene *const scene);

void FreeScene(Scene *const scene);

const float *GetSlicesPlayerScene(const Scene *const scene);

const Player *GetPlayerScene(const Scene *const scene);

const Boundary *GetWallsScene(const Scene *const scene);

#endif //SCENE_H