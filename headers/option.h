#if !defined(OPTION_H)
#define OPTION_H

#include "raylib.h"

typedef struct Option
{
    Rectangle rect;
    Color color;
    Vector2 sizeWindow;

} Option;

Option NewOption(float x, float y, float width, float height, Color color);

void UpdateOption(Option *const option);

void DrawOption(const Option *const option);

void FreeOption(Option *const option);

#endif //OPTION_H