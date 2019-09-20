#if !defined(SQUARE_H)
#define SQUARE_H

#include "raylib.h"

typedef struct Square
{
    Vector2 center;
    Vector2 position; 

    float side; 
    float scale;
    bool active;

    Color color;

} Square;

Square NewSquare(float x, float y, float side, Color color);

void UpdateSquare(Square *const square);

void DrawSquare(const Square *const square);

#endif //SQUARE_H