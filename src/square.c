#include "../headers/square.h"
#include "../headers/global.h"

extern Global global;

//******************************************************************
//******************FIRMAS DE FUNCIOANES STATIC*********************
//******************************************************************
static bool __IsInsideSquare(const Square *const square);
//******************************************************************
//*********************IMPLEMENTACION DE FUNCIONES******************
//******************************************************************
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
    if (__IsInsideSquare(square))
    {
        square->color = RED;
    }
    else
    {
        square->color = BLACK;
    }
    
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

//******************************************************************
//****************IMAPLEMENTACION FUNCIOANES STATIC*****************
//******************************************************************
static bool __IsInsideSquare(const Square *const square)
{
    Vector2 mousePosition = GetMousePositionGlobal(&global);

    if (mousePosition.x > square->position.x && 
        mousePosition.x < (square->position.x + square->side) &&
        mousePosition.y > square->position.y &&
        mousePosition.y < (square->position.y + square->side))
    {
        return true;
    }

    return false;
}