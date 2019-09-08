#include "../headers/map.h"
#include "../headers/global.h"
#include <stdio.h>

extern Global global;

static void __DrawRay(const Scene *const scene);

Map NewMap()
{
    Map map = {0};
    map.color = GRAY;

    return map;
}

void UpdateMap(Map *const map)
{
    // Falta implementar.
}

void DrawMap(const Map *const map, const Scene *const scene)
{
    DrawScene(scene); // Dibuja la escene en el canvas.
    __DrawRay(scene);    
}

void FreeMap(Map *const map)
{
    // Falta implementar.
}


static void __DrawRay(const Scene *const scene)
{
    int sliceWidth = GetScreenWidthGlobal(&global) / GetNumRayPlayer(&scene->player);
    float value = 0;

    for (int i=0; i < GetNumRayPlayer(&scene->player); i++)
    {
        value = GetSlicesPlayerScene(scene)[i];
        if (GetSlicesPlayer(&scene->player)[i] > 255)
            value = 255.0f;

        DrawRectangle(
            i*sliceWidth,
            0,
            sliceWidth,
            global.screenHeight,
            (Color) {value, value, value, 255.0f}
        );
    }
}