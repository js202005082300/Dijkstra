#ifndef __MIN_HEAP_H__ // éviter plusieurs inclusions, les boucles infinies
#define __MIN_HEAP_H__

#include <stdio.h>
#include <stdlib.h>
#include "util.h"

typedef enum { false, true } bool;

/* Structure d'un noeud de la min-heap */
typedef struct MinHeapNode {
    int v; // Numéro du sommet
    int dist; // Distance minimale de la source
} MinHeapNode;

/* Structure d'un Tas de la min-heap */
typedef struct MinHeap {
    int size;        // Taille actuelle de la min-heap
    int capacity;    // Capacité totale de la min-heap
    int *pos;        // Position de chaque sommet dans la heap
    MinHeapNode **array; // Tableau de pointeurs vers les nœuds de la min-heap
} MinHeap;

// Prototypes de fonctions pour manipuler la min-heap
MinHeapNode* newMinHeapNode(int v, int dist); // Ici le pointeur est affiché.
MinHeap* createMinHeap(int capacity);
void swapMinHeapNode(MinHeapNode **a, MinHeapNode **b);
void minHeapify(MinHeap *minHeap, int idx);
bool isEmpty(MinHeap *minHeap);
MinHeapNode* extractMin(MinHeap *minHeap);
void decreaseKey(MinHeap *minHeap, int v, int dist);
bool isInMinHeap(MinHeap *minHeap, int v);

#endif // MIN_HEAP_H
