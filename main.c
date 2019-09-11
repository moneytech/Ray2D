#include "raylib.h"
#include "headers/app.h"


int main(void)
{
    // Crea una instancia de app, recibe el ancho, alto y
    // el titulo de la ventana.
    App app = NewApp(800, 600, "Overflow Engine");
    // ciclo que actualiza  dibuja los 
    // elementos.
    RunApp(&app);
    // libera los recursos que han sido
    // reservados.
    FreeApp(&app);

    return 0;
}
