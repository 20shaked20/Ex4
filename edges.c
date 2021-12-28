#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#define TRUE 1

char add_edges(pedge edges, pnode head)
{
    // printf("ADDING EDGES for node: \n");
    char dst; // in chars so i can tell if its n and then just convert other wise.
    while (TRUE)
    {
        pedge curr = edges;
        int w = 0;
        // printf("enter dst: \n");
        getchar();
        scanf("%c", &dst);
        if ((dst == 'n') || (dst < '0' || dst > '9'))
        {
            break; // if its n return n and move to the next node!
        }
        else
        {
            // printf("enter weight: \n");
            scanf("%d", &w); // gets the weight
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = (pedge)malloc(sizeof(edge));
            curr->next->endpoint = &head[dst - '0']; //converts the dst to number
            curr->next->weight = w;
        }
    }
    return dst;
}

void remove_edges(pedge edges)
{
    while (edges != NULL)
    {
        pedge tmp = edges;
        edges = edges->next;
        tmp->endpoint = NULL; //empty to null.
        tmp->weight = -1; // set weight to minus -1
        free(tmp); // free memory
    }
}