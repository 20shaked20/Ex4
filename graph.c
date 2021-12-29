#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

#define TRUE 1 // for main loop to run.

int node_size; // how many nodes the graph holds. global variable.

char build_graph_cmd(pnode head)
{
    int i = 0;
    int id = 0;
    char c;
    // create n nodes. 1-2-3-4... its an adjacney list of nodes, with empty adjancney list of edges.

    //INIT HEAD:
    head->id = 0;
    head->next = (struct GRAPH_NODE_ *)malloc(sizeof(struct GRAPH_NODE_));
    head->edges = NULL;
    head->edges = (pedge)malloc(sizeof(edge)); // set list
    if (head->edges == NULL)
    {
        printf("Unable to allocate memory to curr node: %d", i);
    }
    head->edges->endpoint = head;
    head->edges->weight = -1;
    head->edges->next = NULL;
    //INIT OTHER LIST:
    pnode currNode = head;
    for (i = 1; i < node_size; ++i)
    {
        pnode newNode = (struct GRAPH_NODE_ *)malloc(sizeof(struct GRAPH_NODE_));
        newNode->id = i;
        newNode->next = NULL;
        newNode->edges = NULL;
        newNode->edges = (pedge)malloc(sizeof(edge)); // set list
        if (newNode->edges == NULL)
        {
            printf("Unable to allocate memory to curr node: %d", i);
        }
        newNode->edges->endpoint = newNode;
        newNode->edges->weight = -1;
        newNode->edges->next = NULL;
        currNode->next = newNode;
        currNode = newNode;
    }

    // now to create the edges of each node above.
    // now to get 'n'
    scanf(" %c", &c);
    while (c == 'n')
    {
        pnode tmp = head;
        scanf("%d", &id); // gets the id of node we operates
        while (tmp->id != id)
        {
            tmp = tmp->next;
        }
        c = add_edges(tmp->edges, head); // adds the edges, and returns the next n from the edges if one exists.
    }
    return c;
}

void printGraph_cmd(pnode head)
{
    pnode tmp = head;
    while (tmp != NULL)
    {
        printf("node number: %d \n", tmp->id);
        pedge curr_edge = tmp->edges;
        while (curr_edge != NULL)
        {
            if (curr_edge->weight != -1)
            {
                printf("src: %d dest: %d weight: %d\n", tmp->id, curr_edge->endpoint->id, curr_edge->weight);
            }
            curr_edge = curr_edge->next;
        }
        tmp = tmp->next;
    }
}

int main()
{

    char c;
    struct GRAPH_NODE_ *head;
    scanf("%c", &c); // what to choose as a char.
    while (c != '\n')
    {
        if (c == 'A') // A case, loading a graph.
        {
            scanf("%d", &node_size); // how many nodes to generate, it will always come after this case.
            head = (struct GRAPH_NODE_ *)malloc(node_size * sizeof(struct GRAPH_NODE_));
            if (head == NULL)
            {
                printf("Unable to allocate memory to head");
                exit(1);
            }
            c = build_graph_cmd(head); // builds a graph of N nodes & all its edges.
        }
        if (c == 'P')
        { // printing for self test.
            printGraph_cmd(head);
            scanf("%c", &c);
        }
        if (c == 'E')
        { // exit state.
            break;
        }
        if (c == 'B')
        {
            while (c == 'B')
            {
                c = add_node(head);
            }
        }
    }
}