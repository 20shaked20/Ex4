#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include <ctype.h>
#define TRUE 1
#define FALSE 0
char c; 

int getdest()
{
    int dst;
    scanf(" %c", &c);
    if (!isdigit(c))
        return -1;
    dst = c - '0';
    scanf("%c", &c);
    while (c != ' ')
    {
        dst *= 10 + c - '0';
        scanf("%c", &c);
    }
    return dst;
}

char add_edges(pedge edges, pnode head)
{
    // printf("ADDING EDGES for node: \n");
    int dst; // in chars so i can tell if its n and then just convert other wise.
    while (TRUE)
    {
        int w = -1;
        // printf("enter dst: \n");
        dst = getdest();
        if ((dst == -1))
        {
            printf("HEAD ID : %d \n", head->id);
            return c; // if its n return n and move to the next node!
        }
        else
        {
            // printf("enter weight: \n");
            scanf("%d", &w); // gets the weight
            pedge curr = edges;
            while (curr->next != NULL) // get the last edge.
            {
                curr = curr->next;
            }
            pnode endpoint = head; // the node for endpoint.
            while (endpoint->id != dst)
            {
                endpoint = endpoint->next;
            }
            curr->next = (pedge)malloc(sizeof(edge));
            curr->next->endpoint = endpoint; //converts the dst to number
            curr->next->weight = w;
        }
    }
   
    return '\0';
}

void remove_edges(pedge edges)
{
    while (edges != NULL)
    {
        pedge tmp = edges;
        edges = edges->next;
        tmp->endpoint = NULL; //empty to null.
        tmp->weight = -1;     // set weight to minus -1
        free(tmp);            // free memory
    }
}