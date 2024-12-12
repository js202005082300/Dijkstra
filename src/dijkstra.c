#include "dijkstra.h"


/**
 * Algorithme de Dijkstra sans Min-Heap.
 * @param graph Graph sous forme de liste d'adjacence.
 * @param src Sommet source pour les plus courts chemins.
 */
void dijkstra_simple(Graph *graph, int src) {
    int V = graph->nb_vertices;
    int dist[V];
    int pred[V];
    Boolean sptSet[V]; // Le tableau sptSet[i] sera vrai si le sommet i est inclus dans le plus court chemin trouvé.

    // Initialiser toutes les distances comme infinies et sptSet[] comme faux
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
        pred[i] = -1;
    }

    // La distance du sommet source à lui-même est toujours 0
    dist[src] = 0;

    // Trouver le chemin le plus court pour tous les sommets
    for (int count = 0; count < V - 1; count++) {
        // Choisir le sommet de distance minimale parmi ceux qui ne sont pas encore traités
        int u = -1;                 // Erreur si sommet non trouvé
        int min_dist = INT_MAX;     // Initialiser à la valeur maximale
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && dist[v] <= min_dist) {
                min_dist = dist[v]; // màj min_dist
                u = v;              // màj le sommet avec la distance minimale
            }
        }

        if(u == -1) break; // Si aucun sommet n'a été trouvé, sortir de la boucle
        sptSet[u] = true;  // Marquer le sommet choisi comme traité

        // Pointeur temporaire pour parcourir la liste d'adjacence des sommets adjacents au sommet choisi.
        NodeList* tmp = graph->tab_neighbours[u].head;
        while (tmp != NULL) {
            int v = tmp->dest;
            if (!sptSet[v] && dist[u] != INT_MAX && tmp->weight + dist[u] < dist[v]) {
                dist[v] = dist[u] + tmp->weight;
                pred[v] = u;
            }
            tmp = tmp->next;
        }
    }

    // Afficher les distances finales et les prédécesseurs
    print_shortest_paths(graph, dist, pred);

    // Afficher les distances
    print_arr(dist, V);
}

/**
 * Algorithme de Dijkstra avec Min-Heap.
 * @param graph Graph sous forme de liste d'adjacence.
 * @param src Sommet source pour les plus courts chemins.
 */
void dijkstra_optimized(Graph *graph, int src) {
    int V = graph->nb_vertices;
    int dist[V];
    MinHeap *minHeap = create_min_heap(V);

    for (int v = 0; v < V; ++v) {
        dist[v] = INT_MAX;
        minHeap->array[v] = new_heap_node(v, dist[v]);
        minHeap->pos[v] = v;
    }

    minHeap->array[src] = new_heap_node(src, dist[src]);
    minHeap->pos[src] = src;
    dist[src] = 0;
    decrease_key(minHeap, src, dist[src]);
    minHeap->size = V;

    while (!is_empty_min_heap(minHeap)) {
        MinHeapNode *minHeapNode = extract_min(minHeap);
        int u = minHeapNode->v;

        NodeList* tmp = graph->tab_neighbours[u].head;
        while (tmp != NULL) {
            int v = tmp->dest;
            if (is_in_min_heap(minHeap, v) && dist[u] != INT_MAX && tmp->weight + dist[u] < dist[v]) {
                dist[v] = dist[u] + tmp->weight;
                decrease_key(minHeap, v, dist[v]);
            }
            tmp = tmp->next;
        }
    }

    // Afficher les distances
    print_arr(dist, V);
}

/* Imprime les distances minimales */
void print_arr(int dist[], int n) {
    printf("Sommet   Distance depuis la source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}
