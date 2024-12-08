#ifndef __DIJKSTRA_H__
#define __DIJKSTRA_H__

#include <stdio.h>
#include <limits.h>
#include "graph.h"
#include "min_heap.h"

// Prototypes de fonctions
void dijkstra_simple(Graph *graph, int src);
void dijkstra_optimized(Graph *graph, int src);
void print_arr(int dist[], int n);

#endif /* __DIJKSTRA_H__ */
