#include "../headers/helper.h"
#include <math.h>

// Funcion que devuelve el modulo de dos vectores.
float Module2VHelper(const Vector2 pto, const Vector2 pto1)
{
    float x = pow(pto.x - pto1.x, 2); 
    float y = pow(pto.y - pto1.y, 2);

    float module = sqrt(x + y); 

    return module;
}


Result UnitVectorHelper(const Vector2 pto, const Vector2 pto1)
{
    Result result = {0};
    result.ok = false;

    float module = Module2VHelper(pto, pto1);
    if (module != 0)
    {
        float x = (pto1.x - pto.x) / module;    
        float y = (pto1.y - pto.y) / module;    
        result.pto = (Vector2) {x, y};
        
        result.ok = true;
    }  

    return result;
}