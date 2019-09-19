#include "../headers/ocamera.h"
#include "../headers/global.h"
#include <stdlib.h>
#include <stdio.h>

extern Global global;

//******************************************************************
//******************FIRMAS DE FUNCIOANES STATIC*********************
//******************************************************************
static void __InitCameraOCamera(OCamera *const ocamera);
//******************************************************************
//*********************IMPLEMENTACION DE FUNCIONES******************
//******************************************************************
OCamera NewOCamera(void)
{
    OCamera ocamera = {0};
    
    ocamera.position = (Vector2) {0.0f, 0.0f};
    __InitCameraOCamera(&ocamera);

    return ocamera;
}

Camera2D *GetCameraOCamera(OCamera *const ocamera)
{
    return &ocamera->camera;
}

void UpdateOCamera(OCamera *const ocamera)
{
    printf("x: %f, y: %f\n", GetMousePositionGlobal(&global).x, GetMousePositionGlobal(&global).y);
}

void ResizeOCamera(OCamera *const ocamera)
{
    __InitCameraOCamera(ocamera);    
}

//******************************************************************
//****************IMAPLEMENTACION FUNCIOANES STATIC*****************
//******************************************************************
static void __InitCameraOCamera(OCamera *const ocamera)
{
    float x = (GetScreenWidth() / 2);
    float y = (GetScreenHeight() / 2);

    if (global.posPlayer != NULL)
    {
        x -= global.posPlayer->x;
        y -= global.posPlayer->y;

        ocamera->camera.target = (Vector2) {
            global.posPlayer->x + 20,
            global.posPlayer->y + 20
        };
    }
    else
        ocamera->camera.target = (Vector2){0.0f, 0.0f};
    
    ocamera->camera.offset = (Vector2) {x, y};
    ocamera->camera.zoom = 1.0f;
    ocamera->camera.rotation = 0.0f;
}
