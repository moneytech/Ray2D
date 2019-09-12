#include "../headers/panel.h"
#include "../headers/global.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern Camera2D camera;
extern Global global;

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

    return panel;
}

void UpdatePanel(Panel *const panel)
{
    // panel->rect.x = camera.target.x;
    // panel->rect.y = camera.target.y;
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

    char *text = (char*) malloc(sizeof(char)*20);
    sprintf(text, "x: %d, y: %d", (int) GetMousePosition().x - (global.screenWidth/2) , (int) GetMousePosition().y - (global.screenHeight/2)); 

    DrawText(
        text,
        panel->rect.x + 10, 
        panel->rect.y + 5,
        18,
        panel->textColor
    );

    free(text);
    // DrawTextEx(
    //     panel->font,
    //     panel->text,
    //     (Vector2) {panel->rect.x + 10, panel->rect.y + 5},
    //     24,
    //     1.0f,
    //     panel->textColor
    // );
}

void FreePanel(Panel *const panel)
{
    // UnloadFont(panel->font);
    printf("FUENTE  VACIADA...\n");
}
