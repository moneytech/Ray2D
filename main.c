#include "raylib.h"
#include "headers/app.h"
#include "headers/ocamera.h"

OCamera *ocamera;

int main(void)
{
    // Crea una instancia de app, recibe el ancho, alto y
    // el titulo de la ventana.
    App app = NewApp();
    // globalWalls = &app.scene.walls;
    ocamera = &app.ocamera;
    // ciclo que actualiza  dibuja los
    // elementos.
    RunApp(&app);
    // libera los recursos que han sido
    // reservados.
    FreeApp(&app);

    return 0;
}