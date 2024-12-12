https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/

# Algorythme Dijkstra

> A.1 Algorithme de Dijkstra : L'algorithme de Dijkstra est utile pour trouver le chemin le moins coûteux entre deux nœuds d’un graphe pondéré. Il nécessite l'utilisation d'une structure de données efficace comme une file de priorité (souvent implémentée avec un tas). Il est important de prouver que les nœuds déjà visités ont leur plus court chemin correctement calculé.

## 1. Effectuez des recherches pour comprendre l'algorithme choisi en profondeur. Vous devrez utiliser des ressources académiques ou en ligne pour mieux comprendre son fonctionnement et les théories qui le sous-tendent. Listez vos sources, expliquez en quelques mots pourquoi vous avez le choix de cet algorithme en particulier, et donnez son contexte d’utilisation (dans quels cas concrets est-il typiquement utilisé ?). 

+ Choix de l'algorithme : Dijkstra's algorithm,
    - Algorithme de Dijkstra : Trouve le chemin le plus court dans un graphe pondéré (arêtes avec poids) à partir d'un sommet source vers tous les autres sommets (Single-source shortest path). Utilise les concepts de sommets, arêtes, poids, et chemins.
    - Graph theory : G = (V, E) : Sommets (V) et Arêtes (E) connectés.
        Graphe (G) : Ensemble de sommets (V) et arêtes (E).
        Sommets (V) : Points ou nœuds du graphe.
        Arêtes (E) : Liens entre les sommets.
        Graphe simple : Pas de boucles ni d'arêtes multiples.
        Boucle : Arête reliant un sommet à lui-même.
        Multigraphe : Contient des boucles et/ou des arêtes multiples.
        Graphe complet (Kn) : Toutes les arêtes possibles entre n sommets.
        Parcours (P) : Séquence de sommets et d'arêtes.
        Chemin : Parcours sans répétition de sommets.
        Circuit : Parcours fermé revenant au sommet initial.
        Acyclique : Pas de circuits.
        Connexe : Chemin entre chaque paire de sommets.
        Composantes connexes : Sous-graphes connexes.
        Graphe orienté (Digraphe) : Arêtes avec direction (queue vers tête).
        Matrice adjacente : Représentation matricielle des connexions.
    - Greedy algorithm : choix de la meilleure option à chaque itération (https://www.geeksforgeeks.org/greedy-algorithms/).
    - Weighted graphs
    - Priority queue
    - Heap data structure

+ Contexte d'utilisation

- **Routes fiscales** : optimiser les routes fiscales des multinationales (Delhaye, V., 2015).
- **Navigation GPS** : trouver le chemin le plus court.
- **Réseaux de télécommunications** : minimiser les délais de transmission (ex : OSPF, Open Shortest Path First).
- **Gestion du trafic** : éviter les embouteillages.

+ Cas concrets


### Sources
https://webcampus.unamur.be/pluginfile.php/50153/mod_resource/content/2/2019-2020.pdf
https://www.geeksforgeeks.org/binary-heap/
https://www.geeksforgeeks.org/heap-data-structure/
https://www.geeksforgeeks.org/dijkstras-algorithm-for-adjacency-list-representation-greedy-algo-8/
https://d-michail.github.io/assets/teaching/data-structures/033_BinaryHeapImplementation.en.pdf

[Blondel, 2014] Blondel, V. (2014). Mathématiques discrètes 1 : Théorie et algorithmique des graphes. Technical report, UCL/EPL. Cours LINMA1691.

https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
https://www.geeksforgeeks.org/introduction-to-dijkstras-shortest-path-algorithm/?ref=header_outind
https://www.geeksforgeeks.org/greedy-algorithms/
https://ils.bib.uclouvain.be/unamur
https://www.unamur.be/fr/bump/bookalibrarian
https://fr.piliapp.com/symbol/math/


Szczesniak, I., & Woźna-Szcześniak, B. (n.d.). *Generic Dijkstra: correctness and tractability*. Czestochowa University of Technology, Department of Computer Science & Jan Długosz University in Czestochowa, Department of Mathematics and Computer Science. Retrieved from [arXiv](https://arxiv.org/pdf/2204.13547).

Delhaye, V. (2015). *Le plus court chemin d’imposition des multinationales : application de l’algorithme de Dijkstra*. UCLouvain, Louvain School of Management. Retrieved from UCLouvain.


Livres "Introduction to Algorithms" de Cormen (chapitres sur les graphes). => https://ils.bib.uclouvain.be/unamur/documents/1471273

https://graphviz.org/docs/library/


Champagne, J. (2023). Langage C #22 - Graphes. YouTube. https://www.youtube.com/watch?v=T5MU8NDMMj4 
Champagne, J. (2024). Architecture - graphe. YouTube. https://www.youtube.com/watch?v=TwO8rCTFy1c

https://fr.wikipedia.org/wiki/Algorithme_de_Dijkstra
https://fr.wikipedia.org/wiki/Liste_d%27adjacence
https://fr.wikipedia.org/wiki/Matrice_d%27adjacence
https://fr.wikipedia.org/wiki/Liste_d%27adjacence
https://lacl.u-pec.fr/dima/complexite/cours4.pdf

# Spécification

> 2. Spécifiez le problème : explicitez les préconditions et postconditions formellement (en respectant les notations mathématiques vues au cours).

## environnement
```c
int V, E, src;
Graph* graph; // Représentation du graphe sous forme de liste d'adjacence
int dist[V]; // Tableau des distances
int pred[V]; // Tableau des prédécesseurs
```

Soit ( G = (V, E) ) un graphe où ( V ) est l'ensemble des sommets ((|V| = V₀)) et ( E \subseteq V \times V ) l'ensemble des arêtes pondérées par une fonction ( w : E \to \mathbb{R}^+ ).

## Précondition (formalisée mathématiquement)

<br>

$$
\begin{aligned}
\text{pré} \equiv & \\
    & V = V₀ > 0 \land E = E₀ \geq 0 \land \text{src} = \text{src₀} \land \\
    & \forall (u, v) \in E₀ : w(u, v) \geq 0
\end{aligned}
$$

V₀ est le nombre de sommets (V₀ > 0).  
E₀ est le nombre d'arêtes (E₀ ≥ 0).  
src₀ est le sommet source, src ∈ [0, V-1].  
Les poids des arêtes (w(u, v)) sont non négatifs (w(u, v) ≥ 0).  
Cette formulation se base uniquement sur les arêtes existantes dans E₀, ce qui correspond à l'utilisation d'une liste d'adjacence comme structure de données.  

> **Remarque** : Je choisis la liste d'adjacence car la matrice d'adjacence :
$$ V₀ > 0 \land \forall i,j : 0 \leq i,j < V₀ : \text{graph}[i][j] \geq 0$$

> nécessite $O(V₀^2)$ d’espace. Cela est dû au fait que `graph[i][j]` représente le poids de l’arête entre `i` et `j`, ou ∞ si l’arête est absente, ce qui permet un accès direct mais utilise beaucoup d'espace. En revanche, la liste d'adjacence :
$$V₀ > 0 \land \forall (u,v) \in E₀ : w(u,v) \geq 0$$

> utilise $O(V₀ + |E₀|)$ d’espace, ce qui est optimal pour les graphes creux (sparse) car seules les arêtes existantes sont stockées.

## Orientation du graphe

Dans mon implémentation, je travaille avec un graphe orienté, ce qui signifie que les arêtes ont une direction. Cela se reflète dans les préconditions et les structures de données utilisées. Voici comment cela se traduit mathématiquement :

Graphe orienté :  

$G = (V, E)$ où $E \subseteq V \times V$ et il se peut que $(v_1, v_2) \in E$ mais $(v_2, v_1) \notin E$. Cela signifie que l'arête $(v_1, v_2)$ existe, mais l'arête inverse $(v_2, v_1)$ n'existe pas nécessairement.

## Postcondition (formalisée mathématiquement)

<br>

$$
\text{post} \equiv \forall v \in V : \text{dist}[v] = 
\begin{cases} 
\min\left(\sum\limits_{(u,v) \in P} w(u,v)\right) & \text{si } P \text{ existe} \\
\infty & \text{sinon}
\end{cases}
$$


Si un chemin P existe de src à v, alors dist[v] contient la somme minimale des poids des arêtes de P.
Si aucun chemin n'existe, dist[v] = ∞.

+ Vérification dans le code
    - La distance initiale des sommets est définie comme ∞ (dist[i] = INT_MAX).
    - La distance est mise à jour uniquement si un chemin existe, via la condition :
```c
if (!sptSet[v] && dist[u] != INT_MAX && tmp->weight + dist[u] < dist[v]) {
    dist[v] = dist[u] + tmp->weight;
}
```
    - Les sommets inatteignables depuis la source ne sont jamais mis à jour, donc dist[v] reste ∞.




## Invariant de boucle (formalisé mathématiquement)

Pendant l'exécution de l'algorithme, après chaque itération k, l'invariant suivant est satisfait :

Invariant de validité :
∀ u ∈ Sₖ : dist[u] = true_dist(src, u)
où Sₖ est l'ensemble des sommets pour lesquels la distance minimale a été confirmée après k itérations.

Invariant sur les distances :
∀ v ∉ Sₖ : dist[v] ≥ true_dist(src, v)
Tous les sommets qui n'ont pas encore été traités ont des estimations de distance (dans dist[v]) supérieures ou égales à leur véritable distance.

Invariant de mise à jour :
∀ (u, v) ∈ E : dist[v] ≤ dist[u] + w(u, v)
Aucune distance estimée ne peut être inférieure à la somme des poids le long d'une arête adjacente.

Commentaires sur votre algorithme
Invariant respecté : Les trois propriétés mentionnées ci-dessus garantissent que votre algorithme converge correctement. Ces invariants sont maintenus grâce à l'exploration systématique des sommets adjacents et la mise à jour des distances via les conditions sur sptSet[v] et dist[v].

Convergence : À la fin de l'algorithme, Sₖ contient tous les sommets atteignables depuis src, et dist[v] est valide pour tous les sommets v.


Si vous avez besoin d'autres modifications ou d'aide supplémentaire, n'hésitez pas à demander !






----------------

> postcondition
post ≡ ∀v (0 ≤ v < V0) : dist[v] = min(∑_{(u,w) ∈ P} graph[u][w]) où P est un chemin de src0 à v

Pour chaque sommet ( v ), ( dist[v] ) contient la distance minimale depuis le sommet source ( src0 ) jusqu'à ( v ).

# Implémentation

> Implémentez l'algorithme en C. Vous êtes autorisés à vous aider des ressources que vous trouvez, mais l’implémentation doit être votre propre travail : vous devez vous l’approprier et en maîtriser tous les détails. Dans le rapport, vous donnerez le code (commenté) de votre implémentation, vous détaillerez les structures de données utilisées et expliquer pourquoi elles sont adaptées à l'algorithme choisi.

```c
#include "dijkstra.h"

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
```
V : Nombre total de sommets.  
E : Nombre total d'arêtes.  
src : Sommet source pour Dijkstra.  
graph : Représentation du graphe en liste d'adjacence.  
dist : Tableau des distances minimales.  
pred : Tableau des prédécesseurs des sommets.  
sptSet : Ensemble des sommets traités (Shortest Path Tree Set).  
NodeList : Liste des voisins d'un sommet.  


## 4. En vos propres mots, expliquez comment fonctionne l'algorithme. Décrivez de manière intuitive pourquoi l’implémentation produit un résultat correct par rapport à vos spécifications.

## 5. Identifiez un invariant de boucle pertinent pour l'algorithme. Formulez cet invariant et démontrez, de manière formelle, qu'il est vérifié à chaque itération de la boucle concernée. Expliquez en quoi il permettrait, dans une preuve de programme plus complète, de faire le pont entre pré- et post- conditions.

## 6. Analysez la complexité temporelle et spatiale « pire des cas » de l'algorithme. Justifiez votre analyse en fonction des différentes étapes de l'algorithme et des structures de données utilisées.



+ Complexité temporelle et spatiale :

Analyse des performances dans différents contextes de graphe (dense, sparse).

Complexity analysis (O(V + E log V))

+ de temps
Soit n sommets et a arcs, on a :
O((a+n)log n)
<=> O(a+nlog n) *simplification pour l'implémentation avec un tas de Fibonacci ce qui améliore le temps asymptotique de l'algorithme de Dijkstra et de l'algorithme de Prim (calcul l'arbre couvrant de pods minimal d'un graphe).

A vérifier !
Complexité : En 𝑂(𝑉²) avec une matrice d’adjacence, optimisée en 𝑂(𝐸log𝑉) avec un tas min et une liste d’adjacence.

+ Comparaison en termes de complexité
++ Temps d’exécution :
A* et Dijkstra : O(E+VlogV) pour les graphes avec files de priorité.
Bellman-Ford : O(V×E), ce qui est plus lourd en termes de traitement pour de grands graphes.
++ Capacité de traitement :
A* et Dijkstra nécessitent que tous les poids soient positifs.
Bellman-Ford accepte des poids négatifs, mais au prix d'une complexité temporelle accrue.

## 7. Proposez une version récursive de l'algorithme (ou d'une partie de celui-ci, si cela est pertinent). Formulez une hypothèse d’induction qui servira à démontrer la correction de l'algorithme sur la base des appels récursifs. Seule l’hypothèse d’induction, et son impact sur la correction de l’implémentation récursive, doit être formulée formellement ; les autres calculs peuvent être considérés corrects.

## 8. Enfin, en fonction de l’algorithme que vous aurez choisi, ajoutez des informations qui vous semblent pertinentes ou sur des aspects caractéristiques à cet algorithme qui sont précisés dans la description de l’algorithme (voir section 2 ci-dessous).







