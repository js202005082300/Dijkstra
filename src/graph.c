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
        g->graph_file = fopen("graphs/digraph.dot", "w");
    else
        g->graph_file = fopen("graphs/graph.dot", "w"); 
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
    char s = src + 'a';
    char d = dest + 'a';
    if(g->is_oriented)
        fprintf(g->graph_file, "\t%c -> %c [label=\"%d\"];\n", s, d, weight);
    else
        fprintf(g->graph_file, "\t%c -- %c [label=\"%d\"];\n", s, d, weight);

    /*-----------------------------*/
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

    /*-------------------------------*/
    /*-------- Display Graph --------*/
    /*-------------------------------*/

void print_graph(Graph *g) {
    for (int i = 0; i < g->nb_vertices; i++) {
        char v = i + 'a';
        NodeList* current = g->tab_neighbours[i].head;
        printf("(%c) : ", v);
        while (current != NULL) {
            printf("-> (%d, %d) ", current->dest, current->weight);
            current = current->next;
        }
        printf("NULL\n");
    }
}

void display_graph(Graph *g) {
    //Windows seulement !
    if(g->is_oriented)
        system("dot.exe digraph.dot");
    else
        system("dot.exe graph.dot");
}

void print_shortest_paths(Graph *g, int dist[], int pred[]) {
    printf("Sommet   Distance   Prédécesseur\n");
    for (int i = 0; i < g->nb_vertices; i++) {
        char v = i + 'a';
        char p = pred[i] != -1 ? pred[i] + 'a' : '-';
        printf("(%c)     %d         %c\n", v, dist[i], p);
    }
}

void display_graph_state(Graph *g, int iteration, bool sptSet[]) {
    char filename[50];
    sprintf(filename, "graphs/graph_state_%d.dot", iteration);
    FILE *graph_file = fopen(filename, "w");

    if (graph_file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    if (g->is_oriented)
        fprintf(graph_file, "digraph G {\n");
    else
        fprintf(graph_file, "graph G {\n");

    for (int i = 0; i < g->nb_vertices; i++) {
        NodeList* current = g->tab_neighbours[i].head;
        while (current != NULL) {
            char s = i + 'a';
            char d = current->dest + 'a';
            if (sptSet[i] && sptSet[current->dest]) {
                if (g->is_oriented)
                    fprintf(graph_file, "\t%c -> %c [label=\"%d\", color=\"red\"];\n", s, d, current->weight);
                else
                    fprintf(graph_file, "\t%c -- %c [label=\"%d\", color=\"red\"];\n", s, d, current->weight);
            } else {
                if (g->is_oriented)
                    fprintf(graph_file, "\t%c -> %c [label=\"%d\"];\n", s, d, current->weight);
                else
                    fprintf(graph_file, "\t%c -- %c [label=\"%d\"];\n", s, d, current->weight);
            }
            current = current->next;
        }
    }
    fprintf(graph_file, "}\n");
    fclose(graph_file);

    char cmd[100];
    sprintf(cmd, "dot -Tpng graphs/graph_state_%d.dot -o graphs/graph_state_%d.png", iteration, iteration);
    system(cmd);
}