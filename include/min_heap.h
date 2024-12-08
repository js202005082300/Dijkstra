#ifndef __MIN_HEAP_H__ // éviter plusieurs inclusions, les boucles infinies
#define __MIN_HEAP_H__

#include <stdio.h>
#include <stdlib.h>
#include "util.h"

/* Définition d'un noeud */
typedef struct MinHeapNode {
    int v;      // Numéro du sommet
    int dist;   // Distance minimale de la source
} MinHeapNode, *hndP; // Définition de la structure et d'un pointeur vers la structure

/* Définition d'un Tas */
typedef struct MinHeap {
    int size;        // Taille actuelle de la min-heap
    int capacity;    // Capacité totale de la min-heap
    int *pos;        // Position de chaque sommet dans la heap
    MinHeapNode **array; // Tableau de pointeurs vers les nœuds de la min-heap
} MinHeap, *mhP;

// Prototypes de fonctions pour manipuler la min-heap
MinHeapNode *new_heap_node(int v, int dist);
MinHeap *create_min_heap(int capacity);
void swap_min_heap_node(MinHeapNode **a, MinHeapNode **b);
void min_heapify(MinHeap *minHeap, int idx);
Boolean is_empty_min_heap(MinHeap *minHeap);
MinHeapNode *extract_min(MinHeap *minHeap);
void decrease_key(MinHeap *minHeap, int v, int dist);
Boolean is_in_min_heap(MinHeap *minHeap, int v);

#endif /* __MIN_HEAP_H__ */
