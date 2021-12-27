#include <stdio.h>
#include <stdlib.h>
// #include "graph.h"

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



void build_graph_cmd(pnode head);
void insert_node_cmd(pnode *head);
void delete_node_cmd(pnode *head);
void printGraph_cmd(pnode head); //for self debug
void deleteGraph_cmd(pnode* head);
void shortsPath_cmd(pnode head);
void TSP_cmd(pnode head);


void build_graph_cmd(pnode head){
    pnode new_node, *temp;
    int node_size = 0;
    int i = 0;

    scanf("%d", &node_size); // how many nodes to generate.
    head = (struct GRAPH_NODE_ *) malloc(node_size * sizeof(struct GRAPH_NODE_));
    if(head == NULL){
        printf("Unable to allocate memory to head");
        exit(0);
    }
    // create n nodes. 1-2-3-4... its an adjacney list of nodes, with empty adjancney list of edges.
    for (int i = 0; i < node_size; ++i) {
        head[i].id = i;
        head[i].edges=(pedge) malloc(sizeof(edge)); // set list 
        head[i].edges->endpoint=head[i].id;
        head[i].edges->weight=-1; // starting weight equal -1
        head[i].edges->next=NULL;
        head[i].next = NULL;
    }
    // now to create the edges of each node above.
    // insert_node_cmd(head); // inserts edges to this node
}

void printGraph_cmd(pnode head){
    pnode tmp = head;
    while(head->next!=NULL){
        printf("DATA: %d \n", head->id);
        head = head->next;
    }
}



int main(){

    char x;
    int i = 0;
    int j = 0;
    int exists = 0;
    // printf("BLA");
    struct GRAPH_NODE_ *head;
    // scanf("%c",&x);
    // if(x == 'A'){ // case A, build graph.
    // printf("BLA");
    build_graph_cmd(head);
    // }
    // printGraph_cmd(*head);
}
