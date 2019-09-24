#if !defined(NODE_H)
#define NODE_H

#include "boundary.h"

typedef struct Node
{
    Boundary *boundaries;
    int size;
    int id;

} Node;

Node NewNode(int size, int id);

void AddElementNode(Node *const node, Boundary boundary, int index);

const Boundary *GetBoundary(const Node *const node);

const int GetSizeBoundary(const Node *const node);

const int GetIdBoundary(const Node *const node);

void DeleteBoundary(Node *const node);

#endif //NODE_H