#if !defined(SCENE_H)
#define SCENE_H

#include "player.h"
#include "boundary.h"

typedef struct Scene
{
    Boundary *walls;
    Player player;

}Scene;

Scene NewScene();

void UpdateScene(Scene *const scene);

void DrawScene(const Scene *const scene);

void FreeScene(Scene *const scene);

#endif //SCENE_H