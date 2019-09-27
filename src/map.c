#include "../headers/map.h"
#include "../headers/global.h"
#include <stdio.h>
#include <math.h>

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
    DrawRectangle(0, global.screenHeight/2, global.screenWidth, global.screenHeight/2, global.color0);
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
    float distance = 0;

    for (int i=0; i < GetNumRayPlayer(&scene->player); i++)
    {
        value = GetSlicesPlayerScene(scene)[i];
        distance = value;
        if (distance > 255)
            value = 255.0f;

        value = abs(value-255);

        float h = abs(distance - GetScreenHeightGlobal(&global));

        DrawRectangle(
            (i * sliceWidth),
            GetScreenHeightGlobal(&global) - h,
            sliceWidth,
            h - (GetScreenHeightGlobal(&global) - h),
            (Color) {value, value, value, 255.0f}
        );
    }
}