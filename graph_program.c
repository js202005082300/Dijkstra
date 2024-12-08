#include <graphviz/cgraph.h>
#include <graphviz/gvc.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    Agraph_t *g;
    Agnode_t *a, *b, *c;
    Agedge_t *e1, *e2, *e3;
    GVC_t *gvc;

    // Initialize a new graphviz context
    gvc = gvContext();

    // Create a new directed graph
    g = agopen("my_graph", Agdirected, NULL);

    // Create nodes
    a = agnode(g, "a", 1);
    b = agnode(g, "b", 1);
    c = agnode(g, "c", 1);

    // Create edges
    e1 = agedge(g, a, b, NULL, 1);
    e2 = agedge(g, a, c, NULL, 1);

    // Create edge with constraint
    e3 = agedge(g, b, c, NULL, 1);
    agset(e3, "constraint", "false");

    // Layout and render the graph to an image
    gvLayout(gvc, g, "dot");
    gvRenderFilename(gvc, g, "svg", "graph.svg");

    // Clean up
    gvFreeLayout(gvc, g);
    agclose(g);
    gvFreeContext(gvc);

    return 0;
}
