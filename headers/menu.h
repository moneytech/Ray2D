#if !defined(MENU_H)
#define MENU_H

#include "panel.h"

typedef struct Menu
{
    Panel panelDown;

} Menu;

Menu NewMenu();

void UpdateMenu(Menu *const menu);

void DrawMenu(const Menu *const menu);

void FreeMenu(Menu *const menu);

#endif //MENU_H