#ifndef __DIJKSTRA_H__
#define __DIJKSTRA_H__

#include <stdio.h>
#include <limits.h>
#include "graph.h"
#include "min_heap.h"
#include "constants.h"

// Déclaration de la fonction Dijkstra
int minDistance(int dist[], bool sptSet[]);
void dijkstraAdjMatrix(int graph[NUM_VERTICES][NUM_VERTICES], int src);
void dijkstra(Graph* graph, int src);
void printArr(int dist[], int n);

#endif /* DIJKSTRA_H */
