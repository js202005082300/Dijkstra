#include <stdio.h>
#include "dijkstra.h"
#include "constant.h"

int main() {
    // const int V = 5;
    Graph *g = new_graph(NUM_VERTICES, true); // Orienté
    add_edge(g, 0, 1, 10);
    add_edge(g, 1, 2, 2);
    add_edge(g, 2, 3, 9);
    add_edge(g, 3, 4, 4);
    add_edge(g, 0, 2, 5);
    add_edge(g, 1, 3, 1);
    add_edge(g, 2, 1, 3);
    add_edge(g, 2, 4, 2);
    add_edge(g, 4, 1, 2);
    add_edge(g, 4, 3, 6);

    printf("Dijkstra avec structure Graph :\n");
    print_graph(g);
    display_graph(g);

    printf("\nPlus courts chemins depuis le sommet source :\n");
    dijkstra_simple(g, 0);  // Dijkstra sans min-heap
    dijkstra_optimized(g, 0);  // Dijkstra avec min-heap

    // Libérer la mémoire
    free_graph(g);

    return 0;
}