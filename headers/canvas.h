#if !defined(CANVAS_H)
#define CANVAS_H

#include "raylib.h"
#include "player.h"
#include "boundary.h"

typedef struct Canvas
{
    int slices;
    float spacing;
    Color color;

    Player player;
    Boundary *walls;
    

}Canvas;

Canvas NewCanvas();

void UpdateCanvas(Canvas *const canvas);

void DrawCanvas(const Canvas *const canvas);

void FreeCanvas(Canvas *const canvas);

#endif //CANVAS_H