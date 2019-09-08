#if !defined(MAP_H)
#define MAP_H

#include "raylib.h"
#include "scene.h"

typedef struct Map
{
    Color color;
    
}Map;

Map NewMap();

void UpdateMap(Map *const map);

void DrawMap(const Map *const map, const Scene *const scene);

void FreeMap(Map *const map);

#endif //MAP_H