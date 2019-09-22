#if !defined(TREE_H)
#define TREE_H

typedef struct Tree
{
    int index;
    struct Tree *left;
    struct Tree *right;

} Tree;

void AddElmentTree(Tree **const tree, int index);

void DeleteTree(Tree **tree);

void DeleteElementTree(Tree **const tree, int index);

int GetElementTree(const Tree *const tree, int index); 

void WalkTree(const Tree *tree);

#endif //TREE_H