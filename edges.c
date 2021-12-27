#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

typedef struct GRAPH_NODE_ {
    int id;
    pedge edges; // list of edges for node
    struct GRAPH_NODE_ *next;
} node, *pnode;

typedef struct edge_ {
    int weight;
    pnode endpoint; // next id point
    struct edge_ *next;
} edge, *pedge;

void insert_edge_cmd(pnode *head,pnode dest,int weight){
   edge *new_edge, *edge_tmp;
   new_edge ->endpoint = &dest;
   new_edge -> weight = weight;
   edge_tmp = (*head)->edges;
   //traverse untill u reached end of edges list.
   while(edge_tmp->next!=NULL){
       edge_tmp = edge_tmp->next;
   }
   //add the edge in the right location of the list.
   edge_tmp ->next = new_edge;
   new_edge ->next = NULL;  
}
