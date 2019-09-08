#include "../headers/canvas.h"
#include <stdlib.h>


Canvas NewCanvas()
{
    Canvas canvas = {0};
    canvas.color = GRAY;

    return canvas;
}

void UpdateCanvas(Canvas *const canvas)
{
    // Falta imaplementacion 
}

void DrawCanvas(const Canvas *const canvas, const Scene *const scene)
{
    DrawScene(scene); // Dibuja la escene en el canvas.
}

void FreeCanvas(Canvas *const canvas)
{
    // Falta imaplementacion 
}