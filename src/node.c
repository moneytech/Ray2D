#include "../headers/node.h"
#include <stdlib.h>

Node NewNode(int size, int id)
{
    Node node = {0};
    node.boundaries = (Boundary *) malloc(sizeof(Boundary) * size);
    node.size = size;
    node.id = id;

    return node;
}

void AddElementNode(Node *const node, Boundary boundary, int index)
{
    if (node != NULL)
        node->boundaries[index] = boundary;
}

const Boundary *GetBoundary(const Node *const node)
{
    return node->boundaries;
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
    if (node->boundaries != NULL)
    {
        free(node->boundaries);
        node->boundaries = NULL;
    }
}