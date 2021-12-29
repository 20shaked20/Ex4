#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

char add_node(pnode head)
{
    int id = 0;
    int exist = -1;
    char c;
    printf("ADDING NODE \n");
    getchar();
    scanf("%d", &id); // gets the id of node we operates
    printf("%d : \n", id);
    //checking if the node exists, if so, we'll have to remove the edges of it, other wise just add it.
    pnode existNode = head;
    while (existNode != NULL)
    {
        if (existNode->id == id)
        { // if the node does exsits, we'll remove its edges.
            printf("NODE exists ");
            remove_edges(existNode->edges);
            exist = id;
            break;
        }
        existNode = existNode->next;
    }
    if (exist == -1)
    { // if the node does not exist, simply add it and add the new edges.
        pnode last = head;
        while (last->next != NULL)
        {
            last = last->next;
        }
        pnode newNode = (struct GRAPH_NODE_ *)malloc(sizeof(struct GRAPH_NODE_));
        newNode->id = id;
        newNode->next = NULL;
        newNode->edges = NULL;
        newNode->edges = (pedge)malloc(sizeof(edge)); // set list
        if (newNode->edges == NULL)
        {
            printf("Unable to allocate memory to curr node %d", id);
        }
        newNode->edges->endpoint = newNode;
        newNode->edges->weight = -1;
        newNode->edges->next = NULL;
        last->next = newNode;
        c = add_edges(newNode->edges, head);
    }
    else
    {
        //after removing the edges of a an exsistent node, add the edges!
        c = add_edges(existNode->edges, head);
    }
    return c;
}
