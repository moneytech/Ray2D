#include "../headers/square.h"
#include "../headers/global.h"
#include "../headers/boundary.h"
#include "../headers/node.h"
#include <stdio.h>
#include <stdlib.h>

extern Global global;

// extern Boundary **globalWalls;
extern int MAX_WALLS; // MAX_WALLS debe tener un valor >= a 4.
extern int COUNT_WALLS;

//******************************************************************
//******************FIRMAS DE FUNCIOANES STATIC*********************
//******************************************************************
static bool __IsInsideSquare(const Square *const square);
//******************************************************************
//*********************IMPLEMENTACION DE FUNCIONES******************
//******************************************************************
Square NewSquare(float x, float y, float side, Color color, int id)
{
    Square square = {0}; 

    square.position = (Vector2) {x, y};
    square.side = side;
    square.scale = 1.0f;
    square.active = false;
    square.color = color;
    square.id = id;
    
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
        if (!square->active && IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            square->active = true;
            square->color = OVE_RED;

            Node node = NewNode(4, square->id);

            Boundary boundary = NewBoundary(
                (Vector2) {square->position.x, square->position.y},
                (Vector2) {square->position.x + (square->side), square->position.y}
            );
            AddElementNode(&node, boundary, 0);

            boundary = NewBoundary(
                (Vector2) {square->position.x + (square->side), square->position.y},
                (Vector2) {square->position.x + (square->side), square->position.y + (square->side)}
            );
            AddElementNode(&node, boundary, 1);

            boundary = NewBoundary(
                (Vector2) {square->position.x + (square->side), square->position.y + (square->side)},
                (Vector2) {square->position.x, square->position.y + (square->side)}
            );
            AddElementNode(&node, boundary, 2);

            boundary = NewBoundary(
                (Vector2) {square->position.x, square->position.y + (square->side)},
                (Vector2) {square->position.x, square->position.y}
            );
            AddElementNode(&node, boundary, 3);

            AddElementList(&(global.listWalls), node);
        }
        else if (square->active && IsMouseButtonDown(MOUSE_RIGHT_BUTTON))
        {
            square->active = false;
            square->color = OVE_BEIGE;
            DeleteElementList(&(global.listWalls), square->id);
        }
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
        OVE_GRAY
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