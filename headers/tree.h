#if !defined(TREE_H)
#define TREE_H

#include "node.h"
#include "ray2d.h"

typedef struct Tree
{
    Node node;
    
    int id;
    int height;

    struct Tree *left;
    struct Tree *right;

} Tree;

Tree *NewTree(void);

void AddElementTree(Tree **const tree, Node value); 

void DeleteTree(Tree **const tree);

void PrintTree(const Tree *const tree);

void DeleteElementTree(Tree **const tree, int id);

#endif //TREE_H