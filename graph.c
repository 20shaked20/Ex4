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
    // printf("Creating nodes... \n");
    for (i = 0; i < node_size; ++i)
    {
        head[i].id = i;
        head[i].edges = (pedge)malloc(sizeof(edge)); // set list
        if(head[i].edges == NULL){
            printf("Unable to allocate memory to curr node: %d",i);
        }
        head[i].edges->endpoint = &head[i];          // points on it self for startes
        head[i].edges->weight = -1;                  // starting weight equal -1
        head[i].edges->next = NULL;
        head[i].next = NULL;
        // printf("NODE : %d \n",i);
        
    }
    // now to create the edges of each node above.
    // now to get 'n'
    // printf("INSERT n\n");
    getchar(); // fixing the scanf with %c problem occurs while trying to scanf the computer thinkings i enterd a blank space.
    scanf("%c", &c);
    // printf("YOU CHOSE: %c",c);
    while (c == 'n')
    {
        // printf("Insert node id: .. \n");                         
        scanf("%d", &id);               // gets the id of node we operates
        c = add_edges(head[id].edges, head); // adds the edges, and returns the next n from the edges if one exists.
        
       
    }
    return c;
}

void printGraph_cmd(pnode head)
{

    for (int i = 0; i < node_size; ++i)
    {
        printf("node number: %d \n", head[i].id);
        pedge curr_edge = head[i].edges;
        while (curr_edge != NULL)
        {
            if (curr_edge->weight != -1)
            {
                printf("src: %d dest: %d weight: %d\n", head[i].id, curr_edge->endpoint->id, curr_edge->weight);
            }
            curr_edge = curr_edge->next;
        }
    }
}

int main()
{

    char c;
    struct GRAPH_NODE_ *head;
    while (TRUE)
    {
        scanf("%c", &c); // what to choose as a char.
        if (c == 'A')    // A case, loading a graph.
        {
            scanf("%d", &node_size); // how many nodes to generate, it will always come after this case.
            head = (struct GRAPH_NODE_ *)malloc(node_size * sizeof(struct GRAPH_NODE_));
            if (head == NULL)
            {
                printf("Unable to allocate memory to head");
                exit(0);
            }
            c = build_graph_cmd(head); // builds a graph of N nodes & all its edges.
            
        }
        if (c == 'P'){ // printing for self test.
            printGraph_cmd(head);  
        }
        if (c == 'E'){ // exit state.
            break; 
        }
        if(c == 'B'){
            while(c == 'B'){
                c = add_node(head);
            }
        }
    }
    
}
