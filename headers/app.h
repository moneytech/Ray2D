#if !defined(APP_H)
#define APP_H

#include "raylib.h"
#include "player.h"
#include "boundary.h"

typedef struct App
{
    int screenWidth;
    int screenHeight;
    float fps;
    const char *title;
    Color background;

    Player player;
    Boundary *walls;

}App;

App NewApp(const int screenWidth, const int screenHeight, const char *title);

void RunApp(App *const app);

void FreeApp(App *const app);

#endif //APP_H