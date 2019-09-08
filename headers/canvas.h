#if !defined(CANVAS_H)
#define CANVAS_H

#include "raylib.h"

typedef struct Canvas
{
    int slices;
    float spacing;
    Color color;

}Canvas;

Canvas NewCanvas();

void UpdateCanvas(Canvas *const canvas);

void DrawCanvas(const Canvas *const canvas);

void FreeCanvas(Canvas *const canvas);

#endif //CANVAS_H