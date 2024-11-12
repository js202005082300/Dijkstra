#include "dijkstra.h"

// Trouver le sommet avec la valeur de distance minimum
int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < NUM_VERTICES; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Implémentation de l'algorithme de Dijkstra pour une matrice d'adjacence
void dijkstraAdjMatrix(int graph[NUM_VERTICES][NUM_VERTICES], int src) {
    int dist[NUM_VERTICES]; // Le tableau des distances, dist[i] contiendra la distance la plus courte de src à i
    bool sptSet[NUM_VERTICES]; // sptSet[i] sera vrai si le sommet i est inclus dans l'arbre des chemins les plus courts

    // Initialiser toutes les distances comme infinies et sptSet[] comme faux
    for (int i = 0; i < NUM_VERTICES; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    // La distance du sommet source à lui-même est toujours 0
    dist[src] = 0;

    // Trouver le chemin le plus court pour tous les sommets
    for (int count = 0; count < NUM_VERTICES - 1; count++) {
        int u = minDistance(dist, sptSet); // Prendre le sommet avec la distance minimale
        sptSet[u] = true; // Marquer le sommet choisi comme traité

        for (int v = 0; v < NUM_VERTICES; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // Imprimer le tableau des distances
    printArr(dist, NUM_VERTICES);
}

// Implémentation de l'Algorithme Dijkstra
void dijkstra(Graph* graph, int src) {
    int V = graph->V;
    int dist[V];
    MinHeap* minHeap = createMinHeap(V);

    for (int v = 0; v < V; ++v) {
        dist[v] = INT_MAX;
        minHeap->array[v] = newMinHeapNode(v, dist[v]);
        minHeap->pos[v] = v;
    }

    minHeap->array[src] = newMinHeapNode(src, dist[src]);
    minHeap->pos[src] = src;
    dist[src] = 0;
    decreaseKey(minHeap, src, dist[src]);
    minHeap->size = V;

    while (!isEmpty(minHeap)) {
        MinHeapNode* minHeapNode = extractMin(minHeap);
        int u = minHeapNode->v;

        AdjListNode* pCrawl = graph->array[u].head;
        while (pCrawl != NULL) {
            int v = pCrawl->dest;
            if (isInMinHeap(minHeap, v) && dist[u] != INT_MAX && pCrawl->weight + dist[u] < dist[v]) {
                dist[v] = dist[u] + pCrawl->weight;
                decreaseKey(minHeap, v, dist[v]);
            }
            pCrawl = pCrawl->next;
        }
    }

    printArr(dist, V);
}

// Affiche le tableau des distances calculées par l'algorithme de Dijkstra
void printArr(int dist[], int n) {
    printf("Sommet   Distance depuis la source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}