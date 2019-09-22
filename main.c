// #include "raylib.h"
// #include "headers/app.h"
// #include "headers/ocamera.h"

// OCamera *ocamera;

// int main(void)
// {
//     // Crea una instancia de app, recibe el ancho, alto y
//     // el titulo de la ventana.
//     App app = NewApp();
//     // globalWalls = &app.scene.walls;
//     ocamera = &app.ocamera;
//     // ciclo que actualiza  dibuja los
//     // elementos.
//     RunApp(&app);
//     // libera los recursos que han sido
//     // reservados.
//     FreeApp(&app);

//     return 0;
// }

#include "headers/tree.h"
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    Tree *node = NULL;
    // 2, 7, 5, 2, 6, 9, 5, 11 y 4
    AddElmentTree(&node, 2);
    AddElmentTree(&node, 7);
    AddElmentTree(&node, 5);
    AddElmentTree(&node, 2);
    AddElmentTree(&node, 6);
    AddElmentTree(&node, 9);
    AddElmentTree(&node, 5);
    AddElmentTree(&node, 11);
    AddElmentTree(&node, 4);

    WalkTree(node);

    printf("first: %d\n", node->index);

    DeleteTree(&node);

    return 0;
}