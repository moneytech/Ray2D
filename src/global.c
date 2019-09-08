#include "../headers/global.h"

Global NewGlobal()
{
    Global global = {0};
    global.section = CANVAS;

    return global;
}