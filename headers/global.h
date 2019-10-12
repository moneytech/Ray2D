#if !defined(GLOBAL_H)
#define GLOBAL_H

#include "raylib.h"
#include "boundary.h"
#include "list.h"

// COLOR MIST GB
#define OVE_MIST_COLOR0 (Color) {45.0f, 27.0f, 0.0f, 255.0f}
#define OVE_MIST_COLOR1 (Color) {30.0f, 96.0f, 110.0f, 255.0f}
#define OVE_MIST_COLOR2 (Color) {90.0f, 185.0f, 168.0f, 255.0f}
#define OVE_MIST_COLOR3 (Color) {196.0f, 240.0f, 194.0f, 255.0f}


// COLOR CRIMSON
#define OVE_CRIMSON_COLOR0 (Color) {27.0f, 3.0f, 38.0f, 255.0f}
#define OVE_CRIMSON_COLOR1 (Color) {122.0f, 28.0f, 75.0f, 255.0f}
#define OVE_CRIMSON_COLOR2 (Color) {186.0f, 80.0f, 68.0f, 255.0f}
#define OVE_CRIMSON_COLOR3 (Color) {239.0f, 249.0f, 214.0f, 255.0f}

// COLOR DIRTYBOY
#define OVE_DIRTYBOY_COLOR0 (Color) {31.0f, 31.0f, 31.0f, 255.0f}
#define OVE_DIRTYBOY_COLOR1 (Color) {77.0f, 83.0f, 60.0f, 255.0f}
#define OVE_DIRTYBOY_COLOR2 (Color) {139.0f, 149.0f, 109.0f, 255.0f}
#define OVE_DIRTYBOY_COLOR3 (Color) {196.0f, 207.0f, 161.0f, 255.0f}

// COLOR AYY4
#define OVE_AYY4_COLOR0 (Color) {0.0f, 48.0f, 59.0f, 255.0f}
#define OVE_AYY4_COLOR1 (Color) {255.0f, 119.0f, 119.0f, 255.0f}
#define OVE_AYY4_COLOR2 (Color) {255.0f, 206.0f, 150.0f, 255.0f}
#define OVE_AYY4_COLOR3 (Color) {241.0f, 242.0f, 218.0f, 255.0f}

// COLOR RUSTIC
#define OVE_RUSTIC_COLOR0 (Color) {44.0f, 33.0f, 55.0f, 255.0f}
#define OVE_RUSTIC_COLOR1 (Color) {118.0f, 68.0f, 98.0f, 255.0f}
#define OVE_RUSTIC_COLOR2 (Color) {169.0f, 104.0f, 104.0f, 255.0f}
#define OVE_RUSTIC_COLOR3 (Color) {237.0f, 180.0f, 161.0f, 255.0f}

// COLOR KIROKAZE GAMEBOY
#define OVE_KIROKAZE_COLOR0 (Color) {51.0f, 44.0f, 80.0f, 255.0f}
#define OVE_KIROKAZE_COLOR1 (Color) {70.0f, 135.0f, 143.0f, 255.0f}
#define OVE_KIROKAZE_COLOR2 (Color) {148.0f, 227.0f, 68.0f, 255.0f}
#define OVE_KIROKAZE_COLOR3 (Color) {226.0f, 243.0f, 228.0f, 255.0f}

// COLOR LINKS GAMEBOY
#define OVE_LINKS_COLOR0 (Color) {90.0f, 57.0f, 33.0f, 255.0f}
#define OVE_LINKS_COLOR1 (Color) {107.0f, 140.0f, 66.0f, 255.0f}
#define OVE_LINKS_COLOR2 (Color) {123.0f, 198.0f, 123.0f, 255.0f}
#define OVE_LINKS_COLOR3 (Color) {255.0f, 255.0f, 181.0f, 255.0f}

// COLOR MUDDYSAND
#define OVE_MUDDYSAND_COLOR0 (Color) {57.0f, 56.0f, 41.0f, 255.0f}
#define OVE_MUDDYSAND_COLOR1 (Color) {123.0f, 113.0f, 98.0f, 255.0f}
#define OVE_MUDDYSAND_COLOR2 (Color) {180.0f, 165.0f, 106.0f, 255.0f}
#define OVE_MUDDYSAND_COLOR3 (Color) {230.0f, 214.0f, 156.0f, 255.0f}


// COLOR GLOBAL
#define OVE_COLOR0 OVE_MIST_COLOR0
#define OVE_COLOR1 OVE_MIST_COLOR1
#define OVE_COLOR2 OVE_MIST_COLOR2
#define OVE_COLOR3 OVE_MIST_COLOR3


typedef enum Section
{
    CANVAS,
    MAP
    
} Section;

typedef struct Line 
{
    Vector2 pto0;
    Vector2 pto1;
    
} Line;

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

    Boundary **walls;
    int maxWalls;
    int countWalls;

    List *listWalls;
    int wallID;

    // arreglo
    int indexTheme;
    
    // Colores
    Color color0;
    Color color1;
    Color color2;
    Color color3;

    // Fuentes
    Font font_b03;

} Global;

Global NewGlobal();

void InitDataGlobal(Global *const global);

const int GetScreenWidthGlobal(const Global *const global);

const int GetScreenHeightGlobal(const Global *const global);

const Vector2 GetScreenGlobal(const Global *const global);

const int GetFPSGlobal(const Global *const global);

const char *GetTitleGlobal(const Global *const global);

void SetSectionGlobal(Global *const global, Section section);

Section GetCurrentSectionGlobal(const Global *const global);

void UpdateCenterGlobal(Global *const global);

Vector2 GetMousePositionGlobal(const Global *const global);

void FreeGlobal(Global *const global);

void UpdateGlobal(Global *const global);

#endif //GLOBAL_H