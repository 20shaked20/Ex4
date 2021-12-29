#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

char add_node(pnode head)
{
    int id = 0;
    int tmp_id = -1;
    char c;
    int node_size = 0;
    printf("ADDING NODE \n");
    getchar();
    scanf("%d", &id); // gets the id of node we operates
    printf("%d : \n",id);
    //checking if the node exists, if so, we'll have to remove the edges of it, other wise just add it.
    printf("CURR: %d ",head->id);
    printf("NEXT: %d ",head->next->id);
    pnode traverse = head;
    while (traverse->next!= NULL)
    {
        // printf("ID: %d ",traverse->id);
        if (traverse->id == id)
        { // if the node does exsits, we'll remove its edges.
            printf("NODE exists ");
            remove_edges(head[id].edges);
            tmp_id = id;
        }
        // printf("NEXT: %d \n", traverse->id);
        traverse = traverse->next;
        ++node_size;
    }
    printf("NODE SIZE: %d \n",node_size);
    if (tmp_id == -1)
    { // if the node does not exist, simply add it.
        head = (node *)realloc(head, node_size * sizeof(node));
        head[node_size - 1].id = id;
        head[node_size - 1].edges = NULL;
        head[node_size - 1].edges = (pedge)malloc(sizeof(edge));
        head[node_size - 1].edges->endpoint = &head[node_size - 1];
        head[node_size - 1].edges->weight = -1;
        head[node_size - 1].edges->next = NULL;
    }
    //after adding the new node/ removing the edges of a an exsistent node, add the edges!
    c = add_edges(head[id].edges, head); // adds the edges to an exsistent node.
    return c;
}
