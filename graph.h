// graph.h
#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <stdio.h>
#include <stdlib.h>
#include "util.h"

typedef struct AdjListNode {
    int dest;
    int weight;
    struct AdjListNode* next;
} AdjListNode;

typedef struct AdjList {
    AdjListNode* head;
} AdjList;

typedef struct Graph {
    int V;
    AdjList* array;
} Graph;

AdjListNode* newAdjListNode(int dest, int weight);
Graph* createGraph(int V);
void addEdge(Graph* graph, int src, int dest, int weight);
void dijkstra(Graph* graph, int src);
void printArr(int dist[], int n);

#endif // GRAPH_H