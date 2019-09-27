#include "../headers/menu.h"
#include "../headers/global.h"

extern Global global;

Menu NewMenu()
{
    Menu menu = {0};
    menu.panelDown = NewPanel(
        0,
        global.screenHeight - 30,
        global.screenWidth,
        30,
        global.color1
    );

    menu.option = NewOption(
        0,
        0,
        250.0f,
        global.screenHeight,
        global.color1
    );

    return menu;
}

void UpdateMenu(Menu *const menu)
{
    UpdateOption(&menu->option);
    UpdatePanel(&menu->panelDown);
}

void DrawMenu(const Menu *const menu)
{
    DrawOption(&menu->option);
    DrawPanel(&menu->panelDown);
}

void FreeMenu(Menu *const menu)
{
    FreePanel(&menu->panelDown);
    FreeOption(&menu->option);
}