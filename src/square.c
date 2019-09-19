#include "../headers/square.h"

Square NewSquare(float x, float y, float side, Color color)
{
    Square square = {0}; 

    square.position = (Vector2) {x, y};
    square.side = side;
    square.scale = 1.0f;
    square.color = color;

    square.center = (Vector2) 
    {
        square.position.x + (side/2),        
        square.position.y + (side/2)        
    };

    return square;
}

void UpdateSquare(Square *const square)
{
    
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
    
    DrawRectangleLinesEx(
        (Rectangle) {
            square->position.x,
            square->position.y,
            square->side,
            square->side
        }, 
        1, 
        BEIGE
    );
}