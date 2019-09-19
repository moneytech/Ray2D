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