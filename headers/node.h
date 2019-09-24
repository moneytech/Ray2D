#if !defined(NODE_H)
#define NODE_H

#include "boundary.h"

typedef struct Node
{
    Boundary *boundary;
    int size;
    int id;

} Node;

Node NewNode(int size, int id);

const Boundary *GetBoundary(const Node *const node);

const int GetSizeBoundary(const Node *const node);

const int GetIdBoundary(const Node *const node);

void DeleteBoundary(Node *const node);

#endif //NODE_H