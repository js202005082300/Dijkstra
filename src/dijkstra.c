#include "dijkstra.h"

/**
 * Trouve l'indice du sommet ayant la distance minimale parmi ceux qui ne sont pas encore traités.
 * @param dist Tableau des distances actuelles.
 * @param sptSet Tableau booléen indiquant si un sommet est traité.
 * @param V Nombre de sommets dans le graphe.
 * @return L'indice du sommet avec la distance minimale, ou -1 si aucun n'est trouvé.
 */
int findMinDistanceIndex(int dist[], Boolean sptSet[], int V) {
    int min_dist = INT_MAX; // Initialisation de la valeur minimale à une valeur très élevée (infinie).
    int minIndex = -1;      // Initialisation de l'indice du sommet minimum à -1 pour signaler une erreur si aucun n'est trouvé.

    // Parcours non récursif pour trouver le sommet de distance minimale
    for (int v = 0; v < V; v++) {  // Boucle qui parcourt tous les sommets du graphe
        if (!sptSet[v] && dist[v] <= min_dist) {  // Si le sommet v n'est pas traité et sa distance est inférieure ou égale à min_dist
            min_dist = dist[v];  // Mise à jour de la nouvelle distance minimale.
            minIndex = v;        // Mise à jour de l'indice du sommet ayant la nouvelle distance minimale.
        }
    }

    return minIndex;  // Retourner l'indice du sommet ayant la distance minimale (ou -1 si aucun sommet valide n'a été trouvé).
}

/**
 * Fonction récursive pour trouver l'indice du sommet avec la plus petite distance parmi ceux qui ne sont pas encore traités.
 * @param dist Tableau des distances actuelles.
 * @param sptSet Tableau booléen indiquant si un sommet est traité.
 * @param V Nombre total de sommets dans le graphe.
 * @param i Indice du sommet actuel lors du parcours récursif.
 * @param minIndex Indice du sommet ayant la distance minimale trouvée jusqu'à présent.
 * @param minVal Valeur de la distance minimale trouvée jusqu'à présent.
 * @return L'indice du sommet ayant la distance minimale, ou -1 si aucun n'est trouvé.
 */
int recursiveMinDistance(int dist[], Boolean sptSet[], int V, int i, int minIndex, int minVal) {
    if (i == V)  // Cas de base : si l'indice i atteint la fin du tableau (tous les sommets ont été parcourus).
        return minIndex;  // Retourner l'indice du sommet ayant la distance minimale trouvée.

    // Si le sommet i n'est pas encore traité et que sa distance est inférieure à la distance minimale actuelle.
    if (!sptSet[i] && dist[i] < minVal) {
        minVal = dist[i];  // Mettre à jour la distance minimale avec la distance du sommet i.
        minIndex = i;      // Mettre à jour l'indice du sommet avec la nouvelle distance minimale.
    }

    // Appel récursif pour le sommet suivant avec l'indice `i + 1`.
    return recursiveMinDistance(dist, sptSet, V, i + 1, minIndex, minVal);
}

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
        // int u = findMinDistanceIndex(dist, sptSet, V);
        // int u = recursiveMinDistance(dist, sptSet, V, 0, -1, INT_MAX);

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
