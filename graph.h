#ifndef GRAPH_
#define GRAPH_

#define TRUE 1
#define FALSE 0
#define INF 9999

typedef struct GRAPH_NODE_ *pnode;

typedef struct edge_ {
    int weight;
    pnode endpoint; // next id point
    struct edge_ *next;
} edge, *pedge;


typedef struct GRAPH_NODE_ {
    int id;
    int visited; // for dijkstra
    int cost; // for dijkstra 
    pedge edges; // list of edges for node
    struct GRAPH_NODE_ *next;
} node, *pnode;

char build_graph_cmd(pnode head);
char add_edges(pedge edges,pnode head);
char add_node(pnode head);
void remove_edges(pedge edges);
void dijkstra(pnode head, int src, int dest);
void printGraph_cmd(pnode head); //for self debug

#endif
