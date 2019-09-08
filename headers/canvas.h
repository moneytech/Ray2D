#if !defined(CANVAS_H)
#define CANVAS_H

#include "raylib.h"
#include "scene.h"

typedef struct Canvas
{
    Color color;

}Canvas;

Canvas NewCanvas();

void UpdateCanvas(Canvas *const canvas);

void DrawCanvas(const Canvas *const canvas, const Scene *const scene);

void FreeCanvas(Canvas *const canvas);

#endif //CANVAS_H