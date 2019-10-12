#include "../headers/list.h"
#include <stdlib.h>
#include <stdio.h>

List *NewList(void)
{
    List *list = NULL;

    return list;
}

void AddElementList(List **const list, Node node)
{
    if ((*list) == NULL)
    {   
        (*list) = (List *) malloc(sizeof(List));
        (*list)->node = node;
        (*list)->next = NULL;
    }
    else
    {
        List *auxList = (*list);
        while (auxList->next != NULL)
            auxList = auxList->next;

        auxList->next = (List *) malloc(sizeof(List));
        auxList->next->node = node;
        auxList->next->next = NULL;
    }
}

void DeleteElementList(List **const list, int id)
{
    List *auxList = (*list);
    while (auxList != NULL && auxList->next != NULL)
    {
        if (auxList->next->node.id == id)
        {
            List *auxList2 = auxList->next;
            auxList->next = auxList2->next;
            free(auxList2);
            auxList2 = NULL;
            break;
        }

        auxList = auxList->next;
    }
}

void FreeList(List **const list)
{
    List *auxList = NULL;
    while ((*list) != NULL)
    {
        auxList = (*list);
        (*list) = (*list)->next;
        free(auxList);
        auxList = NULL;
    }
}