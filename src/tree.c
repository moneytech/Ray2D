#include "../headers/tree.h"
#include <stdlib.h>
#include <stdio.h>

#define max(a , b)(((a) > (b)) ? (a) : (b))

//******************************************************************
//******************FIRMAS DE FUNCIOANES STATIC*********************
//******************************************************************

static void __SwingingTree(Tree **const tree);

static void __UpdateHeightTree(Tree *const tree);

static int __HeightNodeTree(const Tree *const tree);

static void __SimpleRotationLeftTree(Tree **const tree);

static void __SimpleRotationRightTree(Tree **const tree);

static void __DoubleRotationLeftTree(Tree **const tree);

static void __DoubleRotationRightTree(Tree **const tree);

// El tipo que retorna cambia segun el dato que almacena el arbol (OJO)
static Node *__DeleteElementMinTree(Tree **const tree);

//******************************************************************
//*********************IMPLEMENTACION DE FUNCIONES******************
//******************************************************************
 
Tree *NewTree(void)
{
    Tree *tree = NULL;
    return tree;
}

void AddElementTree(Tree **const tree, Node node)
{
    if ((*tree) == NULL)
    {
        (*tree) = (Tree *) malloc(sizeof(Tree));
        (*tree)->node = node;
        (*tree)->height = 0;
        (*tree)->left = NULL;
        (*tree)->right = NULL;
    }
    else
    {
        if ((*tree)->node.id < node.id)
            AddElementTree(&(*tree)->right, node);
        
        else if ((*tree)->node.id > node.id)
            AddElementTree(&(*tree)->left, node);

        __SwingingTree(&(*tree));
        __UpdateHeightTree((*tree));
    }
}

void DeleteTree(Tree **const tree)
{
    if ((*tree) != NULL)
    {
        DeleteTree(&(*tree)->left);
        DeleteTree(&(*tree)->right);

        free((*tree));
        (*tree) = NULL;
    }
}

void PrintTree(const Tree *const tree)
{
    if (tree != NULL)
    {
        printf("id: %d, height: %d \n", tree->node.id, tree->height);
        PrintTree(tree->left);
        PrintTree(tree->right);
    }
}

void DeleteElementTree(Tree **const tree, int id)
{
    if ((*tree) != NULL)
    {
        if ((*tree)->node.id < id)
            DeleteElementTree(&(*tree)->right, id);
    
        else if ((*tree)->node.id < id)
            DeleteElementTree(&(*tree)->left, id);
        
        else
        {
            if ((*tree)->right == NULL && (*tree)->left == NULL)
            {
                free((*tree));
                (*tree) = NULL;
            }
            else if ((*tree)->right != NULL && (*tree)->left == NULL)
            {
                Tree *auxTree = (*tree)->right;
                free((*tree));
                (*tree) = NULL;
                (*tree) = auxTree;
            }
            else if ((*tree)->right == NULL && (*tree)->left != NULL)
            {
                Tree *auxTree = (*tree)->left;
                free((*tree));
                (*tree) = NULL;
                (*tree) = auxTree; 
            }   
            else
                 (*tree)->node = *__DeleteElementMinTree(&(*tree)->right);

            __SwingingTree(&(*tree));
            __UpdateHeightTree((*tree));
        }
    }
}

//******************************************************************
//****************IMAPLEMENTACION FUNCIOANES STATIC*****************
//******************************************************************

static void __SwingingTree(Tree **const tree)
{
    if ((*tree) != NULL)
    {
        // Desequilibrio hacia la izquierda.
        if ((__HeightNodeTree((*tree)->left) - __HeightNodeTree((*tree)->right)) == 2) 
        {
            if (__HeightNodeTree((*tree)->left->left) >= __HeightNodeTree((*tree)->left->right))
                __SimpleRotationRightTree(&(*tree));
            else
                __DoubleRotationRightTree(&(*tree));
        } 
        // Desequilibrio hacia la derecha.
        else if ((__HeightNodeTree((*tree)->right) - __HeightNodeTree((*tree)->left)) == 2)
        {
            if (__HeightNodeTree((*tree)->right->right) >= __HeightNodeTree((*tree)->right->left))
                __SimpleRotationLeftTree(&(*tree));
            else
                __DoubleRotationLeftTree(&(*tree));
        }
    }
}

static void __UpdateHeightTree(Tree *const tree)
{
    if (tree != NULL)
        tree->height = max(__HeightNodeTree(tree->left), __HeightNodeTree(tree->right)) + 1;
}

static int __HeightNodeTree(const Tree *const tree)
{
    return (tree == NULL) ? -1 : tree->height;
}

static void __SimpleRotationLeftTree(Tree **const tree)
{
    if ((*tree) != NULL)
    {
        Tree *auxTree = NULL;
        auxTree = (*tree)->right;
        (*tree)->right = auxTree->left;
        auxTree->left = (*tree);
        __UpdateHeightTree(*tree);
        __UpdateHeightTree(auxTree);

        (*tree) = auxTree;
    }
}

static void __SimpleRotationRightTree(Tree **const tree)
{
    if ((*tree) != NULL)
    {
        Tree *auxTree = NULL;
        auxTree = (*tree)->left;
        (*tree)->left = auxTree->right;
        auxTree->right = (*tree);

        __UpdateHeightTree(*tree);
        __UpdateHeightTree(auxTree);

        (*tree) = auxTree;
    }
}

static void __DoubleRotationLeftTree(Tree **const tree)
{
    if ((*tree) != NULL)
    {
        __SimpleRotationRightTree(&(*tree));
        __SimpleRotationLeftTree(&(*tree));
    }
}

static void __DoubleRotationRightTree(Tree **const tree)
{
    if ((*tree) != NULL)
    {
        __SimpleRotationRightTree(&(*tree));
        __SimpleRotationLeftTree(&(*tree));
    }
}

static Node *__DeleteElementMinTree(Tree **const tree)
{
    if ((*tree) != NULL)
    {
        if ((*tree)->left != NULL)
        {
            Node *node = __DeleteElementMinTree(&(*tree)->left);
            __SwingingTree(&(*tree));
            __UpdateHeightTree((*tree));
            return node;
        }
        else
        {   
            Node *node = &(*tree)->node;
            Tree *auxTree = (*tree);
            (*tree) = (*tree)->right;
            free(auxTree);
            auxTree = NULL;
            return &(*node);
        }
    }

    return NULL;
}