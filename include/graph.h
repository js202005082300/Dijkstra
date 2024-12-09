#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <stdio.h>
#include <stdlib.h>
#include "util.h"

/* Définition d'un Noeud (sommet) */
typedef struct NodeList {
    int dest;                           // Destination du sommet
    int weight;                         // Poids de l'arête
    struct NodeList* next;              // Pointeur vers le prochain nœud
} NodeList, *ndlP;                      // Définition de la structure et d'un pointeur vers la structure

/* Définition d'une liste d'adjacence */
typedef struct AdjacencyList {
    NodeList *head;                     // Pointeur vers le premier nœud de la liste d'adjacence
} AdjacencyList, *adjlP;

/* Définition d'un graphe */
typedef struct Graph {
    Boolean is_oriented;
    int nb_vertices;                    // Nombre de sommets
    AdjacencyList *tab_neighbours;      // Tableau de listes d'adjacence
    FILE *graph_file;
} Graph, *grP;

/* Prototypes */
Graph* new_graph(int nb_vertices, Boolean is_oriented);
Boolean is_empty_graph(Graph *g);
NodeList* add_node(int dest, int weight);
void add_edge(Graph *g, int src, int dest, int weight);
void print_graph(Graph *g);
void display_graph(Graph *g);
void free_graph(Graph *g);

#endif // __GRAPH_H__
