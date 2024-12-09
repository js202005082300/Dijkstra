#include <stdio.h>
#include "dijkstra.h"
#include "constant.h"

// https://www.geeksforgeeks.org/c-program-for-dijkstras-shortest-path-algorithm-greedy-algo-7/

Graph *convert_matrix_to_graph(int graphMatrix[NUM_VERTICES][NUM_VERTICES], int num_vertices);

// Fonction principale pour tester l'algorithme Dijkstra
int main() {
    // // Définir la matrice d'adjacence
    // int graphMatrix[NUM_VERTICES][NUM_VERTICES] = {
    //     { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
    //     { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
    //     { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
    //     { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
    //     { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
    //     { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
    //     { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
    //     { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
    //     { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
    // };

    // // Convertir la matrice d'adjacence en un graphe
    // printf("Conversion de la matrice d'adjacence en graphe...\n");
    // Graph *g = convert_matrix_to_graph(graphMatrix, NUM_VERTICES);

    // Afficher les informations sur l'utilisation de Dijkstra
    printf("Dijkstra avec structure Graph :\n");

    // Créer le graphe pour tester Dijkstra
    Graph *g1 = new_graph(NUM_VERTICES, false); // Non orienté
    add_edge(g1, 0, 1, 4);
    add_edge(g1, 0, 7, 8);
    add_edge(g1, 1, 2, 8);
    add_edge(g1, 1, 7, 11);
    add_edge(g1, 2, 3, 7);
    add_edge(g1, 2, 8, 2);
    add_edge(g1, 2, 5, 4);
    add_edge(g1, 3, 4, 9);
    add_edge(g1, 3, 5, 14);
    add_edge(g1, 4, 5, 10);
    add_edge(g1, 5, 6, 2);
    add_edge(g1, 6, 7, 1);
    add_edge(g1, 6, 8, 6);
    add_edge(g1, 7, 8, 7);

    print_graph(g1);
    display_graph(g1);

    // Exécuter les deux versions de Dijkstra
    dijkstra_simple(g1, 0);  // Dijkstra sans min-heap
    dijkstra_optimized(g1, 0);  // Dijkstra avec min-heap

    // Libérer la mémoire
    // free_graph(g);
    free_graph(g1);

    return 0;
}

/* Convertit une matrice d'adjacence en un graphe */
Graph *convert_matrix_to_graph(int graphMatrix[NUM_VERTICES][NUM_VERTICES], int num_vertices) {
    Graph *graph = new_graph(num_vertices, false);  // Non orienté
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            if (graphMatrix[i][j] != 0) {
                add_edge(graph, i, j, graphMatrix[i][j]);
            }
        }
    }
    return graph;
}