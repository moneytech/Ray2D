#if !defined(TREE_H)
#define TREE_H

typedef struct Tree
{
    int value;
    int height;
    struct Tree *left;
    struct Tree *right;

} Tree;

Tree *NewTree(void);

void AddElementTree(Tree **const tree, int value); 

void DeleteTree(Tree **const tree);

void PrintTree(const Tree *const tree);

void DeleteElementTree(Tree **const tree, int value);

#endif //TREE_H