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
    Section section;
    
}Global;

Global NewGlobal();

#endif //GLOBAL_H