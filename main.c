#include "raylib.h"
#include "headers/app.h"

App *globalApp;

int main(void)
{
    // Crea una instancia de app, recibe el ancho, alto y
    // el titulo de la ventana.
    App app = NewApp(640, 480, "Ray Casting");
    globalApp = &app;

    // ciclo que actualiza  dibuja los 
    // elementos.
    RunApp(&app);
    // libera los recursos que han sido
    // reservados.
    FreeApp(&app);

    return 0;
}