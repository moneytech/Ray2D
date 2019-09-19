#include "../headers/square.h"


Square NewSquare(float x, float y, float side, Color color)
{
    Square square = {0}; 

    square.center = (Vector2) {x, y};
    square.side = side;
    square.scale = 1.0f;
    square.color = color;

    square.position = (Vector2) 
    {
        x - (side/2),        
        y - (side/2)        
    };

    return square;
}

void UpdateSquare(Square *const square)
{
    // Falta implementacion.
}

void DrawSquare(const Square *const square)
{
    DrawRectangle(
        square->position.x,
        square->position.y,
        square->side,
        square->side,
        square->color
    );
}