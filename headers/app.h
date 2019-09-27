#if !defined(APP_H)
#define APP_H

#include "raylib.h"
#include "canvas.h"
#include "scene.h"
#include "menu.h"
#include "map.h"
#include "ocamera.h"

typedef struct App
{
    Color backgroundCanvas;
    Color backgroundMap;
    
    Menu menu;
    Scene scene;
    Canvas canvas;
    Map map;

    Image icon;

    OCamera ocamera;

} App;

App NewApp();

void RunApp(App *const app);

void FreeApp(App *const app);

#endif //APP_H