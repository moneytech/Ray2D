#if !defined(RESULT_H)
#define RESULT_H

#include "raylib.h"

#define FIRST(_1, ...) (_1)
#define NewResult(...) _Generic(FIRST(__VA_ARGS__), Vector2: NewVector2Result, int: NewEmptyResult)(__VA_ARGS__)

typedef struct Result
{
    void *value;
    bool ok;

}Result;

Result NewVector2Result(Vector2 point);

Result NewEmptyResult(int __empty);

void FreeResult(Result *result);


#endif //RESULT_H