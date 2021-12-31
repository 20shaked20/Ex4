#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

char add_node(pnode head)
{
    int id = 0;
    int exist = -1;
    char c;
    printf("ADDING NODE");
    getchar();
    scanf("%d", &id); // gets the id of node we operates
    printf("%d : \n", id);
    //checking if the node exists, if so, we'll have to remove the edges of it, other wise just add it.
    pnode existNode = head;
    while (existNode != NULL)
    {
        if (existNode->id == id)
        { // if the node does exsits, we'll remove its edges.
            printf("NODE exists \n");
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
        newNode->cost = INF; // dijkstra
        newNode->visited = FALSE; // dijkstra
        newNode->edges = NULL;
        newNode->edges = (pedge)malloc(sizeof(edge)); // set list
        if (newNode->edges == NULL)
        {
            printf("Unable to allocate memory to curr node %d", id);
        }
        newNode->edges->endpoint = newNode;
        newNode->edges->weight = 0;
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

void checkEdges(pedge *edge, int toRemov){
  pedge prev, temp;
  pedge currEdge = *edge;
  while (currEdge != NULL){
    if (currEdge->endpoint != NULL){
      if (currEdge->endpoint->id == toRemov){
        if (currEdge == *edge){
          temp = (*edge)->next;
          free(*edge);
          *edge = temp;
        }
        else{
          prev->next = currEdge->next;
          free(currEdge);
          currEdge = prev;
        }
      }
    }
    prev = currEdge;
    currEdge = currEdge->next;
  }
}

void deleteNode(pnode *graph){
  //TODO: add the case if the node is the HEAD
  pnode head = *graph;
  char c;
  scanf(" %c",&c);
  int toRemov = c - '0';
  pnode prev;
  pnode node;
  node = *graph;
  while (node != NULL){
    checkEdges(&(node->edges), toRemov);
    node = node->next;
  }
  if (head->id == toRemov){
    // I fucked bacuse shaked fuked me
    *graph = head->next;
    remove_edges(head->edges);
    free(head->edges);//because remove_edges doesnt free() the the first edge
    free(head);
  }
  else{
    node = head;
    while(node != NULL && node->id != toRemov){
      prev = node;
      node = node->next;
    }
    if (node == NULL) return;//the node is not in the graph

    remove_edges(node->edges);
    free(node->edges);//because remove_edges doesnt free() the the first edge
    prev->next = node->next;
    free(node);
  }
}
