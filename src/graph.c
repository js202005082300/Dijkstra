#include "graph.h"

/* Crée un graphe d'un nombre de sommets */
Graph* new_graph(int nb_vertices, Boolean is_oriented) {
    Graph* g = malloc(sizeof(*g)); // Cast implicite à partir de la variable
    check_allocation(g);
    g->is_oriented = is_oriented;
    g->nb_vertices = nb_vertices;
    g->array = malloc(nb_vertices * sizeof(*g->array));
    check_allocation(g->array);
    for (int i = 0; i < nb_vertices; i++)
        g->array[i].head = NULL;

    /*--------- Graphviz ----------*/
    g->graph = agopen("my_graph", g->is_oriented ? AGDIGRAPH : AGRAPH, NULL); check_allocation(g->graph);
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
    newNode->next = g->array[src].head;
    g->array[src].head = newNode;

    // Si le graphe n'est pas orienté, ajoute l'arête dans l'autre sens
    if (!g->is_oriented) {
        newNode = add_node(src, weight);
        newNode->next = g->array[dest].head;
        g->array[dest].head = newNode;
    }

    /*--------- Graphviz ----------*/
    Agnode_t *src_node = agnode(g->graph, src, TRUE);
    Agnode_t *dest_node = agnode(g->graph, dest, TRUE);
    agedge(g->graph, src_node, dest_node, NULL, TRUE);
    /*-----------------------------*/
}

void print_graph(Graph *g) {
    for(int i = 0; i < g->nb_vertices; i++) {
        NodeList* current = g->array[i].head;
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
    GVC_t *gvc = gvContext();
    agwrite(g->graph, stdout); // Écrit le graphe dans stdout pour le débogage
    gvLayout(gvc, g->graph, "dot"); gvRender(gvc, g->graph, "png", fopen("graph.png", "w"));
    gvFreeLayout(gvc, g->graph);
    gvFreeContext(gvc); // Ajout de la commande pour ouvrir l'image générée selon le système d'exploitation
    #ifdef _WIN32
        system("start graph.png");
    #elif __APPLE__
        system("open graph.png");
    #else
        system("xdg-open graph.png");
    #endif
}

/* Libère la mémoire allouée pour le graphe */
void free_graph(Graph *g) {
    if(is_empty_graph(g))
        return;
    
    if(g->array) {
        for (int i = 0; i < g->nb_vertices; i++) {
            NodeList* current = g->array[i].head;
            while (current != NULL) {
                NodeList* temp = current;
                current = current->next;
                free(temp);
            }
        }
        // Libération de la liste d'adjacence
        free(g->array);
    }

    /*--------- Graphviz ----------*/
    agclose(g->graph);
    /*-----------------------------*/

    // Libération du Graphe
    free(g);
}