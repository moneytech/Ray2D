#if !defined(PANEL_H)
#define PANEL_H

#include "raylib.h"

typedef struct Panel
{
    Rectangle rect;
    const char* text;
    Font font;
    Color panelColor;
    Color textColor;

} Panel;

Panel NewPanel(float x, float y, float width, float height, Color color);

void UpdatePanel(Panel *const panel);

void DrawPanel(const Panel *const panel);

void FreePanel(Panel *const panel);

#endif //PANEL_H