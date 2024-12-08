# Algo de Dijkstra

Calcul les plus courts chemins dans un graphe.

Publié en 1959 par l'informaticien Edsger Dijkstra.

<!-- !!! une file de priorité (souvent implémentée avec un tas). -->
```C
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 9 // Nombre de sommets dans le graphe

// Fonction principale
void Dijkstra(int G[V][V], int Poids[V][V], int sdeb) {
    int d[V];
    int predecesseur[V];
    bool sptSet[V];
    // Initialisation
    for(int i=0; i<V; i++)
        d[i] = INT_MAX, sptSet[i] = false;
    d[sdeb] = 0;
    int Q[V];
    for (int i = 0; i < V; i++)
        Q[i] = 1;
    //

    while (true) {
        int mini = INT_MAX;
        int s1 = -1;
        for(int v = 0; v < V; v++)
            if(Q[v] && d[v] < mini) {
                mini = d[v];
                s1 = v;
            }
        if (s1 == -1) break;
        Q[s1] = 0;
        sptSet[s1] = true;

        for (int s2 = 0; s2 < V; s2++) {
            if (G[s1][s2] && !sptSet[s2])
                // Mise à jour des distances
                if(d[s2]>d[s1]+Poids[s1][s2]) {
                    d[s2]=d[s1]+Poids[s1][s2];
                    predecesseur[s2]=s1;
                }
                //
        }
    }

    printf("Le plus court chemin du sommet %d à tous les autres sommets:\n", sdeb);
    for (int i = 0; i < V; i++)
        printf("%d -> %d \t Distance: %d\n", sdeb, i, d[i]);
}

int main() {
    // Représenter les résultats dans un tableau.
    int G[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                   {4, 0, 8, 0, 0, 0, 0, 11, 0},
                   {0, 8, 0, 7, 0, 4, 0, 0, 2},
                   {0, 0, 7, 0, 9, 14, 0, 0, 0},
                   {0, 0, 0, 9, 0, 10, 0, 0, 0},
                   {0, 0, 4, 14, 10, 0, 2, 0, 0},
                   {0, 0, 0, 0, 0, 2, 0, 1, 6},
                   {8, 11, 0, 0, 0, 0, 1, 0, 7},
                   {0, 0, 2, 0, 0, 0, 6, 7, 0}};
    
    Dijkstra(G, G, 0);

    return 0;
}
```

# Problème de plus court chemin (pcc)

## Test symboles mathématique en .md

$a+b=c$

$$
f(x) = \int_{-\infty}^\infty \hat f(\xi)\,e^{2 \pi \xi x} \,d\xi
$$

## Bibliothèques nécessaires

### Graphviz
- **Version** : `Graphviz-12.2.0-win32`
- **Téléchargement** : [Graphviz Downloads](https://graphviz.org/)
- **Fichiers dynamiques** : Ajoutez les fichiers dans le dossier `bin`

### SDL
- **Téléchargement** : [SDL Downloads](https://www.libsdl.org/download-2.0.php)
- **Fichiers dynamiques** : Ajoutez les fichiers dans le dossier `bin`