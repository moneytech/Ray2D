#include "../headers/panel.h"
#include "../headers/global.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern Global global;

//******************************************************************
//******************FIRMAS DE FUNCIOANES STATIC*********************
//******************************************************************
static void __ResizeWindowUpdatePanel(Panel *const panel);

//******************************************************************
//*********************IMPLEMENTACION DE FUNCIONES******************
Panel NewPanel(float x, float y, float width, float height, Color color)
{
    Panel panel = {0};

    panel.rect.x = x;
    panel.rect.y = y;
    panel.rect.width = width;
    panel.rect.height = height;
    panel.color = color;
    panel.sizeWindow = GetScreenGlobal(&global);

    return panel;
}

void UpdatePanel(Panel *const panel)
{
    __ResizeWindowUpdatePanel(panel);

    if (panel->color.r != global.color1.r ||
        panel->color.g != global.color1.g ||
        panel->color.b != global.color1.b)
        panel->color = global.color1;
}

void DrawPanel(const Panel *const panel)
{
    DrawRectangle(
        panel->rect.x,
        panel->rect.y,
        panel->rect.width,
        panel->rect.height,
        panel->color
    );

    DrawRectangleLinesEx(
        (Rectangle) {
            panel->rect.x,
            panel->rect.y,
            panel->rect.width,
            panel->rect.height
        },
        4,
        global.color3
    );

    Vector2 mousePosition = GetMousePositionGlobal(&global);
    char cmousePosition[100];
    sprintf(cmousePosition, "x: %d, y: %d", (int) mousePosition.x, (int) mousePosition.y);

    DrawTextEx(
        global.font_b03,
        cmousePosition,
        (Vector2) {panel->rect.x + 30, panel->rect.y + 6},
        16,
        1,
        global.color3
    );
}

void FreePanel(Panel *const panel)
{
    // UnloadFont(panel->font);
    printf("PANEL VACIADO...\n");
}

//******************************************************************
//****************IMAPLEMENTACION FUNCIOANES STATIC*****************
//******************************************************************
static void __ResizeWindowUpdatePanel(Panel *const panel)
{
    int screenWidth = GetScreenWidthGlobal(&global);
    int screenHeight = GetScreenHeightGlobal(&global);

    if (panel->sizeWindow.x != screenWidth || panel->sizeWindow.y != screenHeight)
    {
        panel->sizeWindow.x = screenWidth;
        panel->sizeWindow.y = screenHeight;
        panel->rect.width = screenWidth;
        panel->rect.y = screenHeight - panel->rect.height;
    }
}