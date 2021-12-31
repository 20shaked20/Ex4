#include <stdio.h>
#include <stdlib.h>
#include "graph.h"


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
    head->cost = INF;      // dijkstra
    head->visited = FALSE; // dijkstra
    head->edges = NULL;
    head->edges = (pedge)malloc(sizeof(edge)); // set list
    if (head->edges == NULL)
    {
        printf("Unable to allocate memory to curr node: %d", i);
    }
    head->edges->endpoint = head;
    head->edges->weight = 0; // zero = no edge. (other wise dijkstra will be messed up)
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
        newNode->edges->weight = 0; // zero = no edge (other wise dijkstra is messed up)
        newNode->edges->next = NULL;
        newNode->cost = INF;      //dijkstra
        newNode->visited = FALSE; // dijksrta
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
        printf("-------node number: %d -------\n", tmp->id);
        pedge curr_edge = tmp->edges;
        while (curr_edge != NULL)
        {
            if (curr_edge->weight != 0)
            {
                printf("src: %d dest: %d weight: %d\n", tmp->id, curr_edge->endpoint->id, curr_edge->weight);
            }
            curr_edge = curr_edge->next;
        }
        tmp = tmp->next;
    }
}



void dijkstra(pnode head, int src, int dest)
{
    pnode pp, set_src;
    int visitednum = 0; // checker if visited all nodes
    set_src = head;
    while (set_src->id != src)
    {
        set_src = set_src->next;
    }
    set_src->cost = 0; // set src value to 0, because we want to start from it and increase while checking the other nodes.
    while (TRUE)
    {
        int min = INF;
        /*
         targetnode : Keeping node which has minimum cost
        */
        pnode targetnode = NULL;
        pp = head;
        while (pp != NULL)
        {
            if (pp->cost < min && pp->visited == FALSE)
            {
                min = pp->cost;
                targetnode = pp;
            }
            pp = pp->next;
        }

        if (targetnode == NULL)
        {
            pp = head;
            while (TRUE)
            {
                if (pp->visited == FALSE)
                {
                    targetnode = pp;
                    break;
                }
                pp = pp->next;
            }
        }

        /*
         calculate cost of each node which has in edge relaxation proccess
        */
        if (targetnode->edges != NULL)
        {

            if (targetnode->edges->endpoint->cost > targetnode->cost + targetnode->edges->weight)
            {
                targetnode->edges->endpoint->cost = targetnode->cost + targetnode->edges->weight;
            }
            /*
             If there's more than one edges connected to node.
            */
            pedge pptemp;
            pptemp = targetnode->edges->next;
            while (pptemp != NULL)
            {
                if (pptemp->endpoint->cost > targetnode->cost + pptemp->weight)
                {
                    pptemp->endpoint->cost = targetnode->cost + pptemp->weight;
                }
                pptemp = pptemp->next;
            }
        }
        /*
         change visited flag
        */
        targetnode->visited = TRUE;

        visitednum++;
        if (visitednum == node_size)
        {
            break;
        }
    }

    /*
     find distination node
    */
    pnode get_dest = head;
    int totalcost = 0;
    while (get_dest != NULL)
    {
        if (get_dest->id == dest)
        {
            totalcost = get_dest->cost;
            break;
        }
        get_dest = get_dest->next;
    }
    printf("The shortest path Total cost : %d\n", totalcost);
}

int main()
{

    char c;
    pnode *graph;
    struct GRAPH_NODE_ *head;
    graph = &head;
    scanf("%c", &c); // what to choose as a char.
    while (c != '\n')
    {
        if (c == ' ')
        {
            scanf("%c", &c);
        }
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
          printf("\nP\n");
            printGraph_cmd(head);
            scanf("%c", &c);
            printf("\n");
        }
        if (c == 'E')
        { // exit state.
            break;
        }
        if (c == 'B')
        {
            c = add_node(head);
        }
        if (c == 'D')
        {
          deleteNode(graph);
          head = *graph;
          scanf("%c",&c);
        }
        if (c == 'S')
        {
            int src, dst;
            scanf("%d", &src);
            scanf("%d", &dst);
            dijkstra(head, src, dst);
            scanf("%c", &c);
        }
    }
}
