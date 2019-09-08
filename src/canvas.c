#include "../headers/canvas.h"

Canvas NewCanvas()
{
    Canvas canvas = {0};
    canvas.slices = 50;
    canvas.spacing = 1.0f;
    canvas.color = GRAY;

    return canvas;
}

void UpdateCanvas(Canvas *const canvas)
{

}

void DrawCanvas(const Canvas *const canvas)
{
    DrawGrid(canvas->slices, canvas->spacing);
}

void FreeCanvas(Canvas *const canvas)
{

}