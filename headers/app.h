#if !defined(APP_H)
#define APP_H

#include "raylib.h"
#include "canvas.h"
#include "scene.h"
#include "map.h"

typedef struct App
{
    Color backgroundCanvas;
    Color backgroundMap;
    
    Scene scene;
    Canvas canvas;
    Map map;

} App;

App NewApp();

void RunApp(App *const app);

void FreeApp(App *const app);

#endif //APP_H