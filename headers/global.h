#if !defined(GLOBAL_H)
#define GLOBAL_H

#include "raylib.h"

typedef enum Section
{
    CANVAS,
    MAP
    
} Section;

/**
 * La estructura global permite
 * almacenar todos las variables
 * de uso global para la aplicacion.
*/
typedef struct Global
{
    int screenWidth; // ancho de la ventana.
    int screenHeight; // altura de la ventana.
    int fps; // frames por segundos.
    const char *title; // titulo de la ventana.
    Section section; // seccion en ejecucion (Canvas|Map).
    float velocityPlayer; // velocidad del player. 
    float visionAngle; // angulo de vision del player.
    const Vector2 *posPlayer;

    float diffAngle;
    float visionDistance;

    int spaceGrid2D; // espacio de los cuadrados de la grilla.
    int numLinesGrid2D; // numero de lineas que se renderizan en la grilla.

    int keySectionCanvas;
    int keySectionMap;

    Vector2 center;

} Global;

Global NewGlobal();

const int GetScreenWidthGlobal(const Global *const global);

const int GetScreenHeightGlobal(const Global *const global);

const Vector2 GetScreenGlobal(const Global *const global);

const int GetFPSGlobal(const Global *const global);

const char *GetTitleGlobal(const Global *const global);

void SetSectionGlobal(Global *const global, Section section);

Section GetCurrentSectionGlobal(const Global *const global);

#endif //GLOBAL_H