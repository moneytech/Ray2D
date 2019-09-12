#include "../headers/canvas.h"
#include <stdlib.h>


Canvas NewCanvas()
{
    Canvas canvas = {0};
    canvas.grid2d = NewGrid2D(20, (Color) {75.0f, 75.0f, 75.0f, 255.0f});
    canvas.color = GRAY;

    return canvas;
}

void UpdateCanvas(Canvas *const canvas)
{
    // Falta imaplementacion 
    UpdateGrid2D(&canvas->grid2d);
}

void DrawCanvas(const Canvas *const canvas, const Scene *const scene)
{
    DrawGrid2D(&canvas->grid2d);
    DrawScene(scene); // Dibuja la escene en el canvas.
}

void FreeCanvas(Canvas *const canvas)
{
    // Falta imaplementacion 
    FreeGrid2D(&canvas->grid2d);
}