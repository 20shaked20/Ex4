#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include <ctype.h>

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
    pedge curr = edges;
    int dst; // in chars so i can tell if its n and then just convert other wise.
    while (TRUE)
    {
        int w = 0;
        dst = getdest();
        if ((dst == -1))
        {
            return c; // if its n return n and move to the next node!
        }
        else
        {
            scanf("%d", &w); // gets the weight
            pedge newEdge = (pedge)malloc(sizeof(edge)); // creating new edge.
            pnode endpoint = head; // the node for endpoint.
            while (endpoint->id != dst)
            {
                endpoint = endpoint->next;
            }
            newEdge ->next = NULL;
            newEdge->endpoint = endpoint;
            newEdge ->weight = w;
            curr->next = newEdge;
            curr = newEdge;
        }
    }

    return '\0';
}

void remove_edges(pedge edges)
{
    pedge tmp,curr;
    if(edges->next != NULL){
        curr = edges -> next;
        while(curr!=NULL){
            tmp = curr->next;
            free(curr);
            curr = tmp;
        }
    }
    printf("CHECKING..\n");
    edges->next = NULL;
    edges->endpoint = NULL;
    edges->weight = 0;
}