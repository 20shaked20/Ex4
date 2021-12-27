#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

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



void insert_node_cmd(pnode *head);
void delete_node_cmd(pnode *head);


void insert_node_cmd(pnode *head){
    node *src; // traversal node.
    src = head;
    int dest = 0;
    char ch = "";
    int node_id = 0;
    int weight = 0;

    scanf("%c",&ch); // getting the n (to operate on new node.)
    scanf("%d", &node_id); // get the node id.

    while(src->id!=node_id){ // getting the src node we operate on to add edge to.
        src = src->next;  
    }

    scanf("%d",&dest);
    scanf("%d",&weight);
    node *end_point;
    end_point = head;
    while(end_point->id!=dest){ // getting the dest node.
        end_point = end_point->next;  
    }
    insert_edge_cmd(src,end_point,weight); // connect the edge to the node.
}