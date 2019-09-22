#include "../headers/tree.h"
#include <stdlib.h>
#include <stdio.h>

//******************************************************************
//******************FIRMAS DE FUNCIOANES STATIC*********************
//******************************************************************
static void __WalkTree(Tree *const tree);

//******************************************************************
//*********************IMPLEMENTACION DE FUNCIONES******************
//******************************************************************
void AddElmentTree(Tree **const tree, int index)
{
    if ((*tree) == NULL)
    {
        (*tree) = (Tree *) malloc(sizeof(Tree));
        (*tree)->index = index;
        (*tree)->left = NULL;
        (*tree)->right = NULL;
    }
    else
    {
        if (index > (*tree)->index)
            AddElmentTree(&((*tree)->right), index);
        
        else if (index < (*tree)->index)
            AddElmentTree(&((*tree)->left), index); 
    }
}

void DeleteTree(Tree **tree)
{
    if ((*tree) != NULL)
    {
        DeleteTree(&(*tree)->left);
        DeleteTree(&(*tree)->right);
        
        // printf("index: %d\n", (*tree)->index);
        free((*tree));
        (*tree) = NULL;
    }
}

void WalkTree(const Tree *const tree)
{
    if (tree != NULL)
    {
        printf("index: %d\n", tree->index);
        WalkTree(tree->left);
        WalkTree(tree->right);
    }
}

void DeleteElementTree(Tree **const tree, int index)
{
    // Falta implementar    
}

int GetElementTree(const Tree *const tree, int index)
{
    // Falta implementar
} 

//******************************************************************
//****************IMAPLEMENTACION FUNCIOANES STATIC*****************
//******************************************************************
/**
 * Metodo __WalkTree
 * Recorre el arbol en preOrden.
*/
static void __WalkTree(Tree *const tree)
{
    if (tree != NULL)
    {
        __WalkTree(tree->left);
        __WalkTree(tree->right);
    }
}