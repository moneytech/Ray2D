#if !defined(APP_H)
#define APP_H

#include "raylib.h"

typedef struct App
{
    int screenWidth;
    int screenHeight;
    float fps;
    bool close;
    const char *title;
    Color background;

}App;

App NewApp(int screenWidth, int screenHeight, const char *title);

void RunApp(App *const app);

void FreeApp(App *app);

#endif //APP_H