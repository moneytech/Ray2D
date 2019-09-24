#if !defined(LIST_H)
#define LIST_H

#include "node.h"

typedef struct List
{
    Node node;

    struct List *next;

} List;

List *NewList(void);

void AddElementList(List **const list, Node node);

void DeleteElementList(List **const list, int id);

void FreeList(List **const list);

#endif //LIST