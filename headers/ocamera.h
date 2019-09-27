#if !defined(OCAMERA_H)
#define OCAMERA_H

#include "raylib.h"

typedef struct OCamera
{
    Camera2D camera;
    Vector2 position;

} OCamera;

OCamera NewOCamera(void);

Camera2D *GetCameraOCamera(OCamera *const ocamera);

void UpdateOCamera(OCamera *const ocamera);

void ResizeOCamera(OCamera *const ocamera);

#endif //OCAMERA_H