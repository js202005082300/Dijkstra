#include "graph.h"

/* Crée un graphe d'un nombre de sommets */
Graph* new_graph(int nb_vertices, Boolean is_oriented) {
    Graph* g = malloc(sizeof(*g)); // Cast implicite à partir de la variable
    check_allocation(g);
    g->is_oriented = is_oriented;
    g->nb_vertices = nb_vertices;
    g->tab_neighbours = malloc(nb_vertices * sizeof(*g->tab_neighbours));
    check_allocation(g->tab_neighbours);
    for (int i = 0; i < nb_vertices; i++)
        g->tab_neighbours[i].head = NULL;

    /*--------- Graphviz ----------*/
    if(g->is_oriented)
        g->graph_file = fopen("graphs/digraph.out", "w");
    else
        g->graph_file = fopen("graphs/graph.out", "w"); 
    check_allocation(g->tab_neighbours);
    if(g->is_oriented)
        fprintf(g->graph_file, "digraph my_graph\n{\n");
    else
        fprintf(g->graph_file, "graph my_graph\n{\n");
    /*-----------------------------*/

    return g;
}

/* Vérifie si la min-heap est vide */
Boolean is_empty_graph(Graph *g) {
    return g == NULL;
}


// new_NodeList devient add_node

/* Crée un nouveau nœud de la liste d'adjacence */
NodeList* add_node(int dest, int weight) {
    NodeList* newNode = malloc(sizeof(*newNode));
    check_allocation(newNode);
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

/* Ajoute une arête au graphe */
void add_edge(Graph *g, int src, int dest, int weight) {
    NodeList* newNode = add_node(dest, weight);
    newNode->next = g->tab_neighbours[src].head;
    g->tab_neighbours[src].head = newNode;

    // Si le graphe n'est pas orienté, ajoute l'arête dans l'autre sens
    if (!g->is_oriented) {
        newNode = add_node(src, weight);
        newNode->next = g->tab_neighbours[dest].head;
        g->tab_neighbours[dest].head = newNode;
    }

    /*--------- Graphviz ----------*/
    if(g->is_oriented)
        fprintf(g->graph_file, "\t%d -> %d;\n", src, dest);
    else
        fprintf(g->graph_file, "\t%d -- %d;\n", src, dest);
    /*-----------------------------*/
}

void print_graph(Graph *g) {
    for(int i = 0; i < g->nb_vertices; i++) {
        NodeList* current = g->tab_neighbours[i].head;
        printf("(%d) : ", i);

        while(current != NULL) {
            printf("%d, ", current->dest);
            printf("%d, ", current->weight);
            current = current->next;
        }

        printf("NULL\n");
    }
}

void display_graph(Graph *g) {
    //Windows seulement !
    if(g->is_oriented)
        system("dot.exe digraph.out");
    else
        system("dot.exe graph.out");
}

/* Libère la mémoire allouée pour le graphe */
void free_graph(Graph *g) {
    if(is_empty_graph(g))
        return;
    
    if(g->tab_neighbours) {
        for (int i = 0; i < g->nb_vertices; i++) {
            NodeList* current = g->tab_neighbours[i].head;
            while (current != NULL) {
                NodeList* temp = current;
                current = current->next;
                free(temp);
            }
        }
        // Libération de la liste d'adjacence
        free(g->tab_neighbours);
    }

    /*--------- Graphviz ----------*/
    fprintf(g->graph_file, "}\n");// \n: convention pour le retour à la ligne fichier.
    fclose(g->graph_file);
    /*-----------------------------*/

    // Libération du Graphe
    free(g);
}