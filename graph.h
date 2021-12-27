#ifndef GRAPH_
#define GRAPH_

typedef struct GRAPH_NODE_ *pnode;;

typedef struct edge_ {
    int weight;
    pnode endpoint; // next id point
    struct edge_ *next;
} edge, *pedge;


typedef struct GRAPH_NODE_ {
    int id;
    pedge edges; // list of edges for node
    struct GRAPH_NODE_ *next;
} node, *pnode;

void build_graph_cmd(pnode *head);
void insert_node_cmd(pnode *head);
void delete_node_cmd(pnode *head);
void printGraph_cmd(pnode head); //for self debug
void deleteGraph_cmd(pnode* head);
void shortsPath_cmd(pnode head);
void TSP_cmd(pnode head);

#endif
 /*
  *     while (x != 'D')
    {
        scanf("%c", &x); //insert a wanted function to implement.
        if (x == 'A')
        { //generate graph
            build_graph_cmd(nodes);
        }
        if (x == 'B')
        { // finds if there's a route between i,j
            scanf("%d", &i);
            scanf("%d", &j);
            exists = route_exists(i, j); // checks if there's a route.
            if (exists == 1)
            {
                printf("True\n");
            }
            else
            {
                printf("False\n");
            }
        }
        if (x == 'C')
        { // finds the closest route between i,j
            scanf("%d", &i);
            scanf("%d", &j);
            shortest_route(i, j);
            printf("\n");
        }
    }
    */ 
   