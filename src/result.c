#include "../headers/result.h"
#include <stdio.h>
#include <stdlib.h>

Result NewVector2Result(Vector2 point)
{
    Result result = {0};
    
    result.value = (Vector2*) malloc(sizeof(Vector2)); 
    *((Vector2*) result.value) = point;
    result.ok = true;
    
    return result;
}

Result NewEmptyResult(int __empty)
{
    Result result = {0};
    result.value = NULL;
    result.ok = false;

    return result;
}

void FreeResult(Result *result)
{
    if (result->value != NULL)
    {
        free(result->value);
        result->value = NULL;
    }
}