#if !defined(GLOBAL_H)
#define GLOBAL_H

typedef enum Section
{
    CANVAS,
    MAP
}Section;

/**
 * La estructura global permite
 * almacenar todos las variables
 * de uso global para la aplicacion.
*/
typedef struct Global
{
    int screenWidth;
    int screenHeight;
    int fps;
    const char *title;
    Section section;

}Global;

Global NewGlobal();

const int GetScreenWidthGlobal(const Global *const global);

const int GetScreenHeightGlobal(const Global *const global);

const int GetFPSGlobal(const Global *const global);

const char *GetTitleGlobal(const Global *const global);

#endif //GLOBAL_H