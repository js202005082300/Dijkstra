#include "min_heap.h"

// Crée un nouveau nœud de min-heap avec le sommet v et sa distance dist
MinHeapNode* newMinHeapNode(int v, int dist) {
    MinHeapNode* minHeapNode = malloc(sizeof(*minHeapNode)); // Cast implicite à partir de la variable
    // MinHeapNode* minHeapNode = (MinHeapNode*)malloc(sizeof(MinHeapNode)); // Cast explicite du type
    checkAllocation(minHeapNode);
    minHeapNode->v = v;
    minHeapNode->dist = dist;
    return minHeapNode;
}

// Crée une min-heap avec une capacité donnée
MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = malloc(sizeof(*minHeap));
    checkAllocation(minHeap);
    minHeap->pos = (int *)malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (MinHeapNode**)malloc(capacity * sizeof(MinHeapNode*));
    return minHeap;
}

// Échange deux noeuds de la min-heap
void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b) {
    MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// Min-heapify à l'index donné
// Maintient la propriété de la min-heap en organisant les noeuds
void minHeapify(MinHeap* minHeap, int idx) {
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

        // Mise à jour des positions
        minHeap->pos[smallestNode->v] = idx;
        minHeap->pos[idxNode->v] = smallest;

        // Échange des nœuds
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);

        minHeapify(minHeap, smallest);
    }
}

// Fonction pour vérifier si la min-heap est vide
bool isEmpty(MinHeap* minHeap) {
    return minHeap->size == 0;
}

// Extrait le nœud avec la distance minimale (= le sommet de la min-heap)
MinHeapNode* extractMin(MinHeap* minHeap) {
    if (isEmpty(minHeap))
        return NULL;

    MinHeapNode* root = minHeap->array[0];
    MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;

    // Mise à jour des positions
    minHeap->pos[root->v] = minHeap->size - 1;
    minHeap->pos[lastNode->v] = 0;

    // Réduction de la taille de la min-heap et appel de minHeapify
    --minHeap->size;
    minHeapify(minHeap, 0);

    return root;
}

// Diminue la valeur de la distance d'un sommet donné dans la min-heap
void decreaseKey(MinHeap* minHeap, int v, int dist) {
    int i = minHeap->pos[v];
    minHeap->array[i]->dist = dist;

    // Remonter le nœud dans la heap jusqu'à ce que l'arbre soit rééquilibré
    while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist) {
        minHeap->pos[minHeap->array[i]->v] = (i - 1) / 2;
        minHeap->pos[minHeap->array[(i - 1) / 2]->v] = i;
        swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Vérifie si un sommet donné est dans la min-heap
bool isInMinHeap(MinHeap *minHeap, int v) {
    return minHeap->pos[v] < minHeap->size;
}