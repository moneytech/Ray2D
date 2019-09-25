#include "../headers/option.h"
#include "../headers/global.h"
#include <stdio.h>

extern Global global;

//******************************************************************
//******************FIRMAS DE FUNCIOANES STATIC*********************
//******************************************************************
static void __ResizeWindowUpdateOption(Option *const option);

//******************************************************************
//*********************IMPLEMENTACION DE FUNCIONES******************
//******************************************************************
Option NewOption(float x, float y, float width, float height, Color color)
{
    Option option = {0};

    option.rect.x = x;
    option.rect.y = y;
    option.rect.width = width;
    option.rect.height = height;
    option.color = color;
    option.sizeWindow = GetScreenGlobal(&global);

    return option;
}

void UpdateOption(Option *const option)
{
    __ResizeWindowUpdateOption(option);
    
    if (option->color.r != global.color1.r ||
        option->color.g != global.color1.g ||
        option->color.b != global.color1.b)
        option->color = global.color1;
}

void DrawOption(const Option *const option)
{
    DrawRectangle(
        option->rect.x,
        option->rect.y,
        option->rect.width,
        option->rect.height,
        option->color
    );

    DrawRectangleLinesEx(
        (Rectangle) {
            option->rect.x,
            option->rect.y,
            option->rect.width,
            option->rect.height
        },
        4,
        global.color3
    );
}

void FreeOption(Option *const option)
{
    // Falta implementar
    printf("OPTION VACIADO...\n");

}

//******************************************************************
//****************IMAPLEMENTACION FUNCIOANES STATIC*****************
//******************************************************************
static void __ResizeWindowUpdateOption(Option *const option)
{
    int screenWidth = GetScreenWidthGlobal(&global);
    int screenHeight = GetScreenHeightGlobal(&global);

    if (option->sizeWindow.x != screenWidth || option->sizeWindow.y != screenHeight)
    {
        option->sizeWindow.x = screenWidth;
        option->sizeWindow.y = screenHeight;
        // option->rect.width = 100;
        option->rect.height = screenHeight;
    }
}