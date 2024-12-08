#include "min_heap.h"

/* Crée un nouveau nœud de la min-heap */
MinHeapNode *new_heap_node(int v, int dist) {
    MinHeapNode *hnd = malloc(sizeof(*hnd)); // Cast implicite à partir de la variable
    check_allocation(hnd);
    hnd->v = v;
    hnd->dist = dist;
    return hnd;
}

/* Crée une min-heap */
MinHeap *create_min_heap(int capacity) {
    MinHeap *mh = malloc(sizeof(*mh));
    check_allocation(mh);

    mh->array = malloc(capacity * sizeof(*mh->array)); // Allocation de mémoire pour un tableau de pointeurs vers MinHeapNode, de taille 'capacity'
    check_allocation(mh->array);

    mh->pos = malloc(capacity * sizeof(*mh->pos)); 
    check_allocation(mh->pos);

    mh->size = 0;
    mh->capacity = capacity;
    return mh;
}

/* Échange deux nœuds de la min-heap */
void swap_min_heap_node(MinHeapNode **a, MinHeapNode **b) {
    MinHeapNode *tmp = *a;
    *a = *b;
    *b = tmp;
}

/* Maintient la propriété de la min-heap en organisant les noeuds */
void min_heapify(MinHeap *minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    // Vérifier si l'enfant gauche existe et est plus petit que le nœud actuel le plus petit
    if (left < minHeap->size && minHeap->array[left]->dist < minHeap->array[smallest]->dist)
        smallest = left;
    
    // Vérifier si l'enfant droit existe et est plus petit que le nœud actuel le plus petit
    if (right < minHeap->size && minHeap->array[right]->dist < minHeap->array[smallest]->dist)
        smallest = right;

    // Si le nœud le plus petit n'est pas le nœud actuel, échanger et continuer l'heapification
    if (smallest != idx) {
        MinHeapNode *smallestNode = minHeap->array[smallest];
        MinHeapNode *idxNode = minHeap->array[idx];
        minHeap->pos[smallestNode->v] = idx;    // Mise à jour des positions
        minHeap->pos[idxNode->v] = smallest;    // Mise à jour des positions
        swap_min_heap_node(&minHeap->array[smallest], &minHeap->array[idx]); // Échange des nœuds
        min_heapify(minHeap, smallest);
    }
}

/* Vérifie si la min-heap est vide */
Boolean is_empty_min_heap(MinHeap *minHeap) {
    return minHeap->size == 0;
}

/* Extrait le nœud avec la distance minimale (= le sommet de la min-heap) */
MinHeapNode *extract_min(MinHeap *minHeap) {
    if (is_empty_min_heap(minHeap))
        return NULL;

    MinHeapNode *root = minHeap->array[0];
    MinHeapNode *lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;
    minHeap->pos[root->v] = minHeap->size - 1;  // Mise à jour des positions
    minHeap->pos[lastNode->v] = 0;              // Mise à jour des positions
    --minHeap->size;    // Réduction de la taille de la min-heap et appel de minHeapify
    min_heapify(minHeap, 0);

    return root;
}

/* Diminue la clé d'un nœud de la min-heap */
void decrease_key(MinHeap *minHeap, int v, int dist) {
    int i = minHeap->pos[v];        // Trouve l'index du nœud à diminuer dans la min-heap
    minHeap->array[i]->dist = dist; // Màj dist du nœud à la nouvelle valeur
    // Remonter le nœud dans la heap jusqu'à ce que l'arbre soit rééquilibré
    while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist) {
        minHeap->pos[minHeap->array[i]->v] = (i - 1) / 2;   // Màj positions des nœuds dans le tableau pos
        minHeap->pos[minHeap->array[(i - 1) / 2]->v] = i;   // Màj positions des nœuds dans le tableau pos
        swap_min_heap_node(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);  // Échange les positions des nœuds dans le tableau array
        i = (i - 1) / 2;    // Déplace l'index vers le parent
    }
}

// Vérifie si un sommet donné est dans la min-heap
Boolean is_in_min_heap(MinHeap *minHeap, int v) {
    return minHeap->pos[v] < minHeap->size;
}
