#include "graph.h"
#include <stdlib.h>

// Fonction pour créer un nouveau nœud de liste d'adjacence
AdjListNode* newAdjListNode(int dest, int weight) {
    AdjListNode* newNode = malloc(sizeof(*newNode)); // Cast implicite à partir de la variable
    checkAllocation(newNode);
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Création d'un graphe avec V sommets
Graph* createGraph(int V) {
    Graph* graph = malloc(sizeof(*graph));
    checkAllocation(graph);

    graph->V = V;
    graph->array = (AdjList*)malloc(V * sizeof(AdjList));
    checkAllocation(graph->array);

    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;
    return graph;
}

// Ajoute une arête dans le graphe
void addEdge(Graph* graph, int src, int dest, int weight) {
    AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
    newNode = newAdjListNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}