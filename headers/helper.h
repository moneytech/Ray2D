#if !defined(HELPER_H)
#define HELPER_H

#include "raylib.h"

typedef struct Result
{
    bool ok;
    Vector2 pto; // Hacer generico.

}Result;

// Funcion que devuelve el modulo de dos vectores.
float Module2VHelper(const Vector2 pto, const Vector2 pto1);

Result UnitVectorHelper(const Vector2 pto, const Vector2 pto1);

#endif //HELPER_H