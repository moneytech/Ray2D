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
        OVE_BLUE
    );

    return menu;
}

void UpdateMenu(Menu *const menu)
{
    UpdatePanel(&menu->panelDown);
}

void DrawMenu(const Menu *const menu)
{
    DrawPanel(&menu->panelDown);
}

void FreeMenu(Menu *const menu)
{
    FreePanel(&menu->panelDown);
}