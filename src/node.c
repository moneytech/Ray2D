#include "../headers/node.h"
#include <stdlib.h>

Node NewNode(int size, int id)
{
    Node node = {0};
    node.boundary = (Boundary *) malloc(sizeof(Boundary) * size);
    node.size = size;
    node.id = id;

    return node;
}

const Boundary *GetBoundary(const Node *const node)
{
    return node->boundary;
}

const int GetSizeBoundary(const Node *const node)
{
    return node->size;
}

const int GetIdBoundary(const Node *const node)
{
    return node->id;
}

void DeleteBoundary(Node *const node)
{
    if (node->boundary != NULL)
    {
        free(node->boundary);
        node->boundary = NULL;
    }
}