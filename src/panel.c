#include "../headers/panel.h"
#include "../headers/global.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern Camera2D camera;
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

    panel.text = "x: 0, y: 0";
    // panel.font = LoadFont("data/fonts/04B_03__.TTF");
    
    panel.panelColor = color;
    panel.textColor = RAYWHITE;
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
        panel->panelColor
    );

    char text[30] = "";
    // int x = (GetMousePosition().x - (global.screenWidth/2)) + global.posPlayer->x;
    // int y = (GetMousePosition().y - (global.screenHeight/2)) + global.posPlayer->y;
    
    int x = GetMousePosition().x - global.center.x + global.posPlayer->x;
    int y = GetMousePosition().y - global.center.y + global.posPlayer->y;

    sprintf(text, "x: %d, y: %d", x , y); 
    DrawText(
        text,
        panel->rect.x + 10, 
        panel->rect.y + 5,
        18,
        panel->textColor
    );
}

void FreePanel(Panel *const panel)
{
    // UnloadFont(panel->font);
    printf("FUENTE  VACIADA...\n");
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