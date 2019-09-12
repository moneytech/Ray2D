#if !defined(GLOBAL_H)
#define GLOBAL_H

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
    float velocityPlayer; // velocidad del jugador. 
    int spaceGrid2D; // espacio de los cuadrados de la grilla.
    int numLinesGrid2D; // numero de lineas que se renderizan en la grilla.

} Global;

Global NewGlobal();

const int GetScreenWidthGlobal(const Global *const global);

const int GetScreenHeightGlobal(const Global *const global);

const int GetFPSGlobal(const Global *const global);

const char *GetTitleGlobal(const Global *const global);

#endif //GLOBAL_H