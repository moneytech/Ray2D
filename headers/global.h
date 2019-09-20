#if !defined(GLOBAL_H)
#define GLOBAL_H

#include "raylib.h"


#define OVE_DARKMARRON (Color) {43.0f, 40.0f, 33.0f, 255.0f} 
#define OVE_MARRON (Color) {98.0f, 76.0f, 60.0f, 255.0f} 
#define OVE_YELLOW (Color) {224.0f, 200.0f, 114.0f, 255.0f} 
#define OVE_GREEN (Color) {62.0f, 105.0f, 88.0f, 255.0f} 
#define OVE_RED (Color) {176.0f, 58.0f, 72.0f, 255.0f} 
#define OVE_GRAY (Color) {177.0f, 165.0f, 141.0f, 255.0f} 
#define OVE_DARKGRAY (Color) {93.0f, 114.0f, 117.0f, 255.0f} 
#define OVE_DARKBEIGE (Color) {217.0f, 172.0f, 139.0f, 255.0f} 
#define OVE_BEIGE (Color) {227.0f, 207.0f, 180.0f, 255.0f} 
#define OVE_DARKBLUE (Color) {36.0f, 61.0f, 92.0f, 255.0f} 
#define OVE_BLUE (Color) {92.0f, 139.0f, 147.0f, 255.0f} 
#define OVE_ORAGEN (Color) {212.0f, 128.0f, 77.0f, 255.0f} 

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

} Global;

Global NewGlobal();

const int GetScreenWidthGlobal(const Global *const global);

const int GetScreenHeightGlobal(const Global *const global);

const Vector2 GetScreenGlobal(const Global *const global);

const int GetFPSGlobal(const Global *const global);

const char *GetTitleGlobal(const Global *const global);

void SetSectionGlobal(Global *const global, Section section);

Section GetCurrentSectionGlobal(const Global *const global);

void UpdateCenterGlobal(Global *const global);

Vector2 GetMousePositionGlobal(const Global *const global);

#endif //GLOBAL_H